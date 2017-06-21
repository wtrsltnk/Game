// WtrWorld.cpp: implementation of the CWtrWorld class.
//
//////////////////////////////////////////////////////////////////////

#include "WtrWorld.h"
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

//////////////////////////////////////////////////////////////////////
// Statics
//////////////////////////////////////////////////////////////////////
CWtrWorld* CWtrWorld::m_pInstance = 0;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWtrWorld::CWtrWorld()
{
	m_pChildFrames = NULL;
	m_pBspWorld = NULL;
}

CWtrWorld::~CWtrWorld()
{
	if (m_pChildFrames)
	{
		CWtrFrame* pFrm = m_pChildFrames;

		while (pFrm)
		{
			CWtrFrame* tmp = pFrm;
			pFrm = pFrm->GetNext();
			delete tmp;
		}
	}
}

CWtrWorld* CWtrWorld::GetInstance()
{
	if (m_pInstance == NULL)
		m_pInstance = new CWtrWorld();

	return m_pInstance;
}

CWtrWorld* CWtrWorld::InitWorld(const char* strBspFile)
{
	if (m_pInstance)
		delete m_pInstance;

	m_pInstance = new CWtrWorld();

	// Init code here
	m_pInstance->m_pBspWorld = GetNewBsp(strBspFile);
	if (m_pInstance->m_pBspWorld)
		m_pInstance->m_pBspWorld->LoadBsp(strBspFile);

	return m_pInstance;
}

CWtrBaseBsp* CWtrWorld::GetNewBsp(const char* strBspFile)
{
	if (!strBspFile)
		return NULL;

	FILE* file;
	CWtrBaseBsp* pBsp;
	if ( (file = fopen(strBspFile, "rb")) == 0)
		return NULL;

	unsigned char inv[8];
	fread(inv, sizeof(inv), 1, file);

	tBSPHeader* qhdr = (tBSPHeader*)inv;
	hlBSPHeader_t* hlhdr = (hlBSPHeader_t*)inv;

	if (strncmp(qhdr->strID, "IBSP", 4) == 0)
		pBsp = new CWtrQBsp();
	else if (hlhdr->version == BSPVERSION)
		pBsp = new CWtrHLBsp();
	else
		pBsp = NULL;

	fclose(file);

	return pBsp;
}

void CWtrWorld::Render()
{
	glPushMatrix();
	{
		//glPolygonMode(GL_FRONT_AND_BACK , GL_LINE);
		if (m_pBspWorld)
			m_pBspWorld->Render();

		CWtrFrame* pFrame = m_pChildFrames;
		while (pFrame)
		{
			pFrame->Render();
			pFrame = pFrame->GetNext();
		}
	}
	glPopMatrix();
}

void CWtrWorld::AddFrame(CWtrFrame* pFrame)
{
	if (!pFrame)
		return;

	if (m_pChildFrames)
		pFrame->SetNext(m_pChildFrames);
	m_pChildFrames = pFrame;
}
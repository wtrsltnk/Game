// WtrFrame.cpp: implementation of the CWtrFrame class.
//
//////////////////////////////////////////////////////////////////////

#include "wtrframe.h"
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWtrFrame::CWtrFrame(void)
{
	m_pNext = 0;
	m_pParent = 0;
	m_pChildFrames = 0;
	m_pChildObjects = 0;

	m_Position.Fill(0.0f, 0.0f, 0.0f);

	m_fPitch = 0.0f;
	m_fRoll = 0.0f;
	m_fYaw = 0.0f;

	m_fXVelocity = 0.0f;
	m_fYVelocity = 0.0f;
	m_fZVelocity = 0.0f;

	m_fFrameInterval = 0.0f;
}

CWtrFrame::~CWtrFrame(void)
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

	if (m_pChildObjects)
	{
		CWtrObject* pObj = m_pChildObjects;

		while (pObj)
		{
			CWtrObject* tmp = pObj;

			pObj = pObj->GetNext();
			delete tmp;
		}
	}
}

void CWtrFrame::SetParent(CWtrFrame* pParent)
{
	m_pParent = pParent;
}

CWtrFrame* CWtrFrame::GetParent()
{
	return m_pParent;
}

void CWtrFrame::SetNext(CWtrFrame* pNext)
{
	m_pNext = pNext;
}

CWtrFrame* CWtrFrame::GetNext()
{
	return m_pNext;
}

void CWtrFrame::AddFrame(CWtrFrame* pFrame)
{
	if (!pFrame)
		return;

	pFrame->SetParent(this);

	if (m_pChildFrames)
		pFrame->SetNext(m_pChildFrames);
	m_pChildFrames = pFrame;
}

void CWtrFrame::AddObject(CWtrObject* pObject)
{
	if (!pObject)
		return;

	pObject->SetParent(this);

	if (m_pChildObjects)
		pObject->SetNext(m_pChildObjects);
	m_pChildObjects = pObject;
}

void CWtrFrame::Update()
{
	CalculateFrameInterval();
	m_Position.X += m_fXVelocity * m_fFrameInterval;
	m_Position.Y += m_fYVelocity * m_fFrameInterval;
	m_Position.Z += m_fZVelocity * m_fFrameInterval;
}

void CWtrFrame::Render()
{
	Update();
	glPushMatrix();
	{
		glRotatef(m_fPitch, 1, 0, 0);
		glRotatef(m_fRoll, 0, 1, 0);
		glRotatef(m_fYaw, 0, 0, 1);
		glTranslatef(m_Position.X, m_Position.Y, m_Position.Z);

		CWtrFrame* pFrame = m_pChildFrames;
		while (pFrame)
		{
			pFrame->Render();
			pFrame = pFrame->GetNext();
		}

		CWtrObject* pObject = m_pChildObjects;
		while (pObject)
		{
			pObject->Render();
			pObject = pObject->GetNext();
		}
	}
	glPopMatrix();
}

void CWtrFrame::CalculateFrameInterval()
{
	static float frameTime = 0;
    float currentTime;

	currentTime = (float)timeGetTime() / 100;	

 	m_fFrameInterval = currentTime - frameTime;

	frameTime = currentTime;
}

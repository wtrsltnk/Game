// WtrWorld.cpp: implementation of the CWtrWorld class.
//
//////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "WtrQBsp.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWtrQBsp::CWtrQBsp()
{
	m_numOfVerts    = 0;	
	m_numOfFaces    = 0;	
	m_numOfTextures = 0;

	m_pVerts = NULL;
	m_pFaces = NULL;
}

CWtrQBsp::~CWtrQBsp()
{
	FreeBsp();
}

bool CWtrQBsp::LoadBsp(const char* strBspFile)
{
	FILE *fp = NULL;
	int i = 0;

	if((fp = fopen(strBspFile, "rb")) == NULL)
	{
		MessageBox(NULL, "Could not find BSP file!", "Error", MB_OK);
		return false;
	}

	tBSPHeader header = {0};
	tBSPLump lumps[kMaxLumps] = {0};

	fread(&header, 1, sizeof(tBSPHeader), fp);
	fread(&lumps, kMaxLumps, sizeof(tBSPLump), fp);

	m_numOfVerts = lumps[kVertices].length / sizeof(tBSPVertex);
	m_pVerts     = new tBSPVertex [m_numOfVerts];

	m_numOfFaces = lumps[kFaces].length / sizeof(tBSPFace);
	m_pFaces     = new tBSPFace [m_numOfFaces];

	m_numOfTextures = lumps[kTextures].length / sizeof(tBSPTexture);
	tBSPTexture *pTextures = new tBSPTexture [m_numOfTextures];

	fseek(fp, lumps[kVertices].offset, SEEK_SET);


	for(i = 0; i < m_numOfVerts; i++)
	{
		fread(&m_pVerts[i], 1, sizeof(tBSPVertex), fp);
		
		float temp = m_pVerts[i].vPosition.y;
		m_pVerts[i].vPosition.y = m_pVerts[i].vPosition.z;
		m_pVerts[i].vPosition.z = -temp;

		m_pVerts[i].vTextureCoord.y *= -1;
	}	

	fseek(fp, lumps[kFaces].offset, SEEK_SET);

	fread(m_pFaces, m_numOfFaces, sizeof(tBSPFace), fp);

	fseek(fp, lumps[kTextures].offset, SEEK_SET);
	
	fread(pTextures, m_numOfTextures, sizeof(tBSPTexture), fp);

/*
	for(i = 0; i < m_numOfTextures; i++)
	{
		FindTextureExtension(pTextures[i].strName);
		
		CreateTexture(m_textures[i], pTextures[i].strName);
	}
	
	delete [] pTextures;
*/
	fclose(fp);

	m_FacesDrawn.Resize(m_numOfFaces);

	return true;
}

void CWtrQBsp::Render()
{
	glVertexPointer(3, GL_FLOAT, sizeof(tBSPVertex), &(m_pVerts[0].vPosition));
	glTexCoordPointer(2, GL_FLOAT, sizeof(tBSPVertex), &(m_pVerts[0].vTextureCoord));

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	int i = m_numOfFaces;

	m_FacesDrawn.ClearAll();

	while(i--)
	{
		if(m_pFaces[i].type != FACE_POLYGON) continue;

		if(!m_FacesDrawn.On(i)) 
		{
			m_FacesDrawn.Set(i);
			RenderFace(i);
		}
	}
}

void CWtrQBsp::RenderFace(int index)
{
	tBSPFace *pFace = &m_pFaces[index];
/*			
	if(g_bTextures)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,  m_textures[pFace->textureID]);
	}
*/
	glDrawArrays(GL_TRIANGLE_FAN, pFace->startVertIndex, pFace->numOfVerts);
}

void CWtrQBsp::FreeBsp()
{
	if(m_pVerts) 
	{
		delete [] m_pVerts;
		m_pVerts = NULL;
	}

	if(m_pFaces)	
	{
		delete [] m_pFaces;
		m_pFaces = NULL;
	}
}
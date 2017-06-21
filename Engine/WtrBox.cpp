// WtrCamera.cpp: implementation of the CWtrCamera class.
//
//////////////////////////////////////////////////////////////////////

#include "WtrBox.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWtrBox::CWtrBox(void)
{
	m_pMaterial = NULL;
	SetBoundaries(1.0f, 1.0f, 1.0f);
}

CWtrBox::CWtrBox(float width, float height, float depth)
{
	SetBoundaries(width, height, depth);
}

CWtrBox::CWtrBox(float width, float height, float depth, CWtrMaterial* pMaterial)
{
	SetBoundaries(width, height, depth);
	m_pMaterial = pMaterial;
}

CWtrBox::~CWtrBox(void)
{
}

void CWtrBox::Render()
{
	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		m_pMaterial->Use();
		glBegin(GL_QUADS);
		{
			glNormal3f( 0.0f, 0.0f, 1.0f);					// Normal Pointing Towards Viewer
			glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.0f,  0.0f,  m_fDepth);			// Point 1 (Front)
			glTexCoord2f(1.0f, 0.0f); glVertex3f( m_fWidth,  0.0f,  m_fDepth);		// Point 2 (Front)
			glTexCoord2f(1.0f, 1.0f); glVertex3f( m_fWidth,  m_fHeight,  m_fDepth);	// Point 3 (Front)
			glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.0f,  m_fHeight,  m_fDepth);		// Point 4 (Front)
			// Back Face
			glNormal3f( 0.0f, 0.0f,-1.0f);					// Normal Pointing Away From Viewer
			glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.0f,  0.0f,  0.0f);				// Point 1 (Back)
			glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.0f,  m_fHeight,  0.0f);			// Point 2 (Back)
			glTexCoord2f(0.0f, 1.0f); glVertex3f( m_fWidth,  m_fHeight,  0.0f);		// Point 3 (Back)
			glTexCoord2f(0.0f, 0.0f); glVertex3f( m_fWidth,  0.0f,  0.0f);			// Point 4 (Back)
			// Top Face
			glNormal3f( 0.0f, 1.0f, 0.0f);					// Normal Pointing Up
			glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.0f,  m_fHeight,  0.0f);			// Point 1 (Top)
			glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.0f,  m_fHeight,  m_fDepth);		// Point 2 (Top)
			glTexCoord2f(1.0f, 0.0f); glVertex3f( m_fWidth,  m_fHeight,  m_fDepth);	// Point 3 (Top)
			glTexCoord2f(1.0f, 1.0f); glVertex3f( m_fWidth,  m_fHeight,  0.0f);		// Point 4 (Top)
			// Bottom Face
			glNormal3f( 0.0f,-1.0f, 0.0f);					// Normal Pointing Down
			glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.0f,  0.0f,  0.0f);				// Point 1 (Bottom)
			glTexCoord2f(1.0f, 0.0f); glVertex3f( m_fWidth,  0.0f,  0.0f);			// Point 2 (Bottom)
			glTexCoord2f(1.0f, 1.0f); glVertex3f( m_fWidth,  0.0f,  m_fDepth);		// Point 3 (Bottom)
			glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.0f,  0.0f,  m_fDepth);			// Point 4 (Bottom)
			// Right face
			glNormal3f( 1.0f, 0.0f, 0.0f);					// Normal Pointing Right
			glTexCoord2f(1.0f, 0.0f); glVertex3f( m_fWidth,  0.0f,  0.0f);			// Point 1 (Right)
			glTexCoord2f(1.0f, 1.0f); glVertex3f( m_fWidth,  m_fHeight,  0.0f);		// Point 2 (Right)
			glTexCoord2f(0.0f, 1.0f); glVertex3f( m_fWidth,  m_fHeight,  m_fDepth);	// Point 3 (Right)
			glTexCoord2f(0.0f, 0.0f); glVertex3f( m_fWidth,  0.0f,  m_fDepth);		// Point 4 (Right)
			// Left Face
			glNormal3f(-1.0f, 0.0f, 0.0f);					// Normal Pointing Left
			glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.0f,  0.0f,  0.0f);				// Point 1 (Left)
			glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.0f,  0.0f,  m_fDepth);			// Point 2 (Left)
			glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.0f,  m_fHeight,  m_fDepth);		// Point 3 (Left)
			glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.0f,  m_fHeight,  0.0f);			// Point 4 (Left)
		}
		glEnd();
	}
	glPopMatrix();
}

void CWtrBox::SetBoundaries(float width, float height, float depth)
{
	m_fWidth = width;
	m_fHeight = height;
	m_fDepth = depth;
}

void CWtrBox::SetMaterial(CWtrMaterial* pMaterial)
{
	m_pMaterial= pMaterial;
}
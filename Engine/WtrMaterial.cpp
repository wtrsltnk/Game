// WtrFrame.cpp: implementation of the CWtrFrame class.
//
//////////////////////////////////////////////////////////////////////

#include "WtrMaterial.h"
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWtrMaterial::CWtrMaterial(void)
{
	for (int i = 0; i < 4; i++)
	{
		m_fAmbient[i] = 0.0f;
		m_fDiffuse[i] = 0.0f;
		m_fSpecular[i] = 0.0f;
		m_fEmission[i] = 0.0f;
	}

	m_fShininess = 0.0f;
	memset(m_strTexture, 0, sizeof(m_strTexture));
	m_iTexture = 0;
}

CWtrMaterial::~CWtrMaterial(void)
{
}

void CWtrMaterial::Use()
{
	if (m_iTexture != 0)
		glBindTexture(GL_TEXTURE_2D, m_iTexture);

	glMaterialfv(GL_FRONT, GL_AMBIENT, m_fAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_fDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, m_fSpecular);
	glMaterialfv(GL_FRONT, GL_EMISSION, m_fEmission);

	glMaterialf(GL_FRONT, GL_SHININESS, m_fShininess);
}

void CWtrMaterial::SetTexture(char* texture)
{
	strcpy(m_strTexture, texture);
	m_iTexture = CWtrTextureManager::GetInstance()->AddTexture(m_strTexture);
}

void CWtrMaterial::SetColor(int type, float r, float g, float b, float w)
{
	switch (type)
	{
	case Ambient:
		{
			m_fAmbient[0] = r;
			m_fAmbient[1] = g;
			m_fAmbient[2] = b;
			m_fAmbient[3] = w;
			break;
		}
		
	case Diffuse:
		{
			m_fDiffuse[0] = r;
			m_fDiffuse[1] = g;
			m_fDiffuse[2] = b;
			m_fDiffuse[3] = w;
			break;
		}
		
	case Specular:
		{
			m_fSpecular[0] = r;
			m_fSpecular[1] = g;
			m_fSpecular[2] = b;
			m_fSpecular[3] = w;
			break;
		}

	case Emission:
		{
			m_fEmission[0] = r;
			m_fEmission[1] = g;
			m_fEmission[2] = b;
			m_fEmission[3] = w;
			break;
		}
	}
}

void CWtrMaterial::SetShininess(float shininess)
{
	m_fShininess = shininess;
}
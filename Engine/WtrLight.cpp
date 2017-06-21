// WtrWorld.cpp: implementation of the CWtrWorld class.
//
//////////////////////////////////////////////////////////////////////

#include "Wtrlight.h"
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

//////////////////////////////////////////////////////////////////////
// Statics
//////////////////////////////////////////////////////////////////////
int CWtrLight::m_iNumLights = 0;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWtrLight::CWtrLight(void)
{
	m_iLightID = GL_LIGHT1 + m_iNumLights++;
}

CWtrLight::~CWtrLight(void)
{
}

void CWtrLight::Render()
{
	// Initializeer de volgende onderdelen:

	glEnable(m_iLightID);
	// Ambient
	glLightfv(m_iLightID, GL_AMBIENT, m_fAmbient);
	// Diffuse
	glLightfv(m_iLightID, GL_DIFFUSE, m_fDiffuse);
	// Specular
	glLightfv(m_iLightID, GL_SPECULAR, m_fSpecular);
	// Position
	glLightfv(m_iLightID, GL_POSITION, m_fPosition);
}

void CWtrLight::SetColor(int type, float r, float g, float b, float w)
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
	}
}

void CWtrLight::SetPosition(float x, float y, float z, float w)
{
	m_fPosition[0] = x;
	m_fPosition[1] = y;
	m_fPosition[2] = z;
	m_fPosition[3] = w;
}
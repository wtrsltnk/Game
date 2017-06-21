// WtrLight.h: interface for the CWtrLight class.
//
//////////////////////////////////////////////////////////////////////

#ifndef WTRLIGHT
#define WTRLIGHT

#include "WtrObject.h"

class __declspec(dllexport) CWtrLight : public CWtrObject
{
private:
	static int m_iNumLights;
	int m_iLightID;

	float m_fAmbient[4];
	float m_fDiffuse[4];
	float m_fSpecular[4];
	float m_fPosition[4];
public:
	CWtrLight(void);
	~CWtrLight(void);

	enum
	{
		Ambient = 0,
		Diffuse,
		Specular,
	};

	void Render();
	
	void SetColor(int type, float r, float g, float b, float w);
	void SetPosition(float x, float y, float z, float w);
};

#endif
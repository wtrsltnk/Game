// WtrMaterial.h: interface for the CWtrMaterial class.
//
//////////////////////////////////////////////////////////////////////

#ifndef WTRMATERIAL
#define WTRMATERIAL

#include "WtrTextureManager.h"

class __declspec(dllexport) CWtrMaterial
{
private:
	float m_fAmbient[4];
	float m_fDiffuse[4];
	float m_fSpecular[4];
	float m_fEmission[4];
	float m_fShininess;

	char m_strTexture[MAX_PATH];
	int m_iTexture;
public:
	CWtrMaterial(void);
	virtual ~CWtrMaterial(void);

	enum
	{
		Ambient = 0,
		Diffuse,
		Specular,
		Emission
	};

	void Use();
	
	void SetTexture(char* texture);
	void SetColor(int type, float r, float g, float b, float w);
	void SetShininess(float shininess);
};

#endif
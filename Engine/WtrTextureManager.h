// WtrTextureManager.h: interface for the CWtrTextureManager class.
//
//////////////////////////////////////////////////////////////////////

#ifndef WTRTEXTUREMANAGER
#define WTRTEXTUREMANAGER

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>
#include <stdio.h>

#define MAX_TEX 32

class CWtrTextureManager
{
private:
	static CWtrTextureManager* m_pInstance;

	GLuint m_uiTextures[MAX_TEX];
	unsigned int m_uiNumTextures;
public:
	CWtrTextureManager(void);
	virtual ~CWtrTextureManager(void);
	
	static CWtrTextureManager* GetInstance();

    int AddTexture(const char* filename);
};

#endif

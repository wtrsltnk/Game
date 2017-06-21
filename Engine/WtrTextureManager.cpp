// WtrWorld.cpp: implementation of the CWtrWorld class.
//
//////////////////////////////////////////////////////////////////////

#include "WtrTextureManager.h"
#include "stb_image.h"

//////////////////////////////////////////////////////////////////////
// Statics
//////////////////////////////////////////////////////////////////////
CWtrTextureManager* CWtrTextureManager::m_pInstance = 0;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWtrTextureManager::CWtrTextureManager(void)
{
	m_uiNumTextures = 0;
	glGenTextures(MAX_TEX, &m_uiTextures[0]);
}

CWtrTextureManager::~CWtrTextureManager(void)
{
}

CWtrTextureManager* CWtrTextureManager::GetInstance()
{
	if (!m_pInstance)
		m_pInstance = new CWtrTextureManager();

	return m_pInstance;
}

int CWtrTextureManager::AddTexture(const char* filename)
{
	if (m_uiNumTextures > MAX_TEX)
		return -1;

    int x,y,n;
    unsigned char *data = stbi_load(filename, &x, &y, &n, 0);
    if (data != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, m_uiTextures[m_uiNumTextures++]);
        glTexImage2D(GL_TEXTURE_2D, 0, n, x, y, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

        stbi_image_free(data);
	}
	return m_uiTextures[m_uiNumTextures-1];
}

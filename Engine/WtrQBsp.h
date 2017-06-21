// WtrWorld.h: interface for the CWtrWorld class.
//
//////////////////////////////////////////////////////////////////////

#ifndef WTRQBSP
#define WTRQBSP

#include "WtrBaseBsp.h"
#include "QBspfile.h"
#include <stdio.h>

class CWtrQBsp : public CWtrBaseBsp
{
private:
	int  m_numOfVerts;				// The number of verts in the model
	int  m_numOfFaces;				// The number of faces in the model
	int  m_numOfTextures;			// The number of texture maps

	tBSPVertex  *m_pVerts;			// The object's vertices
	tBSPFace *m_pFaces;				// The faces information of the object
	UINT m_textures[MAX_TEXTURES];	// The texture and lightmap array for the level

	CBitset m_FacesDrawn;

	void RenderFace(int index);
public:
	CWtrQBsp();
	virtual ~CWtrQBsp();

	bool LoadBsp(const char* strBspFile);
	void FreeBsp();

	void Render();
};

#endif
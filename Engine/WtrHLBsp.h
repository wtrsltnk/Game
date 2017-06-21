// WtrWorld.h: interface for the CWtrWorld class.
//
//////////////////////////////////////////////////////////////////////

#ifndef WTRHLBSP
#define WTRHLBSP

#include "WtrBaseBsp.h"
#include "HLBspFile.h"
#include <stdio.h>

class CWtrHLBsp : public CWtrBaseBsp
{
private:
	int  m_numOfVerts;				// The number of verts in the model
	int  m_numOfEdges;				// The number of edges in the model
	int  m_numOfFaces;				// The number of faces in the model
	int m_numOfSurfedges;			// The number of surfedges in the model

	hlBSPVertex_t  *m_pVerts;		// The object's vertices
	hlBSPEdge_t *m_pEdges;			// The object's edges
	hlBSPFace_t *m_pFaces;			// The faces information of the object
	int *m_pSurfEdges;				// The surfedges information

	CBitset m_FacesDrawn;
	
	void RenderFace(int index);
	void RenderEdge(int index);
	void InitBsp();
public:
	CWtrHLBsp();
	virtual ~CWtrHLBsp();

	bool LoadBsp(const char* strBspFile);
	void FreeBsp();

	void Render();
};

#endif
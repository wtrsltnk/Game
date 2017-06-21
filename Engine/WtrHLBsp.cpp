// WtrWorld.cpp: implementation of the CWtrWorld class.
//
//////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "WtrHLBsp.h"

int rendertype = GL_POLYGON;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWtrHLBsp::CWtrHLBsp()
{
	m_numOfVerts    = 0;
	m_numOfEdges	= 0;
	m_numOfFaces    = 0;
	m_numOfSurfedges = 0;

	m_pVerts = NULL;
	m_pEdges = NULL;
	m_pFaces = NULL;
	m_pSurfEdges = NULL;
}

CWtrHLBsp::~CWtrHLBsp()
{
	FreeBsp();
}

int    LittleLong (int l)
{
        return l;
}

bool CWtrHLBsp::LoadBsp(const char* strBspFile)
{
	FILE *fp = NULL;
	int i = 0;

	if((fp = fopen(strBspFile, "rb")) == NULL)
	{
		MessageBox(NULL, "Could not find BSP file!", "Error", MB_OK);
		return false;
	}

	hlBSPHeader_t header = {0};
	hlBSPLump_t lumps[hlMaxLumps] = {0};

	fread(&header, 1, sizeof(hlBSPHeader_t), fp);
	fread(&lumps, hlMaxLumps, sizeof(hlBSPLump_t), fp);

	m_numOfVerts = lumps[hlVertexes].length / sizeof(hlBSPVertex_t);
	m_pVerts     = new hlBSPVertex_t [m_numOfVerts];

	m_numOfEdges = lumps[hlEdges].length / sizeof(hlBSPEdge_t);
	m_pEdges     = new hlBSPEdge_t [m_numOfEdges];

	m_numOfFaces = lumps[hlFaces].length / sizeof(hlBSPFace_t);
	m_pFaces     = new hlBSPFace_t [m_numOfFaces];

	m_numOfSurfedges = lumps[hlSurfEdges].length / sizeof(int);
	m_pSurfEdges     = new int [m_numOfFaces];

	fseek(fp, lumps[hlVertexes].offset, SEEK_SET);
	fread(m_pVerts, m_numOfVerts, sizeof(hlBSPVertex_t), fp);

	fseek(fp, lumps[hlEdges].offset, SEEK_SET);
	fread(m_pEdges, m_numOfEdges, sizeof(hlBSPEdge_t), fp);

	fseek(fp, lumps[hlFaces].offset, SEEK_SET);
	fread(m_pFaces, m_numOfFaces, sizeof(hlBSPFace_t), fp);

	fseek(fp, lumps[hlSurfEdges].offset, SEEK_SET);
	fread(m_pSurfEdges, m_numOfSurfedges, sizeof(m_pSurfEdges[0]), fp);

	fclose(fp);

	m_FacesDrawn.Resize(m_numOfFaces);

	return true;
}

void CWtrHLBsp::InitBsp()
{
}

void CWtrHLBsp::Render()
{
	int i = this->m_numOfFaces;

	::glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	while (i--)
	{
		RenderFace(i);
	}

	rendertype = GL_LINES;

	::glDisable(GL_LIGHTING);
	::glColor3f(1.0f, 0.0f, 0.0f);
	::glEnable(GL_CULL_FACE);
	i = this->m_numOfFaces;
	while (i--)
	{
		RenderFace(i);
	}
	rendertype = GL_POLYGON;
}

void CWtrHLBsp::RenderFace(int index)
{
	if (index < this->m_numOfFaces && index > 0)
	{
		int start = this->m_pFaces[index].firstedge;
		int num = this->m_pFaces[index].numedges;

		::glBegin(rendertype);
		for (int i = start; i < (start + num); i++)
		{
			RenderEdge(i);
		}
		::glEnd();
	}
}

void CWtrHLBsp::RenderEdge(int index)
{
	if (index < this->m_numOfEdges && index > 0)
	{
		int v1 = this->m_pEdges[index].v[0];
		int v2 = this->m_pEdges[index].v[1];

		hlBSPVertex_t vert1 = this->m_pVerts[v1];
		hlBSPVertex_t vert2 = this->m_pVerts[v2];

		::glVertex3fv(vert1.point);
		//::glVertex3fv(vert2.point);
	}
}

void CWtrHLBsp::FreeBsp()
{
	m_numOfVerts = 0;
	if (m_pVerts)
		delete m_pVerts;

	m_numOfEdges = 0;
	if (m_pEdges)
		delete m_pEdges;

	m_numOfFaces = 0;
	if (m_pFaces)
		delete m_pFaces;

	m_numOfSurfedges = 0;
	if (m_pSurfEdges)
		delete m_pSurfEdges;
}
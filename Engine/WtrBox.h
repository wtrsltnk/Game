// WtrBox.h: interface for the CWtrBox class.
//
//////////////////////////////////////////////////////////////////////

#ifndef WTRBOX
#define WTRBOX

#include "WtrObject.h"
#include "WtrMaterial.h"

class __declspec(dllexport) CWtrBox : public CWtrObject
{
private:
	float m_fWidth, m_fHeight, m_fDepth;

	CWtrMaterial* m_pMaterial;
public:
	CWtrBox(void);
	CWtrBox(float width, float height, float depth);
	CWtrBox(float width, float height, float depth, CWtrMaterial* pMaterial);
	virtual ~CWtrBox(void);

	void Render();

	void SetBoundaries(float width, float height, float depth);
	void SetMaterial(CWtrMaterial* pMaterial);
};
#endif
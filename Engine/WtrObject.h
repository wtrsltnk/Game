// WtrObject.h: interface for the CWtrObject class.
//
//////////////////////////////////////////////////////////////////////

#ifndef WTROBJECT
#define WTROBJECT

#include "wiskunde.h"
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

class CWtrFrame;
class __declspec(dllexport) CWtrObject
{
private:
	CWtrObject* m_pNext;
	CWtrFrame* m_pParent;
public:
	CWtrObject(void);
	virtual ~CWtrObject(void);

	virtual void Render();

	void SetNext(CWtrObject* pNext);
	CWtrObject* GetNext();
	void SetParent(CWtrFrame* pParent);
	CWtrFrame* GetParent();
};

#endif
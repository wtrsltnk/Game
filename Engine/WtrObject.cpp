// WtrObject.cpp: implementation of the CWtrObject class.
//
//////////////////////////////////////////////////////////////////////

#include "WtrObject.h"
#include "WtrFrame.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWtrObject::CWtrObject(void)
{
	m_pNext = 0;
	m_pParent = 0;
}

CWtrObject::~CWtrObject(void)
{
}

void CWtrObject::Render()
{
}

void CWtrObject::SetNext(CWtrObject* pNext)
{
	m_pNext = pNext;
}

CWtrObject* CWtrObject::GetNext()
{
	return m_pNext;
}

void CWtrObject::SetParent(CWtrFrame* pParent)
{
	m_pParent = pParent;
}

CWtrFrame* CWtrObject::GetParent()
{
	return m_pParent;
}

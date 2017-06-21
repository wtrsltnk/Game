// WtrWorld.cpp: implementation of the CWtrWorld class.
//
//////////////////////////////////////////////////////////////////////

#include "WtrEntry.h"
#include <string.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWtrEntry::CWtrEntry(void)
{
	for (int i = 0; i < MAX_CHARS_IN_LINE; i++)
		m_strLine[i] = 0;

	m_pNext = 0;
	m_iLength = 0;
}

CWtrEntry::~CWtrEntry(void)
{
}

void CWtrEntry::SetNext(CWtrEntry* pEntry)
{
	m_pNext = pEntry;
}

CWtrEntry* CWtrEntry::GetNext()
{
	return m_pNext;
}

void CWtrEntry::KeyStroke(char key)
{
	if (key == '\b')
	{
		if (m_iLength <= 0)
			return;

		m_iLength--;

		m_strLine[m_iLength] = '\0';
	}
	else
	{
		if (m_iLength >= MAX_CHARS_IN_LINE-1)
			return;

		m_strLine[m_iLength] = key;

		m_iLength++;
	}
}

const char* CWtrEntry::GetText() const
{
    return this->m_strLine;
}

void CWtrEntry::SetText(const char* text)
{
	strcpy(m_strLine, text);
}

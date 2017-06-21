// WtrWorld.cpp: implementation of the CWtrWorld class.
//
//////////////////////////////////////////////////////////////////////

#include "WtrConsole.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWtrConsole::CWtrConsole(void)
{
	m_pEngine = NULL;
	m_bShowconsole = false;

	m_pEntryList = new CWtrEntry();
}

CWtrConsole::~CWtrConsole(void)
{
}

void CWtrConsole::Render()
{
	if (!m_pEngine)
		return;

	RECT rc;
	static float trans = 0.0f;
	if (m_bShowconsole)
	{
		if (trans < 0.8f)
			trans += 0.1f;
	}
	else
	{
		if (trans > 0.0f)
			trans -= 0.1f;
		else
			return;
	}
	float color[4] = {1.0f, 1.0f, 1.0f, trans};

	m_pEngine->Goto2D();

	if (trans >= 0.8f)
	{
		char text[MAX_CHARS_IN_LINE];
		int drawposition = m_iHeight - 20;

		CWtrEntry* tmp = m_pEntryList;

		while (tmp)
        {
            m_pEngine->Draw2DText(10, drawposition, color, tmp->GetText());

			tmp = tmp->GetNext();
			drawposition -= 10;
		}
	}

	color[0] = 0.0f;
	color[1] = 0.2f;
	color[2] = 0.9f;
	rc.left = 0;
	rc.right = m_iWidth;
	rc.top = 0;
	rc.bottom = m_iHeight;
	m_pEngine->Draw2DRect(&rc, color);
	m_pEngine->Leave2D();
}

void CWtrConsole::Initialize(CWtrEngine* pEngine)
{
	m_pEngine = pEngine;

	Resize();
}

void CWtrConsole::Resize()
{
	RECT rc;
	m_pEngine->GetScreenrect(&rc);

	m_iHeight = rc.bottom / 2;
	m_iWidth = rc.right;
}

bool CWtrConsole::KeyStoke(char key)
{
	if (key == -64)
	{
		m_bShowconsole = !m_bShowconsole;
		return true;
	}

	if (!m_bShowconsole)
		return false;

	if (key == VK_RETURN)
	{
		CWtrEntry* tmp = new CWtrEntry();
		tmp->SetNext(m_pEntryList);
		m_pEntryList = tmp;
		return true;
	}

	m_pEntryList->KeyStroke(key);
	return m_bShowconsole;
}

bool CWtrConsole::AddLine(const char* text)
{
	m_pEntryList->SetText(text);
	CWtrEntry* tmp = new CWtrEntry();
	tmp->SetNext(m_pEntryList);
	m_pEntryList = tmp;

	return true;
}

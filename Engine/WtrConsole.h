// WtrConsole.h: interface for the CWtrConsole class.
//
//////////////////////////////////////////////////////////////////////

#ifndef WTRCONSOLE
#define WTRCONSOLE

#include <windows.h>
#include "WtrEngine.h"
#include "WtrEntry.h"

class __declspec(dllexport) CWtrConsole
{
private:
	CWtrEngine* m_pEngine;

	CWtrEntry* m_pEntryList;

	int m_iWidth, m_iHeight;
	bool m_bShowconsole;
public:
	CWtrConsole(void);
	virtual ~CWtrConsole(void);

	void Render();

	void Initialize(CWtrEngine* pEngine);
	void Resize();

	bool KeyStoke(char key);

    bool AddLine(const char* text);
};

#endif

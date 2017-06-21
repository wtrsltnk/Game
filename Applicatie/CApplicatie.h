#ifndef CAPPLICATIE_H
#define CAPPLICATIE_H

#include "CWin.h"
#include "WtrEngine.h"
#include "WtrWorld.h"
#include "WtrBox.h"
#include "WtrLight.h"
#include "WtrConsole.h"
#include "Keys.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class CApplicatie : public CWin
{
private:
	CWtrEngine* m_pEngine;
	CWtrConsole* m_pConsole;

	static BOOL CALLBACK DispModeProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void QueryDisplayMode();
public:
	CApplicatie();
	~CApplicatie();

	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
	void Render();
};

#endif

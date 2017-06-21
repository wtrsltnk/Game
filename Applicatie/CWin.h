#ifndef CWIN_H
#define CWIN_H

#include <windows.h>
#include "resource.h"

class CWin
{
protected:
	static HINSTANCE m_hInstance;
	HWND  m_hWnd;
	
	DWORD m_PosX;
	DWORD m_PosY;
	DWORD m_dwWindowStyle;
	DWORD m_dwExWindowStyle;
 	DWORD m_dwCreationFlags;
	DWORD m_dwCreationHeight;
	DWORD m_dwCreationWidth;
	TCHAR * m_strWindowTitle;
	HBRUSH m_hbrWindowColor;
	HICON  m_hIcon;
	HMENU  m_hMenu;
	HACCEL m_hAccelTable;
	BOOL m_bFullscreen;
	DEVMODE* m_pDevmode;


public:
	 CWin();
	 HRESULT Create();
	 int Run();
	 virtual ~CWin();
	 virtual LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);

	 virtual void Render() = 0;
};

#endif

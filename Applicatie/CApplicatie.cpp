#include "CApplicatie.h"
#include <tchar.h>
#include <stdio.h>

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
CApplicatie::CApplicatie()
{
	QueryDisplayMode();
	this->m_dwCreationFlags  = 0L;
	this->m_dwWindowStyle	 = WS_POPUPWINDOW;
	this->m_dwExWindowStyle	 = WS_EX_WINDOWEDGE;
	this->m_dwCreationFlags  = SW_SHOW;
	this->m_hbrWindowColor	 = (HBRUSH)(COLOR_WINDOW);
	this->m_hIcon			 = LoadIcon(m_hInstance, MAKEINTRESOURCE(IDI_ICON));
	this->m_strWindowTitle	 = _T("Wtr© Game Engine");
	this->m_hMenu			 = NULL;
	this->m_pEngine			 = NULL;
	this->m_pConsole		 = NULL;
}


CApplicatie::~CApplicatie()
{
}

/////////////////////////////////////
// Memberfuncties                  //
/////////////////////////////////////

LRESULT CApplicatie::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		{
			HFONT hFont = CreateFont(	12,						// logical height of font
										0,						// logical average character width
										0,						// angle of escapement
										0,						// base-line orientation angle
										FW_NORMAL,				// font weight
										FALSE,					// italic attribute flag
										FALSE,					// underline attribute flag
										FALSE,					// strikeout attribute flag
										ANSI_CHARSET,			// character set identifier
										OUT_DEFAULT_PRECIS,		// output precision
										CLIP_DEFAULT_PRECIS,	// clipping precision
										DEFAULT_QUALITY,		// output quality
										DEFAULT_PITCH,			// pitch and family
										"Verdana"				// pointer to typeface name string
										);



			m_pEngine = new CWtrEngine();
			if (m_pEngine->InitEngine(hWnd, m_pDevmode, m_bFullscreen==TRUE, hFont) == ERR)
				PostQuitMessage(0);

			m_pConsole = new CWtrConsole();
			m_pConsole->Initialize(m_pEngine);

			m_pConsole->AddLine("Engine initialized!!");

			CWtrFrame* pFrame = new CWtrFrame();

			CWtrWorld::InitWorld("data\\GamersDay2.bsp");

			CWtrMaterial* pMat = new CWtrMaterial();
			pMat->SetTexture("data\\test.bmp");
			pMat->SetColor(CWtrMaterial::Ambient, 0.5f, 0.5f, 0.5f, 1.0f);
			pMat->SetColor(CWtrMaterial::Diffuse, 0.5f, 0.5f, 0.5f, 1.0f);
			pMat->SetColor(CWtrMaterial::Specular, 0.3f, 0.3f, 0.3f, 1.0f);
			pMat->SetColor(CWtrMaterial::Emission, 0.0f, 0.0f, 0.0f, 0.0f);
			pMat->SetShininess(100.0f);
/*
			CWtrLight* pLight = new CWtrLight();
			pLight->SetColor(CWtrLight::Ambient, 0.0f, 0.6f, 1.0f, 1.0f);
			pLight->SetColor(CWtrLight::Diffuse, 0.2f, 0.2f, 0.2f, 1.0f);
			pLight->SetColor(CWtrLight::Specular, 0.0f, 0.0f, 0.0f, 1.0f);
			pLight->SetPosition(1.0f, 0.0f, 5.0f, 1.0f);
			pFrame->AddObject(pLight);
*/
			pFrame->AddObject(new CWtrBox(0.5f, 0.5f, 0.5f, pMat));
			CWtrWorld::GetInstance()->AddFrame(pFrame);

			m_pConsole->AddLine("World initialized!!");
			break;
		}

	case WM_SIZE:
		{
			m_pEngine->Resize(LOWORD(lParam), HIWORD(lParam));
			m_pConsole->Resize();
			break;
		}

	case WM_CLOSE:
		{
			m_pEngine->Shutdown();
			break;
		}

	case WM_LBUTTONDOWN:
			CKeys::GetInstance()->ButtonDown(Left); break;
	case WM_LBUTTONUP:
			CKeys::GetInstance()->ButtonUp(Left); break;
	case WM_RBUTTONDOWN:
			CKeys::GetInstance()->ButtonDown(Right); break;
	case WM_RBUTTONUP:
			CKeys::GetInstance()->ButtonUp(Right); break;
	case WM_MBUTTONDOWN:
			CKeys::GetInstance()->ButtonDown(Middle); break;
	case WM_MBUTTONUP:
			CKeys::GetInstance()->ButtonUp(Middle); break;
	case WM_KEYUP:
			CKeys::GetInstance()->KeyUp(wParam); break;
	case WM_KEYDOWN:
		{	
			if (wParam == VK_ESCAPE)
			{
				PostQuitMessage(0);
			}

			if (m_pConsole)
			{
				if (m_pConsole->KeyStoke(wParam) == true)
					break;
			}
			if (wParam == 'C')
			{
				m_pEngine->ToggleCaptureCursor();
			}
			CKeys::GetInstance()->KeyDown(wParam);
			break;
		}
	}
	return CWin::MsgProc(hWnd, uMsg, wParam, lParam);
}

BOOL CALLBACK CApplicatie::DispModeProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		{
			DEVMODE* dm = new DEVMODE;
			RECT rc, desk;
			char str[64];

			int i = 0;
			while (EnumDisplaySettings(NULL, i, dm))
			{
				sprintf(str, "%i x %i (%i bit) @ %i Hz", dm->dmPelsWidth, dm->dmPelsHeight, dm->dmBitsPerPel, dm->dmDisplayFrequency);
				int index = SendMessage(GetDlgItem(hDlg, IDC_DISPMODES), LB_ADDSTRING, 0, (LPARAM)(LPTSTR)str);
				SendMessage(GetDlgItem(hDlg, IDC_DISPMODES), LB_SETITEMDATA, index, i);
				i++;
			}
			
			GetWindowRect(GetDesktopWindow(), &desk);
			GetWindowRect(hDlg, &rc);

			int width = (rc.right-rc.left);
			int height = (rc.bottom-rc.top);
			int x = (desk.right/2)-(width/2);
			int y = (desk.bottom/2)-(height/2);

			MoveWindow(hDlg, x, y, width, height, true);

			break;
		}

	case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{
			case IDOK:
				{
					int i = SendMessage(GetDlgItem(hDlg, IDC_DISPMODES), LB_GETCURSEL, 0, 0);
					if (i == LB_ERR)
						EndDialog(hDlg, -1);
					int item = SendMessage(GetDlgItem(hDlg, IDC_DISPMODES), LB_GETITEMDATA, (WPARAM)i, 0);
					if (item != LB_ERR)
					{
						EndDialog(hDlg, item);
						break;
					}

					EndDialog(hDlg, -1);
					break;
				}

			case IDCANCEL:
				{
					EndDialog(hDlg, -1);
					break;
				}

			case IDC_DISPMODES:
				{
					switch (HIWORD(wParam))
					{
					case LBN_DBLCLK:
						{
							int i = SendMessage(GetDlgItem(hDlg, IDC_DISPMODES), LB_GETCURSEL, 0, 0);
							if (i == LB_ERR)
								EndDialog(hDlg, -1);
							int item = SendMessage(GetDlgItem(hDlg, IDC_DISPMODES), LB_GETITEMDATA, (WPARAM)i, 0);
							if (item != LB_ERR)
							{
								EndDialog(hDlg, item);
								break;
							}

							EndDialog(hDlg, -1);
							break;
						}
					}
					break;
				}
			}
			break;
		}
	}
	return FALSE;
}

void CApplicatie::QueryDisplayMode()
{
	m_pDevmode = new DEVMODE;

	int res = ::MessageBox(NULL, "Do you want to play in fullscreen?", "Fullscreen", MB_YESNO | MB_ICONQUESTION);

	if (res == IDYES)
	{
		int mode = DialogBox(m_hInstance, MAKEINTRESOURCE(IDD_DISPMODES), NULL, DispModeProc);
		EnumDisplaySettings(NULL, mode, m_pDevmode);
		m_bFullscreen = TRUE;
		this->m_PosX			 = 0;	
		this->m_PosY			 = 0;	
		this->m_dwCreationWidth  = m_pDevmode->dmPelsWidth;
		this->m_dwCreationHeight = m_pDevmode->dmPelsHeight;
	}
	else if (res == IDNO)
	{
		EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, m_pDevmode);
		m_bFullscreen = FALSE;
		this->m_PosX			 = (m_pDevmode->dmPelsWidth - SCREEN_WIDTH) / 2;	
		this->m_PosY			 = (m_pDevmode->dmPelsHeight - SCREEN_HEIGHT) / 2;	
		this->m_dwCreationWidth  = SCREEN_WIDTH;
		this->m_dwCreationHeight = SCREEN_HEIGHT;
	}
}

void CApplicatie::Render()
{
	float textcolor[4] = {1.0f, 1.0f, 1.0f, 1.0f};

	m_pEngine->PreRender();

	CWtrWorld::GetInstance()->Render();

	m_pEngine->Goto2D();
	m_pEngine->Draw2DText(20, 20, textcolor, m_pEngine->GetFPS());
	m_pEngine->Leave2D();

	m_pConsole->Render();

	m_pEngine->PostRender();
}

// WtrWorld.h: interface for the CWtrWorld class.
//
//////////////////////////////////////////////////////////////////////

#ifndef WTRWORLD
#define WTRWORLD

#include "WtrFrame.h"
#include "WtrQBsp.h"
#include "WtrHLBsp.h"

class __declspec(dllexport) CWtrWorld
{
private:
	static CWtrWorld* m_pInstance;

	CWtrFrame* m_pChildFrames;
	CWtrBaseBsp* m_pBspWorld;
public:
	CWtrWorld();
	virtual ~CWtrWorld();

	static CWtrWorld* GetInstance();
	static CWtrWorld* InitWorld(const char* strBspFile);
	static CWtrBaseBsp* GetNewBsp(const char* strBspFile);

	void Render();

	void AddFrame(CWtrFrame* pFrame);
};

#endif
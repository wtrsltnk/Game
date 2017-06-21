// WtrFrame.h: interface for the CWtrFrame class.
//
//////////////////////////////////////////////////////////////////////

#ifndef WTRFRAME
#define WTRFRAME

#include "WtrObject.h"
#include "wiskunde.h"

class __declspec(dllexport) CWtrFrame
{
private:
	Vector m_Position;

	float m_fPitch;
	float m_fRoll;
	float m_fYaw;

	float m_fXVelocity;
	float m_fYVelocity;
	float m_fZVelocity;
	
	float m_fFrameInterval;

	CWtrFrame* m_pNext;
	CWtrFrame* m_pParent;
	CWtrFrame* m_pChildFrames;
	CWtrObject* m_pChildObjects;

	void SetParent(CWtrFrame* pParent);
	CWtrFrame* GetParent();

	void CalculateFrameInterval();
public:
	CWtrFrame(void);
	virtual ~CWtrFrame(void);

	void Update();
	void Render();

	void SetNext(CWtrFrame* pNext);
	CWtrFrame* GetNext();
	void AddFrame(CWtrFrame* pFrame);
	void AddObject(CWtrObject* pObject);
};

#endif
#ifndef WTRBASEBSP
#define WTRBASEBSP

class CWtrBaseBsp
{
protected:
	CWtrBaseBsp(void);
	virtual ~CWtrBaseBsp(void);

public:
	virtual bool LoadBsp(const char* strBspFile) = 0;
	virtual void FreeBsp() = 0;

	virtual void Render() = 0;
};

#endif
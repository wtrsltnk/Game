// WtrEntry.h: interface for the CWtrEntry class.
//
//////////////////////////////////////////////////////////////////////

#ifndef WTRENTRY
#define WTRENTRY

#define MAX_CHARS_IN_LINE 64

class CWtrEntry
{
private:
	CWtrEntry* m_pNext;

	char m_strLine[MAX_CHARS_IN_LINE];
	int m_iLength;
public:
	CWtrEntry(void);
	virtual ~CWtrEntry(void);

	void SetNext(CWtrEntry* pEntry);
	CWtrEntry* GetNext();
	void KeyStroke(char key);

    const char* GetText() const;
    void SetText(const char* text);
};

#endif

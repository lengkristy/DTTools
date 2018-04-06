#pragma once

class CDTTools : public CSkinApplication
{
public:
	CDTTools();

public:
	virtual BOOL InitInstance();
	virtual void Run(const tstring& strCmdLine, int nCmdShow);
	virtual void ExitInstance();
};

extern CDTTools theApp;
#pragma once
namespace UI {

class SKINUI_API CSkinApplication
{
public:
	CSkinApplication();

public:
	virtual BOOL InitInstance() = 0;
	virtual ResType GetResType() { return RT_FILE; }
	virtual void Run(const tstring& strCmdLine, int nCmdShow) = 0;
	virtual void ExitInstance();
};

};
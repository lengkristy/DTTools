#include "stdafx.h"
#include "DTTools.h"
#include "MainDialog.h"

HINSTANCE g_hInstance = NULL;//定义全局应用程序实例

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	g_hInstance = hInstance;
	return SkinUI::WinMain(hInstance, lpCmdLine, nCmdShow);
}

CDTTools theApp;
CDTTools::CDTTools()
{
	
}

BOOL CDTTools::InitInstance()
{
	SkinUI::LoadConfig(_T("C:\\MySkin\\DTTools\\AppConfig.xml"));
	SkinUI::LoadSkin(_T("C:\\MySkin\\DTTools\\"));
	return TRUE;
}

void CDTTools::Run(const tstring& strCmdLine, int nCmdShow)
{
	CMainDialog dlg;
	SkinUI::SetMainWnd(&dlg);
	dlg.DoModal(NULL);
}

void CDTTools::ExitInstance()
{
	CSkinApplication::ExitInstance();
}
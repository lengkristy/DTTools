#include "Command.h"
#include <Windows.h>

Command::Command(){

}

Command::~Command(){

}

void Command::StartApplication(const TCHAR* exePath)
{
	TCHAR szCommandLine[1024];
	 memcpy(szCommandLine, exePath, 1024);
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	BOOL bRet = ::CreateProcess(
		NULL,           // ���ڴ�ָ����ִ���ļ����ļ���
		szCommandLine,      // �����в���
		NULL,           // Ĭ�Ͻ��̰�ȫ��
		NULL,           // Ĭ���̰߳�ȫ��
		FALSE,          // ָ����ǰ�����ڵľ�������Ա��ӽ��̼̳�
		CREATE_NEW_CONSOLE, // Ϊ�½��̴���һ���µĿ���̨����
		NULL,           // ʹ�ñ����̵Ļ�������
		NULL,           // ʹ�ñ����̵���������Ŀ¼
		&si,
		&pi); 

	if (bRet)
	{
		//WaitForSingleObject(pi.hProcess, INFINITE);
		// ��Ȼ���ǲ�ʹ�������������������̽����ǹر�
		::CloseHandle(pi.hThread);
		::CloseHandle(pi.hProcess);
	}
}

void Command::OpenMyComputer()
{
	ShellExecute(NULL, NULL, _T("::{20D04FE0-3AEA-1069-A2D8-08002B30309D}"), NULL, NULL, SW_SHOWNORMAL);
}
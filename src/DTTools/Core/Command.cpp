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
		NULL,           // 不在此指定可执行文件的文件名
		szCommandLine,      // 命令行参数
		NULL,           // 默认进程安全性
		NULL,           // 默认线程安全性
		FALSE,          // 指定当前进程内的句柄不可以被子进程继承
		CREATE_NEW_CONSOLE, // 为新进程创建一个新的控制台窗口
		NULL,           // 使用本进程的环境变量
		NULL,           // 使用本进程的驱动器和目录
		&si,
		&pi); 

	if (bRet)
	{
		//WaitForSingleObject(pi.hProcess, INFINITE);
		// 既然我们不使用两个句柄，最好是立刻将它们关闭
		::CloseHandle(pi.hThread);
		::CloseHandle(pi.hProcess);
	}
}

void Command::OpenMyComputer()
{
	ShellExecute(NULL, NULL, _T("::{20D04FE0-3AEA-1069-A2D8-08002B30309D}"), NULL, NULL, SW_SHOWNORMAL);
}
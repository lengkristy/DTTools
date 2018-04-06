#pragma once
#include <tchar.h>
class Command//默认提取第一个
{
public:
	Command();
	~Command();
public:
	void StartApplication(const TCHAR* exePath);//执行程序
	void OpenMyComputer();//打开我的电脑
};


#pragma once
#include <tchar.h>
class Command//Ĭ����ȡ��һ��
{
public:
	Command();
	~Command();
public:
	void StartApplication(const TCHAR* exePath);//ִ�г���
	void OpenMyComputer();//���ҵĵ���
};


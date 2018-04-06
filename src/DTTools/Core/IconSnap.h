#pragma once
#include "Icons.h"
#include <windows.h>
#include <shellapi.h>//SHGetFileInfo
#include <ShObjIdl.h>//IShellFolder::GetAttributesOf
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
class IconSnap//Ĭ����ȡ��һ��
{
public:
	IconSnap();
	~IconSnap();
public:
	HICON ExtractIcon(const TCHAR* programPath);//��ȡӦ�ó���ͼ�꣬��ȡ��һ��

	BOOL ExtractIconToFile(const TCHAR* programPath, const TCHAR* iconFilePath);//��ȡӦ�ó���ͼ�걣�浽�ļ�����ȡ��һ��
	bool SaveHIconToPngFile(HICON hIcon, LPCTSTR lpszPicFileName);//��ICOͼ�걣��Ϊpng
private:
	LPICONRESOURCE m_lpIR;  // ICON��Դָ��
	EXEDLLICONINFO m_EDII;
	BOOL m_hasExtract;//�Ƿ��Ѿ���ȡ��ͼ��
	CIcons *m_pIcons;
	LPTSTR	m_dIconID = NULL;//��Դid,��������
	TCHAR m_strIconID[512];//��Դid���ַ�������
	BOOL m_iconIdIsDigital;//icon��Դid�Ƿ�Ϊ����
public:
	BOOL HasExtract();//�Ƿ��Ѿ���ȡ��һ��ͼ��
	void SetExtract();//�����Ѿ���ȡ��һ��ͼ��
	void SetIconID(const LPTSTR iconId);//������ȡ��iconID
	void SetIconType(BOOL type);//����ICONԴ���ͣ�TRUEΪ���֣�FALSEΪ�ַ���
private:
	BOOL Extract(const TCHAR* programPath);//��ȡͼ����Ϣ��Ĭ����ȡ��һ��
	int GetEncoderClsid(const WCHAR* format, CLSID* pClsid);
};


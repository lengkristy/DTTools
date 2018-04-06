#pragma once
#include "Icons.h"
#include <windows.h>
#include <shellapi.h>//SHGetFileInfo
#include <ShObjIdl.h>//IShellFolder::GetAttributesOf
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
class IconSnap//默认提取第一个
{
public:
	IconSnap();
	~IconSnap();
public:
	HICON ExtractIcon(const TCHAR* programPath);//提取应用程序图标，提取第一个

	BOOL ExtractIconToFile(const TCHAR* programPath, const TCHAR* iconFilePath);//提取应用程序图标保存到文件，提取第一个
	bool SaveHIconToPngFile(HICON hIcon, LPCTSTR lpszPicFileName);//将ICO图标保存为png
private:
	LPICONRESOURCE m_lpIR;  // ICON资源指针
	EXEDLLICONINFO m_EDII;
	BOOL m_hasExtract;//是否已经提取到图标
	CIcons *m_pIcons;
	LPTSTR	m_dIconID = NULL;//资源id,数字类型
	TCHAR m_strIconID[512];//资源id，字符串类型
	BOOL m_iconIdIsDigital;//icon资源id是否为数字
public:
	BOOL HasExtract();//是否已经提取第一个图标
	void SetExtract();//设置已经提取第一个图标
	void SetIconID(const LPTSTR iconId);//设置提取的iconID
	void SetIconType(BOOL type);//设置ICON源类型，TRUE为数字，FALSE为字符串
private:
	BOOL Extract(const TCHAR* programPath);//提取图标信息，默认提取第一个
	int GetEncoderClsid(const WCHAR* format, CLSID* pClsid);
};


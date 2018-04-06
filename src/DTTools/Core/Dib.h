// Dib.h: interface for the CDib class.
//////////////////////////////////////////////////////////////////////
//
//用途：IconSnap所需调用的类
//功能：DIB设备无关位图基础操作类
//作者：徐景周
//日期：2001年9月
//
//////////////////////////////////////////////////////////////////////
#pragma once
#include <Windows.h>

// How wide, in bytes, would this many bits be, DWORD aligned?
#define WIDTHBYTES(bits)      ((((bits) + 31)>>5)<<2)

class CDib  
{
public:
	CDib();
	virtual ~CDib();

public:
    LPSTR FindDIBBits (LPSTR lpbi);
	WORD DIBNumColors (LPSTR lpbi);
	WORD PaletteSize (LPSTR lpbi);
	DWORD BytesPerLine( LPBITMAPINFOHEADER lpBMIH );
	LPBYTE ConvertDIBFormat( LPBITMAPINFO lpSrcDIB, UINT nWidth, UINT nHeight, UINT nColors, BOOL bStretch );
	void SetMonoDIBPixel( LPBYTE pANDBits, DWORD dwWidth, DWORD dwHeight, DWORD x, DWORD y, BOOL bWhite );
	LPBYTE ReadBMPFile( LPCTSTR szFileName );
	BOOL WriteBMPFile( LPCTSTR szFileName, LPBYTE lpDIB );

private:
	BOOL CopyColorTable( LPBITMAPINFO lpTarget, LPBITMAPINFO lpSource );

};

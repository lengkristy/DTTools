#include "../stdafx.h"
#include "IconSnap.h"

/****************************************************************************
*
*     FUNCTION: MyEnumProcedure
*
*     PURPOSE:  Callback for enumerating resources in a DLL/EXE
*
*     PARAMS:   HANDLE  hModule  - Handle of the module
*               LPCTSTR lpszType - Resource Type
*               LPTSTR  lpszName - Resource Name
*               LONG    lParam   - Handle of ListBox to add name to
*
*     RETURNS:  BOOL - TRUE to continue, FALSE to stop
*
\****************************************************************************/
BOOL CALLBACK MyEnumProcedure(HANDLE  hModule, LPCTSTR  lpszType, LPTSTR  lpszName, LONG  lParam)
{
	IconSnap* pIconSnap = (IconSnap*)lParam;
	if (!pIconSnap)
		return FALSE;
	if (pIconSnap->HasExtract())
		return TRUE;
	LONG    nIndex = LB_ERR;
	TCHAR iconId[512] = { 0 };
	if (HIWORD(lpszName) == 0)//判断资源ID是不是数字
	{
		pIconSnap->SetIconType(TRUE);
		pIconSnap->SetIconID(lpszName);
	}
	else//资源id为字符串
	{
		wsprintf(iconId, _T("%s"), lpszName);
		pIconSnap->SetIconType(FALSE);
		pIconSnap->SetIconID(iconId);
	}
	pIconSnap->SetExtract();//设置已经提取第一个图标
	return TRUE;
}
/* End MyEnumProcedure() ***************************************************/

IconSnap::IconSnap()
{
	m_hasExtract = FALSE;
	memset(this->m_strIconID, 0, 512);
}


IconSnap::~IconSnap()
{
	FreeLibrary(this->m_EDII.hInstance);
}

BOOL IconSnap::Extract(const TCHAR* programPath)
{
	HINSTANCE  hLibrary;
	// Load the DLL/EXE - NOTE: must be a 32bit EXE/DLL for this to work
	if ((hLibrary = LoadLibraryEx(programPath, NULL, LOAD_LIBRARY_AS_DATAFILE)) == NULL)
	{
		// Failed to load - abort
		return FALSE;
	}
	// Store the info
	m_EDII.szFileName = programPath;
	m_EDII.hInstance = hLibrary;

	// Fill in the listbox with the icons available
	if (!EnumResourceNames(m_EDII.hInstance, RT_GROUP_ICON, (ENUMRESNAMEPROC)MyEnumProcedure, (LPARAM)this))
	{
		return FALSE;
	}
	return TRUE;
}


HICON IconSnap::ExtractIcon(const TCHAR* programPath)
{
	HICON hIcon = NULL;
	Extract(programPath);
	hIcon = m_pIcons->GetIconFromInstance(m_EDII.hInstance, this->m_iconIdIsDigital?this->m_dIconID:this->m_strIconID);
	return hIcon;
}

BOOL IconSnap::ExtractIconToFile(const TCHAR* programPath, const TCHAR* iconFilePath)
{
	Extract(programPath);
	m_lpIR = m_pIcons->ReadIconFromEXEFile(programPath, this->m_iconIdIsDigital ? this->m_dIconID : this->m_strIconID);
	if (!m_lpIR)
	{
		return NULL;
	}
	return m_pIcons->WriteIconToICOFile(m_lpIR, iconFilePath);
}

bool IconSnap::SaveHIconToPngFile(HICON hIcon, LPCTSTR lpszPicFileName)
{
	if (hIcon == NULL)
	{
		return false;
	}

	ICONINFO icInfo = { 0 };
	if (!::GetIconInfo(hIcon, &icInfo))
	{
		return false;
	}

	BITMAP bitmap;
	GetObject(icInfo.hbmColor, sizeof(BITMAP), &bitmap);

	Gdiplus::Bitmap* pBitmap = NULL;
	Gdiplus::Bitmap* pWrapBitmap = NULL;

	do
	{
		if (bitmap.bmBitsPixel != 32)
		{
			pBitmap = Gdiplus::Bitmap::FromHICON(hIcon);
		}
		else
		{
			pWrapBitmap = Gdiplus::Bitmap::FromHBITMAP(icInfo.hbmColor, NULL);
			if (!pWrapBitmap)
				break;

			Gdiplus::BitmapData bitmapData;
			Gdiplus::Rect rcImage(0, 0, pWrapBitmap->GetWidth(), pWrapBitmap->GetHeight());

			pWrapBitmap->LockBits(&rcImage, Gdiplus::ImageLockModeRead, pWrapBitmap->GetPixelFormat(), &bitmapData);
			pBitmap = new (Gdiplus::Bitmap)(bitmapData.Width, bitmapData.Height, bitmapData.Stride, PixelFormat32bppARGB, (BYTE*)bitmapData.Scan0);
			pWrapBitmap->UnlockBits(&bitmapData);
		}

		CLSID encoderCLSID;
		GetEncoderClsid(_T("image/png"), &encoderCLSID);
		Gdiplus::Status st = pBitmap->Save(lpszPicFileName, &encoderCLSID, NULL);
		if (st != Gdiplus::Ok)
			break;

	} while (false);

	delete pBitmap;
	if (pWrapBitmap)
		delete pWrapBitmap;
	DeleteObject(icInfo.hbmColor);
	DeleteObject(icInfo.hbmMask);

	return true;
}

int IconSnap::GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT num = 0, size = 0;

	Gdiplus::GetImageEncodersSize(&num, &size);
	if (size == 0)
		return -1;  // Failure

	Gdiplus::ImageCodecInfo* pImageCodecInfo = (Gdiplus::ImageCodecInfo*)(malloc(size));

	Gdiplus::GetImageEncoders(num, size, pImageCodecInfo);
	bool found = false;
	for (UINT ix = 0; !found && ix < num; ++ix)
	{
		if (_wcsicmp(pImageCodecInfo[ix].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[ix].Clsid;
			found = true;
			break;
		}
	}

	free(pImageCodecInfo);
	return found;
}


BOOL IconSnap::HasExtract()
{
	return this->m_hasExtract;
}

void IconSnap::SetExtract()
{
	this->m_hasExtract = TRUE;
}

void IconSnap::SetIconID(const LPTSTR iconId)
{
	if (this->m_iconIdIsDigital)
	{
		this->m_dIconID = iconId;
	}
	else
	{
		memcpy(m_strIconID, iconId, 512);
	}
}

void IconSnap::SetIconType(BOOL type)
{
	this->m_iconIdIsDigital = type;
}
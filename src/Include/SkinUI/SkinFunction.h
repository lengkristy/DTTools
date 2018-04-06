#pragma once
namespace UI {

class SKINUI_API SkinUI
{
public:
	static int WinMain(HINSTANCE hInstance, const tstring& strCmdLine, int nCmdShow);
	static void SetDllInstance(HMODULE hModule);
	static HINSTANCE GetInstance();

	static void LoadSkin(const tstring& strPath);
	static void LoadConfig(const tstring& strPath);
	static void ChangeSkin(const tstring& strSkin);
	static void ChangeFontSize(LONG nFontSizeChange);
	static void ChangeAppName(const tstring& strAppName);

	static ResType GetResType();
	static tstring GetLanguage();
	static LONG GetFontSizeChange();
	static tstring GetAppName();

	static void SetMainWnd(CSkinDialog* pDialog);
	static CSkinDialog* GetMainWnd();
	static HWND GetMainHWND();

	static void SetModuleName(const tstring& strName);
	static tstring GetModuleName();

	static void OpenAnimation(BOOL bOpen);
	static BOOL IsAnimationOpen();

public:
	static LONG GetDialogRadius();
	static LONG GetDialogTitleHeight();
	static LONG GetDialogSysButtonTopOffset();
	static LONG GetDialogSysButtonRightOffset();
	static LONG GetMenuMinWidth();
	static LONG GetMenuItemHeight();
	static LONG GetMenuSeparatorHeight();
	static tstring GetMenuItemBkgImage();
	static tstring GetMenuItemHotBkgColor();
	static tstring GetMenuItemHotTextColor();
	static tstring GetDialogBkgBottomColor();
	static tstring GetDialogBkgLineColor();
	static BOOL IsAllowFullTransparentSkin();

	static CPatch GetDialogShadowPatch();
	static vector<tstring> GetDialogBorder();
	static tstring GetDialogCaptionFontStyle();
	static tstring GetDialogCaptionAlignment();
	static tstring GetMoreSkinURL();
	static tstring GetCefExternal();

public:
	static BOOL GetSysConfig(const tstring& strKey, tstring& strValue);
	static BOOL GetSysConfig(const tstring& strKey, BOOL& bValue);
	static BOOL GetSysConfig(const tstring& strKey, UINT& nValue);
	static BOOL GetSysConfig(const tstring& strKey, LONG& nValue);
	static BOOL GetSysConfig(const tstring& strKey, uint64& nValue);

	static BOOL GetAppConfig(const tstring& strKey, tstring& strValue);
	static BOOL GetAppConfig(const tstring& strKey, BOOL& bValue);
	static BOOL GetAppConfig(const tstring& strKey, UINT& nValue);
	static BOOL GetAppConfig(const tstring& strKey, LONG& nValue);
	static BOOL GetAppConfig(const tstring& strKey, uint64& nValue);

	static void SetAppConfig(const tstring& strKey, const tstring& strValue);
	static void SetAppConfig(const tstring& strKey, const BOOL& bValue);
	static void SetAppConfig(const tstring& strKey, const UINT& nValue);
	static void SetAppConfig(const tstring& strKey, const LONG& nValue);
	static void SetAppConfig(const tstring& strKey, const uint64& nValue);

public:
	static tstring GetVersion();
	static tstring GetVersionDate();
	static tstring GetCurModulePath();
	static tstring GetTempPath();

	static BOOL IsAltKeyDown();
	static BOOL IsCtrlKeyDown();
	static BOOL IsShiftKeyDown();
	static BOOL IsLeftKeyDown();

	static tstring GetFontFamily();
	static HFONT GetFont(const tstring& strFont);
	static Color GetColor(const tstring& strColor);
	static tstring GetString(const tstring& strString);
	static tstring GetStringResource(const tstring& strResource, BOOL bSkinUIResource);

	static Image* GetImage(const tstring& strImage);
	static CSize GetImageSize(const tstring& strImage);
	static CPatch GetImagePatch(const tstring& strImage);
	static LONG GetImageFrameCount(const tstring& strImage);

public:
	static BOOL IsLightColor(const Color& color);
	static BOOL IsImage(const tstring& strPath);
	static BOOL IsGifImage(const tstring& strPath);
	static BOOL IsGifImage(Image& image);
	static BOOL SaveImage(Image* pBmp, const tstring& strFilePath);
	static BOOL SaveAsImage(const tstring& strExistFilePath, const tstring& strFilePath);
	static BOOL GenFileIcon(const tstring& strFilePath, const tstring& strIconPath, BOOL bBigIcon);
	static Image* ZoomImage(Image* pOldImage, const CSize& szMax, CSize& szNew);
	static HBITMAP CreateCompatibleBitmap(HDC hdc, int cx, int cy, BYTE** ppBits = NULL);
	static Bitmap* CreateBitmapFromHBITMAP(HBITMAP hBitmap);
	static HICON LoadIcon(UINT nIconId, CSize szIcon);
	static Color GetColorFromBitmap(Bitmap* pBitmap);

public:
	static CRect GetFullScreenRect();
	static CRect GetParentWindowRect(HWND hWndParent);
	static CMonitor MonitorFromPoint(const CPoint& point);
	static CMonitor MonitorFromRect(const CRect& rect);
	static CMonitor MonitorFromWindow(HWND hWnd);

public:
	static BOOL SetMapFileBuffer(LONG nId, const void* pBuffer, const list<CRect>& lstDirty, int width, int height);
	static BOOL GetMapFileBuffer(LONG nId, void* pBuffer, const list<CRect>& lstDirty, int width, int height);

public:
	static tstring GetXMLFromClipboard();
	static tstring GetTextFromClipboard();
	static tstring GetImagePathFromClipboard();
	static int GetFileFromClipboard(HDROP hDrop, list<tstring>& lstFile);

	static void SetTextToClipboard(const tstring& strText, HWND hWndNewOwner, BOOL bEmptyClipboard);
	static void SetImageToClipboard(const tstring& strImage, HWND hWndNewOwner, BOOL bEmptyClipboard);
	static void SetXMLToClipboard(const tstring& strXML, HWND hWndNewOwner, BOOL bEmptyClipboard);
	static LRESULT SendCopyDataMessage(HWND hWnd, ULONG_PTR dwData, const CCopyDataPacketOut& packet);
	static void SetForegroundWindow(CSkinDialog* pDlg);
	static BOOL IsForegroundWindow(CSkinDialog* pDlg);

	static BOOL RegHotKey(WORD wVirtualKeyCode, WORD wModifiers, const tstring& strHotKey);
	static BOOL UnRegHotKey(const tstring& strHotKey);
	static BOOL OpenURL(const tstring& strURL);

public:
	static int StringToInt(const tstring& str);
	static BOOL StringToBool(const tstring& str);
	static LONG StringToLong(const tstring& str);
	static int64 StringToInt64(const tstring& str);
	static CSize StringToSize(const tstring& str);
	static CPoint StringToPoint(const tstring& str);
	static CRect StringToRect(const tstring& str);
	static Color StringToColor(const tstring& str);
	static COLORREF StringToCOLORREF(const tstring& str);
	static vector<UINT> StringToDrag(const tstring& str);
	static CharFormat StringToCharFormat(const tstring& str);
	static void StringToHotKey(const tstring& strHotKey, WORD& wVirtualKeyCode, WORD& wModifiers);

public:
	static tstring IntToString(uint64 n);
	static tstring BoolToString(bool b);
	static tstring BoolToString(BOOL b);
	static tstring COLORREFToString(COLORREF clr);
	static tstring RectToString(const CRect& rect);
	static tstring SizeToString(const CSize& size);
	static tstring PointToString(const CPoint& point);
	static tstring ColorToString(const Color& color);
	static tstring CharFormatToString(const CharFormat& format);
	static tstring HotKeyToString(WORD wVirtualKeyCode, WORD wModifiers);

public:
	static void StringMakeLower(tstring& str);
	static void StringMakeUpper(tstring& str);
	static void StringTrim(tstring& str, const TCHAR& chTarget);
	static void StringTrimLeft(tstring& str, const TCHAR& chTarget);
	static void StringTrimRight(tstring& str, const TCHAR& chTarget);
	static void StringReplace(tstring& str, const tstring& strOld, const tstring& strNew);
	static void StringSplit(const tstring& strTarget, const tstring& separator, vector<tstring>& vecString);

	static int StringFind(const tstring& str, const tstring& strFind);
	static int StringFindNoCase(const tstring& str, const tstring& strFind);
	static int StringReverseFind(const tstring& str, const TCHAR& chTarget);
	static int StringCompare(const tstring& str, const tstring& strCompare);
	static int StringCompareNoCase(const tstring& str, const tstring& strCompare);

	static tstring StringFormat(const TCHAR* fmt, ...);
	static tstring StringLeft(const tstring& str, int nCount);
	static tstring StringRight(const tstring& str, int nCount);
	static tstring StringMid(const tstring& str, int nFirst);
	static tstring StringMid(const tstring& str, int nFirst, int nCount);

	static wstring UTF8ToUnicode(const string& str);
	static string UnicodeToUTF8(const wstring& str);
	static wstring MultiByteToWideChar(const string& str);
	static string WideCharToMultiByte(const wstring& str);

public:
	static void IdToNode(CXMLNode& node, UINT nXmlId);
	static BOOL FileToNode(CXMLNode& node, const tstring& strPath);
	static void StringToNode(CXMLNode& node, const tstring& strXml);
	static void NodeToFile(const CXMLNode& node, const tstring& strPath);
	static void NodeToString(const CXMLNode& node, tstring& strXml);

public:
	static void StringToObject(JsonObject& object, const tstring& strJson);
	static tstring ObjectToString(const JsonObject& object, bool bStyled = false);
	static tstring ValueToString(const JsonValue& value, bool bStyled = false);

public:
	static void LockDrawText(BOOL bLock);
	static BOOL IsLockDrawText();
	static void OnlyDrawText(BOOL bOnly);
	static BOOL IsOnlyDrawText();

	static CSize MesureSize(const CRect& rect, const tstring& text, const tstring& font, BOOL bMultiLine = FALSE);
	static tstring MesureText(const CRect& rect, const tstring& text, const tstring& font, BOOL bMultiLine = FALSE, UINT nEndTextLength = 0);

public:
	static void FillRect(HDC hdc, const CRect& rect, const tstring& color, int nRadius = 0, int nRoundMask = ROUND_ALL);
	static void FillRect(HDC hdc, const CRect& rect, const Color& color, int nRadius = 0, int nRoundMask = ROUND_ALL);
	static void FillRect(HDC hdc, const CRect& rect, const tstring& colorBegin, const tstring& colorEnd, int nRadius = 0, int nRoundMask = ROUND_ALL, LinearGradientMode mode = LinearGradientModeVertical);
	static void FillRect(HDC hdc, const CRect& rect, const Color& colorBegin, const Color& colorEnd, int nRadius = 0, int nRoundMask = ROUND_ALL, LinearGradientMode mode = LinearGradientModeVertical);

	static void DrawRect(HDC hdc, const CRect& rect, const tstring& color, int nRadius = 0, int nRoundMask = ROUND_ALL);
	static void DrawRect(HDC hdc, const CRect& rect, const Color& color, int nRadius = 0, int nRoundMask = ROUND_ALL);
	static void DrawImage(HDC hdc, const CRect& rect, const tstring& strImage, UINT nIndex = 0, BOOL bDisable = FALSE, BOOL bStretch = FALSE);
	static void DrawImage(HDC hdc, const CRect& rect, Image* pImage, LONG nRadius = 0);
	static void DrawLine(HDC hdc, const tstring& color, int nLeft, int nTop, int nRight, int nBottom, DashStyle dashStyle = DashStyleSolid);
	static void DrawLine(HDC hdc, const Color& color, int nLeft, int nTop, int nRight, int nBottom, DashStyle dashStyle = DashStyleSolid);
	static void DrawText(HDC hdc, const CRect& rect, const tstring& text, const tstring& font, const tstring& color, UINT format);
	static void DrawText(HDC hdc, const CRect& rect, const tstring& text, const tstring& font, const Color& color, UINT format);
};

};
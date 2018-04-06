#pragma once
namespace UI {

class SKINUI_API CSkinColorDialog
{
public:
	CSkinColorDialog(const Color& color, DWORD dwFlags);

public:
	INT_PTR DoModal(HWND hWndParent);
	Color GetColor();

private:
	Color	m_color;
	DWORD	m_dwFlags;
};

class SKINUI_API CSkinFileDialog
{
public:
	CSkinFileDialog(const tstring& strTitle, LPTSTR lpstrFilter, UINT nMaxCount, BOOL bSelShortCut = TRUE);
	CSkinFileDialog(const tstring& strTitle, const list<tstring>& lstFilter, UINT nMaxCount, BOOL bSelShortCut = TRUE);

public:
	INT_PTR DoModal(HWND hWndParent);
	const list<tstring>& GetFile();
	BOOL GetOverLimit();

private:
	tstring				m_strTitle;
	LPTSTR				m_lpstrFilter;
	tstring				m_strFilter;
	UINT				m_nMaxCount;
	list<tstring>		m_lstFile;
	BOOL				m_bSelShortCut;
	BOOL				m_bOverLimit;
};

class SKINUI_API CSkinFolderDialog
{
public:
	CSkinFolderDialog(const tstring& strTitle, BOOL bWithSlash = TRUE);
	CSkinFolderDialog(const tstring& strTitle, const tstring& strDefaultFolder, BOOL bWithSlash = TRUE);

public:
	INT_PTR DoModal(HWND hWndParent);
	tstring GetFolder();

private:
	tstring				m_strTitle;
	tstring				m_strDefaultFolder;
	tstring				m_strFolder;
	BOOL				m_bWithSlash;
};

class SKINUI_API CSkinSaveAsDialog
{
public:
	CSkinSaveAsDialog(const tstring& strFile, LPTSTR lpstrFilter);

public:
	INT_PTR DoModal(HWND hWndParent);
	tstring GetFile();

private:
	tstring				m_strFile;
	LPTSTR				m_lpstrFilter;
};

class SKINUI_API CSkinPicSaveAsDialog
{
public:
	CSkinPicSaveAsDialog(const tstring& strFile);

public:
	INT_PTR DoModal(HWND hWndParent);
	tstring GetFile();

private:
	tstring				m_strFile;
};

class SKINUI_API CSkinPopupDialog : public CSkinDialog
{
public:
	CSkinPopupDialog(const tstring& strXml = _T(""));
	~CSkinPopupDialog();

protected:
	LRESULT OnInitDialogFinish(WPARAM wParam, LPARAM lParam);

	void OnMouseLeave(BOOL& bHandle){}
	void OnMouseMove(UINT nFlags, CPoint point, BOOL& bHandle);

	void OnLButtonDown(UINT nFlags, CPoint point, BOOL& bHandle);
	void OnRButtonDown(UINT nFlags, CPoint point, BOOL& bHandle);
	SKINUI_DECLARE_MESSAGE_MAP()
};

class SKINUI_API CSkinTrayIcon : public CTimerListener
{
public:
	friend class CSkinDialog;

private:
	CSkinTrayIcon(CSkinDialog* pSkinDialog);
	~CSkinTrayIcon();

public:
	void Flash(BOOL bFlash);
	BOOL IsFlashing();

	void Modify(const tstring& strTips, HICON hIcon = NULL);
	const NOTIFYICONDATA& GetNotifyIconData();

protected:
	LRESULT HandleTrayMessage(WPARAM wParam, LPARAM lParam);

protected:
	void Update(DWORD dwMessage, const tstring& strTips, HICON hIcon = NULL);
	void Delete();

protected:
	virtual void HandleTimer(UINT_PTR nIDEvent);

protected:
	NOTIFYICONDATA		m_nid;
	CSkinDialog*		m_pSkinDialog;
	BOOL				m_bIconFlashing;
	BOOL				m_bMouseEnter;
	CPoint				m_ptMouseHover;
};

inline const NOTIFYICONDATA& CSkinTrayIcon::GetNotifyIconData()
{
	return m_nid;
}

};
#pragma once
namespace UI {

class CSkinImage;
class CSkinTrayIcon;
class CDialogAnimation;
class CCollapseAnimation;
class CSkinLoadingLayout;
class SKINUI_API CSkinDialog : public CSkinWindow, public CDropTarget
{
public:
	friend class CDialogAnimation;

public:
	CSkinDialog(const tstring& strXml = _T(""));
	virtual ~CSkinDialog();

public:
	static void ChangeSkin();
	static void ChangeFontSize();

public:
	BOOL Create(HWND hWndParent = NULL, DWORD dwStyle = WS_POPUP | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU);
	INT_PTR DoModal(HWND hWndParent = NULL);

public:
	UINT MsgBox(const tstring& strText, const tstring& strTitle = _T(""), UINT nType = MB_OK, const tstring& strOk = _T(""), const tstring& strCancel = _T(""), const tstring& strCheckBox = _T(""), BOOL bChecked = FALSE, tstring& strEditText = tstring(), tstring& strEditTips = tstring(), BOOL bEditView = FALSE, LONG nEditViewLimit = 0);
	UINT MsgBoxModeless(const tstring& strText, const tstring& strTitle = _T(""), UINT nType = MB_OK, const tstring& strOk = _T(""), const tstring& strCancel = _T(""), const tstring& strCheckBox = _T(""), BOOL bChecked = FALSE, UINT nId = 0, LPARAM lParam = NULL);

	int Alert(const tstring& strMessage, const tstring& strTitle = _T(""), const tstring& strButtonName = _T(""));
	int Confirm(const tstring& strMessage, const tstring& strTitle = _T(""), const tstring& strButtonOK = _T(""), const tstring& strButtonCancel = _T(""));
	int Prompt(tstring& strEditText, tstring& strEditTips, const tstring& strMessage, const tstring& strTitle = _T(""), const tstring& strButtonOK = _T(""), const tstring& strButtonCancel = _T(""), LONG nLimit = 0);
	int ActionSheet(const list<tstring>& lstSheet, const tstring& strTitle = _T(""), const tstring& strButtonCancel = _T(""));

	void ShakeWindow(int nDuration = 2);
	void Toast(const tstring& strText, int nIcon = TOAST_ICON_NONE, int nDuration = 2, int nDelay = 0);
	void ShowLoading(const tstring& strText, const CRect& rect = CRect());
	void ShowLoading(CSkinView* pSkinButton, const CRect& rect = CRect());
	void HideLoading();

	HWND PopupMenu(const tstring& strMenu, const CPoint& ptPopup, const CSize& szButton, CSkinView* pNotifyView, PopupDirection direction = PD_UNKNOWN);
	HWND PopupMenu(const CXMLNode& xmlNode, const CPoint& ptPopup, const CSize& szButton, CSkinView* pNotifyView, PopupDirection direction = PD_UNKNOWN);

	void ViewImage(const vector<tstring>& vecImage, const tstring& strImage);

public:
	virtual void OnInitDialog();
	virtual void OnInitDialogPos();
	virtual void OnInitDialogShow();

	virtual BOOL OnPreMessage(uint nMsg, WPARAM wParam, LPARAM lParam);
	virtual void OnIdle();
	virtual void OnEndDialog();

public:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void InitAnimationAttribute(const CXMLNode& node);

	virtual void SetMenuHWND(HWND hWnd);
	virtual void SetDrag(const vector<UINT>& vecDrag);

	virtual void SetRect(const CRect& rect);
	virtual void RedrawView(BOOL bUpdateWindow = TRUE);
	virtual void EndDialog(INT_PTR nResult);
	virtual void DeleteAllChild();

public:
	virtual void HandleSkinChange();
	virtual void HandleFontSizeChange();
	virtual void HandleChildDelete(CSkinView* pView);

	virtual void HandleTrayMouseEnter(const CPoint& ptCursorPos){}
	virtual void HandleTrayMouseHover(const CPoint& ptCursorPos){}
	virtual void HandleTrayMouseLeave(const CPoint& ptCursorPos){}

	virtual void HandleEscKeyDown(BOOL& bHandle);
	virtual void HandleReturnKeyDown(BOOL& bHandle);
	virtual void HandleTabKeyDown(BOOL& bHandle);
	virtual BOOL HandleEndDialog();

public:
	virtual void DrawBackground(HDC hdc);
	virtual void DrawBkgTheme(HDC hdc);
	virtual void DrawBkgColor(HDC hdc);
	virtual void DrawBkgShadow(HDC hdc);
	virtual void DrawBkgBorder(HDC hdc);

public:
	virtual HDC GetBkgDC();
	virtual HDC GetMemDC();

	virtual CRect GetAreoRect();
	virtual CRect GetClientRect();

	virtual CSkinDialog* GetOwner();
	virtual CSkinView* HitTest(CPoint& point);

protected:
	LRESULT OnCopyData(HWND hWnd, PCOPYDATASTRUCT pCopyDataStruct, BOOL& bHandle);
	LRESULT OnMouseWheel(UINT nFlags, short zDelta, CPoint point, BOOL& bHandle);
	LRESULT OnSetCursor(HWND hWnd, UINT nHitTest, UINT nMessage, BOOL& bHandle);

	LRESULT OnImeStartComposition(WPARAM wParam, LPARAM lParam, BOOL& bHandle);
	LRESULT OnImeEndComposition(WPARAM wParam, LPARAM lParam, BOOL& bHandle);
	LRESULT OnImeComposition(WPARAM wParam, LPARAM lParam, BOOL& bHandle);

	LRESULT OnNcHitTest(CPoint point, BOOL& bHandle);
	LRESULT OnDisplayChange(BOOL& bHandle);
	LRESULT OnEraseBkgnd(BOOL& bHandle);

protected:
	void OnClose(BOOL& bHandle);
	void OnPaint(HDC hDC, BOOL& bHandle);

	void OnMouseLeave(BOOL& bHandle);
	void OnMouseMove(UINT nFlags, CPoint point, BOOL& bHandle);
	void OnMouseHover(WPARAM wParam, CPoint point, BOOL& bHandle);

	void OnChar(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);
	void OnKeyUp(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);
	void OnKeyDown(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);
	void OnSysKeyUp(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);
	void OnSysKeyDown(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);

	void OnLButtonDblClk(UINT nFlags, CPoint point, BOOL& bHandle);
	void OnLButtonDown(UINT nFlags, CPoint point, BOOL& bHandle);
	void OnRButtonDown(UINT nFlags, CPoint point, BOOL& bHandle);
	void OnLButtonUp(UINT nFlags, CPoint point, BOOL& bHandle);
	void OnRButtonUp(UINT nFlags, CPoint point, BOOL& bHandle);

	void OnWindowPosChanged(WINDOWPOS* lpwndpos, BOOL& bHandle);
	void OnGetMinMaxInfo(LPMINMAXINFO lpMMI, BOOL& bHandle);
	void OnSizing(UINT nSide, LPRECT lpRect, BOOL& bHandle);
	void OnSize(UINT nType, CSize size, BOOL& bHandle);

	void OnSetFocus(HWND hWnd, BOOL& bHandle);
	void OnKillFocus(BOOL& bHandle);

	void OnNcLButtonDown(UINT nFlags, CPoint point, BOOL& bHandle);
	void OnNcDestroy(BOOL& bHandle);
	void OnDestroy(BOOL& bHandle);

protected:
	void OnBtnClickedNoTopMost(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedTopMost(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedRestore(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedClose(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedSkin(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedMenu(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedMax(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedMin(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnCancel(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnOK(UINT uNotifyCode, int nID, CSkinView* pView);

protected:
	void OnCommandCut(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnCommandCopy(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnCommandPaste(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnCommandDelete(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnCommandSelectAll(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnCommandSaveAs(UINT uNotifyCode, int nID, CSkinView* pView);

public:
	void OnUpdateCommandCut(CSkinView* pView);
	void OnUpdateCommandCopy(CSkinView* pView);
	void OnUpdateCommandPaste(CSkinView* pView);
	void OnUpdateCommandDelete(CSkinView* pView);
	void OnUpdateCommandSaveAs(CSkinView* pView);

protected:
	LRESULT OnInitDialogFinish(WPARAM wParam, LPARAM lParam);
	LRESULT OnActiveModalDialog(WPARAM wParam, LPARAM lParam);
	LRESULT OnActiveInstance(WPARAM wParam, LPARAM lParam);
	LRESULT OnSyetemTray(WPARAM wParam, LPARAM lParam);

	LRESULT OnIEQueryMessage(WPARAM wParam, LPARAM lParam);
	LRESULT OnCefQueryMessage(WPARAM wParam, LPARAM lParam);

	LRESULT OnBeginDoModal(WPARAM wParam, LPARAM lParam);
	LRESULT OnEndDoModal(WPARAM wParam, LPARAM lParam);

	LRESULT OnViewImage(WPARAM wParam, LPARAM lParam);
	LRESULT OnFastTimer(WPARAM wParam, LPARAM lParam);
	LRESULT OnSpyWindow(WPARAM wParam, LPARAM lParam);
	LRESULT OnSpyClear(WPARAM wParam, LPARAM lParam);

	SKINUI_DECLARE_MESSAGE_MAP()

public:
	void SetResize(BOOL bResize);
	void SetAllowMove(BOOL bAllow);
	void SetDialogRadius(LONG nDialogRadius);

	void SetThemeHeight(LONG nThemeHeight);
	void SetDefaultWidth(LONG nDefaultWidth);
	void SetDefaultHeight(LONG nDefaultHeight);
	void SetMinWidth(LONG nMinWidth);
	void SetMinHeight(LONG nMinHeight);

	void SetSysButton(const tstring& strSysStyle);
	void SetTitleHeight(LONG nTitleHeight);
	void SetTitleCaption(const tstring& strTitle);
	void SetTitleIcon(LONG nIconId);

public:
	void AddWndView(CSkinWndView* pWndView);
	void AddEditView(CSkinEditView* pEditView);
	void AddUpdateUI(CSkinView* pView, CSkinView* pNotifyView);

	void SetTrayMenu(const tstring& strMenu);
	void ModifyTrayIcon(const tstring& strTips, HICON hIcon = NULL);
	void FlashTrayIcon(BOOL bFlash);
	BOOL IsTrayIconFlashing();

	void SetFocusView(CSkinView* pFocus);
	void SetKillFocusView(CSkinView* pKillFocus);
	void SetMenuPopupView(CSkinView* pView);

	void SetCapture(CSkinView* pView = NULL);
	void ReleaseCapture();

public:
	void SetImeInfo(const CPoint& point, LOGFONT logFont);

	void ShowToolTips(const tstring& strTips);
	void HideToolTips();

	void ShowSkinTips(const CPoint& point, const tstring& strLayout);
	void HideSkinTips();

public:
	CSkinImage* LoadImage(const tstring& strImage, const CSize& szMax, CImageObject* pImageObject, BOOL bUseCache);
	CSkinImage* LoadImage(Image* pImage, const CSize& szMax, CImageObject* pImageObject);
	void ReleaseImage(CSkinImage* pImage, CImageObject* pImageObject);

	void SetImageTimer(CSkinImage* pSkinImage, UINT nElapse);
	void KillImageTimer(CSkinImage* pSkinImage);
	void HandleImageTimer();

	void ResetCacheImage();

public:
	tstring GetTrayMenu();
	CSkinView* GetFocusView();
	CSkinView* GetMenuPopupView();
	list<pair<CSkinView*, CSkinView*>>* GetUpdateUI();
	BLENDFUNCTION& GetBlendFunction();

	LONG GetTitleHeight();
	LONG GetDialogRadius();
	LONG GetThemeHeight();
	LONG GetDefaultWidth();
	LONG GetDefaultHeight();
	LONG GetMinWidth();
	LONG GetMinHeight();

	BOOL IsInitDialogFinish();
	BOOL IsDialogAnimationPlaying();

	HWND GetParentHWND();
	HWND GetMenuHWND();

private:
	HDC						m_hdc;
	HBITMAP					m_hBitmap;
	HBITMAP					m_hBitmapBkg;
	HDC						m_hdcBkg;
	HWND					m_hWndToolTip;
	HWND					m_hWndSkinTip;
	HWND					m_hWndCapsTip;
	HWND					m_hWndModal;
	HWND					m_hWndMenu;
	LONG					m_nModalResult;
	LONG					m_nTitleHeight;
	LONG					m_nThemeHeight;
	LONG					m_nDialogRadius;
	BOOL					m_bInitDialogFinish;
	BOOL					m_bShowToolTips;
	BOOL					m_bResize;
	BOOL					m_bModalDlg;
	LOGFONT					m_logFont;
	CPoint					m_ptImeCaretPos;

	list<CSkinWndView*>						m_lstWndView;
	list<CSkinEditView*>					m_lstEditView;
	list<pair<CSkinView*, CSkinView*>>		m_lstUpdate;

	set<CSkinImage*>		m_setImage;
	CSkinLoadingLayout*		m_pLayoutLoading;
	CSkinView*				m_pHotCefView;
	CSkinView*				m_pMenuPopup;
	CSkinView*				m_pCapture;
	CSkinView*				m_pFocus;
	CSkinView*				m_pKillFocus;
	BLENDFUNCTION			m_blend;

protected:
	tstring					m_strXML;
	tstring					m_strTrayMenu;
	UINT_PTR				m_nImageTimerId;
	LONG					m_nEndDialogResult;
	LONG					m_nDefaultWidth;
	LONG					m_nDefaultHeight;
	LONG					m_nMinWidth;
	LONG					m_nMinHeight;
	BOOL					m_bAllowMove;
	CSkinTrayIcon*			m_pTrayIcon;
	CDialogAnimation*		m_pDialogAnimation;
};

inline void CSkinDialog::SetResize(BOOL bResize)
{
	m_bResize = bResize;
}

inline void CSkinDialog::SetAllowMove(BOOL bAllow)
{
	m_bAllowMove = bAllow;
}

inline void CSkinDialog::SetDefaultWidth(LONG nDefaultWidth)
{
	m_nDefaultWidth = nDefaultWidth;
}

inline void CSkinDialog::SetDefaultHeight(LONG nDefaultHeight)
{
	m_nDefaultHeight = nDefaultHeight;
}

inline void CSkinDialog::SetMinWidth(LONG nMinWidth)
{
	m_nMinWidth = nMinWidth;
}

inline LONG CSkinDialog::GetMinWidth()
{
	return m_nMinWidth;
}

inline void CSkinDialog::SetMinHeight(LONG nMinHeight)
{
	m_nMinHeight = nMinHeight;
}

inline LONG CSkinDialog::GetMinHeight()
{
	return m_nMinHeight;
}

inline void CSkinDialog::SetTitleHeight(LONG nTitleHeight)
{
	m_nTitleHeight = nTitleHeight;
}

inline LONG CSkinDialog::GetTitleHeight()
{
	return m_nTitleHeight;
}

inline void CSkinDialog::SetDialogRadius(LONG nDialogRadius)
{
	m_nDialogRadius = nDialogRadius;
}

inline LONG CSkinDialog::GetDialogRadius()
{
	return m_nDialogRadius;
}

inline void CSkinDialog::SetThemeHeight(LONG nThemeHeight)
{
	m_nThemeHeight = nThemeHeight;
}

inline LONG CSkinDialog::GetThemeHeight()
{
	return m_nThemeHeight;
}

inline LONG CSkinDialog::GetDefaultWidth()
{
	return m_nDefaultWidth;
}

inline LONG CSkinDialog::GetDefaultHeight()
{
	return m_nDefaultHeight;
}

inline BOOL CSkinDialog::IsInitDialogFinish()
{
	return m_bInitDialogFinish;
}

inline BLENDFUNCTION& CSkinDialog::GetBlendFunction()
{
	return m_blend;
}

inline list<pair<CSkinView*, CSkinView*>>* CSkinDialog::GetUpdateUI()
{
	return &m_lstUpdate;
}

inline CSkinView* CSkinDialog::GetMenuPopupView()
{
	return m_pMenuPopup;
}

inline CSkinView* CSkinDialog::GetFocusView()
{
	return m_pFocus;
}

inline tstring CSkinDialog::GetTrayMenu()
{
	return m_strTrayMenu;
}

inline HWND CSkinDialog::GetParentHWND()
{
	return m_hWndParent;
}

inline HWND CSkinDialog::GetMenuHWND()
{
	return m_hWndMenu;
}

inline HDC CSkinDialog::GetBkgDC()
{
	return m_hdcBkg;
}

inline HDC CSkinDialog::GetMemDC()
{
	return m_hdc;
}

};
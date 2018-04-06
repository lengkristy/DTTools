#pragma once
namespace UI {

class SKINUI_API CSkinLayout : public CSkinView
{
public:
	CSkinLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void DrawBackground(HDC hdc);
	virtual void DrawForeground(HDC hdc);

protected:
	void DrawViewImageAndColor(HDC hdc, const CRect& rect, const tstring& strImage, const tstring& strColor, BOOL bBkg);
};

class SKINUI_API CSkinHorizontalLayout : public CSkinLayout
{
public:
	CSkinHorizontalLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void SetRect(const CRect& rect);
	virtual void GetWrapContentSize(CSize& size);
};

class SKINUI_API CSkinVerticalLayout : public CSkinLayout
{
public:
	CSkinVerticalLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void SetRect(const CRect& rect);
	virtual void GetWrapContentSize(CSize& size);
};

class SKINUI_API CSkinRelativeLayout : public CSkinLayout
{
public:
	CSkinRelativeLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void SetRect(const CRect& rect);
};

class SKINUI_API CSkinFrameLayout : public CSkinLayout
{
public:
	CSkinFrameLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void SetRect(const CRect& rect);
};

class SKINUI_API CSkinHorzPercentLayout : public CSkinLayout
{
public:
	CSkinHorzPercentLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void SetRect(const CRect& rect);
};

class SKINUI_API CSkinVertPercentLayout : public CSkinLayout
{
public:
	CSkinVertPercentLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void SetRect(const CRect& rect);
};

class SKINUI_API CSkinGridLayout : public CSkinLayout
{
public:
	CSkinGridLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void SetColumnCount(LONG nColumnCount);

public:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void SetRect(const CRect& rect);

private:
	LONG	m_nColumnCount;
};

inline void CSkinGridLayout::SetColumnCount(LONG nColumnCount)
{
	m_nColumnCount = nColumnCount;
}

class SKINUI_API CSkinSplitterLayout : public CSkinRelativeLayout
{
public:
	CSkinSplitterLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void SetRect(const CRect& rect);
};

class CSwitchAnimation;
class SKINUI_API CSwitchAnimationHost : public CSkinFrameLayout
{
public:
	CSwitchAnimationHost(CSkinView* pParent);
	~CSwitchAnimationHost();
	SKINUI_DECLARE_DYNCREATE()

public:
	void ShowView(LONG nId);
	LONG GetShowViewId();

	void ShowView(CSkinView* pView);
	CSkinView* GetShowView();

protected:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void DrawForeground(HDC hdc);

protected:
	virtual void HandleMouseWheel(LONG nStep);
	virtual void HandleMouseMove(CPoint point, UINT nFlags);
	virtual void HandleMouseHover(CPoint point);
	virtual void HandleLButtonUp(CPoint point);
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void HandleLButtonDblClk(CPoint point, BOOL& bHandle);
	virtual void HandleRButtonUp(CPoint point, BOOL& bHandle);
	virtual void HandleRButtonDown(CPoint point);

public:
	virtual void HandleTimer(UINT_PTR nIDEvent);
	virtual void HandleFinishAnimation();
	virtual void HandleChildDelete(CSkinView* pView);

protected:
	CSwitchAnimation*	m_pAnimation;
};

class CHideAnimation;
class SKINUI_API CHideAnimationHost : public CSkinView
{
public:
	CHideAnimationHost(CSkinView* pParent);
	~CHideAnimationHost();
	SKINUI_DECLARE_DYNCREATE()

public:
	void ShowView(LONG nId);
	void ShowView(CSkinView* pView);

	void HideView(LONG nId);
	void HideView(CSkinView* pView);

public:
	virtual void InitAttribute(const CXMLNode& node);

	virtual void SetRect(const CRect& rect);
	virtual void DrawForeground(HDC hdc);
	virtual void HandleTimer(UINT_PTR nIDEvent);

protected:
	CHideAnimation*	m_pAnimation;
};

class SKINUI_API CSkinFloatLayout : public CSkinRelativeLayout
{
public:
	CSkinFloatLayout(CSkinView* pParent);
	~CSkinFloatLayout();
	SKINUI_DECLARE_DYNCREATE()

	static set<CSkinFloatLayout*> s_setFloatLayout;

public:
	void SetZOrder(LONG nZOrder);
	void SetTransparent(BOOL bTransparent);
	void SetLButtonDownHided(BOOL bLButtonDownHided);

	LONG GetZOrder();
	BOOL IsLButtonDownHided();
	uint64 GetVisibleTimestamp();

public:
	virtual void InitAttribute(const CXMLNode& node);

	virtual void SetState(ViewState state);
	virtual void HandleVisibleStateChange();
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void RedrawView(BOOL bUpdateWindow = TRUE);
	virtual void SetRect(const CRect& rect);

public:
	virtual BOOL IsFloatView();
	virtual BOOL IsRedrawAllChild();
	virtual HDC GetMemDC();

protected:
	void ResetCacheImage();

private:
	BOOL				m_bLButtonDownHided;
	BOOL				m_bTransparent;
	uint64				m_nTimestamp;
	LONG				m_nZOrder;

	HDC					m_hdc;
	HBITMAP				m_hBitmap;
};

inline void CSkinFloatLayout::SetLButtonDownHided(BOOL bLButtonDownHided)
{
	m_bLButtonDownHided = bLButtonDownHided;
}

inline BOOL CSkinFloatLayout::IsLButtonDownHided()
{
	return m_bLButtonDownHided;
}

inline void CSkinFloatLayout::SetTransparent(BOOL bTransparent)
{
	m_bTransparent = bTransparent;
}

inline BOOL CSkinFloatLayout::IsFloatView()
{
	return TRUE;
}

inline BOOL CSkinFloatLayout::IsRedrawAllChild()
{
	return TRUE;
}

inline HDC CSkinFloatLayout::GetMemDC()
{
	return m_hdc;
}

inline uint64 CSkinFloatLayout::GetVisibleTimestamp()
{
	return m_nTimestamp;
}

inline void CSkinFloatLayout::SetZOrder(LONG nZOrder)
{
	m_nZOrder = nZOrder;
}

inline LONG CSkinFloatLayout::GetZOrder()
{
	return m_nZOrder;
}

class SKINUI_API CSkinSlideLayout : public CSkinRelativeLayout
{
public:
	CSkinSlideLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void HandleShowFinish();
	virtual void HandleCloseFinish();
};

class SKINUI_API CSlideAnimationHost : public CSkinFloatLayout
{
public:
	CSlideAnimationHost(CSkinView* pParent);
	~CSlideAnimationHost();
	SKINUI_DECLARE_DYNCREATE()

public:
	void Show(CSkinSlideLayout* pSlideLayout);
	void Hide();

protected:
	virtual void DrawForeground(HDC hdc);
	virtual void DrawBackground(HDC hdc);
	virtual void HandleMouseWheel(LONG nStep);
	virtual void HandleMouseMove(CPoint point, UINT nFlags);
	virtual void HandleMouseHover(CPoint point);
	virtual void HandleLButtonUp(CPoint point);
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void HandleLButtonDblClk(CPoint point, BOOL& bHandle);
	virtual void HandleRButtonUp(CPoint point, BOOL& bHandle);
	virtual void HandleRButtonDown(CPoint point);
	virtual void HandleTimer(UINT_PTR nIDEvent);

protected:
	void BuildCache();
	void ReleaseCache();

	BOOL IsPlaying();
	LONG GetTotalProgress();

private:
	vector<LONG>	m_vecProgress;
	LONG			m_nProgress;
	UINT			m_nPos;
	BOOL			m_bHorz;
	BOOL			m_bShow;

	HDC				m_hdcMem;
	HBITMAP			m_hBitmapMem;
	CSkinSlideLayout*	m_pSlideLayout;
};

class SKINUI_API CSkinTextView : public CSkinView
{
public:
	CSkinTextView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void SetFontStyle(const tstring& strFontStyle);
	virtual tstring GetFontStyle();

	virtual void SetFontColor(const tstring& strFontColor);
	virtual tstring GetFontColor();

	virtual void SetHorzAlignment(StringAlignment alignment);
	virtual StringAlignment GetHorzAlignment();

	virtual void SetVertAlignment(StringAlignment alignment);
	virtual StringAlignment GetVertAlignment();

	virtual void SetAutoLayoutEndTextLength(UINT nEndTextLength);
	virtual void SetAutoLayout(BOOL bAutoLayout);
	virtual BOOL IsAutoLayout();

	virtual void SetMultiLine(BOOL bMultiLine);
	virtual BOOL IsMultiLine();

public:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void GetWrapContentSize(CSize& size);

	virtual void SetText(const tstring& strText);
	virtual void SetRect(const CRect& rect);
	virtual void DrawForeground(HDC hdc);

protected:
	UINT GetDrawTextFormat();

protected:
	StringAlignment		m_horzAlignment;
	StringAlignment		m_vertAlignment;
	tstring				m_strTextDraw;
	tstring				m_strFontStyle;
	tstring				m_strFontColor;

	UINT				m_nEndTextLength;
	BOOL				m_bAutoLayout;
	BOOL				m_bMultiLine;
};

class SKINUI_API CSkinTextViewEx : public CSkinTextView
{
public:
	struct STTextObject
	{
		tstring text;
		tstring color;
		CRect rect;
	};

public:
	CSkinTextViewEx(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void SetText(const tstring& strText);
	virtual tstring GetText();

	virtual void SetRect(const CRect& rect);
	virtual void GetWrapContentSize(CSize& size);
	virtual void DrawForeground(HDC hdc);

public:
	void SetText(const list<pair<tstring, tstring>>& lstText);

private:
	list<pair<tstring, tstring>>	m_lstText;
	list<STTextObject>				m_lstDraw;
};

class SKINUI_API CSkinButton : public CSkinRelativeLayout
{
public:
	CSkinButton(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void SetMouseOverOffset(LONG nOffset);
	LONG GetMouseOverOffset();

	void SetPressDownOffset(LONG nOffset);
	LONG GetPressDownOffset();

	void SetShowLoading(BOOL bShowLoading);

public:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void DrawForeground(HDC hdc);

public:
	virtual void HandleMouseEnter();
	virtual void HandleMouseLeave();

	virtual void HandleLButtonUp(CPoint point);
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void HandleLButtonDblClk(CPoint point, BOOL& bHandle);

	virtual BOOL IsHandleUpdateUI();

private:
	LONG	m_nMouseOverOffset;
	LONG	m_nPressDownOffset;
	BOOL	m_bShowLoading;
};

inline BOOL CSkinButton::IsHandleUpdateUI()
{
	return TRUE;
}

inline void CSkinButton::SetShowLoading(BOOL bShowLoading)
{
	m_bShowLoading = bShowLoading;
}

class SKINUI_API CSkinMenuButton : public CSkinButton
{
public:
	CSkinMenuButton(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void HandleLButtonUp(CPoint point);

private:
	PopupDirection	m_direction;
};

class SKINUI_API CSkinHyperlink : public CSkinTextView
{
public:
	CSkinHyperlink(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void SetHotFontStyle(const tstring& strFontStyle);
	virtual tstring GetHotFontStyle();
	virtual tstring GetFontColor();

	virtual void SetHotFontColor(const tstring& strFontColor);
	virtual tstring GetHotFontColor();

	virtual void SetUrl(const tstring& strUrl);
	virtual tstring GetUrl();

public:
	virtual void InitAttribute(const CXMLNode& node);
	virtual tstring GetTips();

	virtual void HandleMouseEnter();
	virtual void HandleMouseLeave();

	virtual void HandleLButtonUp(CPoint point);
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);

	virtual void DrawForeground(HDC hdc);
	virtual void SetRect(const CRect& rect);

private:
	tstring			m_hotStyle;
	tstring			m_hotColor;
	tstring			m_strUrl;
	tstring			m_strDraw;
};

class CSkinRadioButton;
class SKINUI_API CSkinRadioGroup : public CSkinRelativeLayout
{
public:
	CSkinRadioGroup(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void SetChecked(CSkinRadioButton* pRadioButton);
	virtual CSkinRadioButton* GetChecked();

public:
	void SetAllowNoChecked(BOOL bAllowNoChecked);
	BOOL IsAllowNoChecked();

private:
	BOOL m_bAllowNoChecked;
};

class SKINUI_API CSkinAnimationGroup : public CSkinRadioGroup
{
public:
	CSkinAnimationGroup(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void SetChecked(CSkinRadioButton* pRadioButton);
};

class SKINUI_API CSkinRadioButton : public CSkinButton
{
public:
	CSkinRadioButton(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void SetChecked(BOOL bChecked);
	virtual BOOL IsChecked();

	virtual void SetBindView(LONG nBindView);
	virtual LONG GetBindView();

	void SetOnlyPostCommandMessageChecked();
	BOOL IsOnlyPostCommandMessageChecked();

public:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void HandleLButtonDblClk(CPoint point, BOOL& bHandle);
	virtual void HandleLButtonUp(CPoint point);
	virtual void DrawForeground(HDC hdc);

private:
	BOOL	m_bChecked;
	LONG	m_nBindView;

	BOOL	m_bOnlyPostCommandMessageChecked;
};

class SKINUI_API CSkinCheckBox : public CSkinButton
{
public:
	CSkinCheckBox(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void SetChecked(BOOL bChecked);
	virtual BOOL IsChecked();

	virtual void SetCheckedState(CheckedState state);
	virtual CheckedState GetCheckedState();

public:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void HandleLButtonUp(CPoint point);
	virtual void DrawForeground(HDC hdc);

private:
	CheckedState	m_eCheckedState;
};

inline BOOL CSkinCheckBox::IsChecked()
{
	return m_eCheckedState == CS_CHECKED;
}

inline void CSkinCheckBox::SetChecked(BOOL bChecked)
{
	SetCheckedState(bChecked ? CS_CHECKED : CS_UNCHECKED);
}

inline CheckedState CSkinCheckBox::GetCheckedState()
{
	return m_eCheckedState;
}

class SKINUI_API CSkinImageView : public CSkinView, public CImageObject
{
public:
	CSkinImageView(CSkinView* pParent);
	~CSkinImageView();
	SKINUI_DECLARE_DYNCREATE()

public:
	void SetAutoPlay(BOOL bAutoPlay);
	BOOL IsAutoPlay();

	void SetClickAble(BOOL bClickAble);
	BOOL IsClickAble();

public:
	void Play();
	void Stop();

public:
	virtual void SetImage(const tstring& strImage);
	virtual void LoadImage(const tstring& strImage);

	virtual void RedrawImageObject();
	virtual BOOL IsImageVisible();

public:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void GetLayoutSize(CSize& size);

	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void HandleLButtonUp(CPoint point);

	virtual void DrawForeground(HDC hdc);

protected:
	BOOL			m_bAutoPlay;
	BOOL			m_bClickAble;
	CSkinImage*		m_pSkinImage;
};

class SKINUI_API CSkinImageViewEx : public CSkinView
{
public:
	CSkinImageViewEx(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void SetAutoPlay(BOOL bAutoPlay);
	BOOL IsAutoPlay();

	void SetClickAble(BOOL bClickAble);
	BOOL IsClickAble();

	void SetElapse(LONG nElapse);

public:
	void Play();
	void Stop();

public:
	virtual void SetImage(const tstring& strImage);
	virtual void DrawForeground(HDC hdc);
	virtual void InitAttribute(const CXMLNode& node);
	virtual void HandleTimer(UINT_PTR nIDEvent);

	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void HandleLButtonUp(CPoint point);

protected:
	LONG	m_nIndex;
	LONG	m_nElapse;
	BOOL	m_bAutoPlay;
	BOOL	m_bClickAble;
};

inline void CSkinImageViewEx::SetElapse(LONG nElapse)
{
	m_nElapse = nElapse;
}

class CSkinComboItem;
class CSkinListView;
class SKINUI_API CSkinComboBox : public CSkinRelativeLayout
{
public:
	CSkinComboBox(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	static void DestroyComboBar();

public:
	void SetCurSel(LONG nCurSel);
	LONG GetCurSel();

	void SetListMaxHeight(LONG nMaxHeight);
	LONG GetListMaxHeight();

	void SetDefaultText(const tstring& strText);
	LONG AddContent(const tstring& str);
	void ResetContent();

	CSkinEditView* GetEditView();

public:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void InitComboList(CSkinListView* pListView);
	virtual const vector<tstring>& GetContent() { return m_vecString; }

public:
	virtual void HandleMouseEnter();
	virtual void HandleMouseLeave();
	virtual void HandleSetCursor(CPoint& point, BOOL& bHandle);
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void HandleSetFocus();
	virtual void HandleKeyDown(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);

	virtual void DrawForeground(HDC hdc);
	virtual void DrawComboBkg(HDC hdc);

	virtual void SetEnable(BOOL bEnabled);
	virtual void SetText(const tstring& strText);
	virtual tstring GetText();

private:
	vector<tstring>		m_vecString;
	LONG				m_nListMaxHeight;
	tstring				m_strDefaultText;
};

class CSkinComboBoxTextView : public CSkinComboBox
{
public:
	CSkinComboBoxTextView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void SetEditMode(BOOL bEditMode);

public:
	virtual void HandleBuildFinish();
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void DrawComboBkg(HDC hdc);

private:
	BOOL		m_bEditMode;
};

class SKINUI_API CSkinLine : public CSkinView
{
public:
	CSkinLine(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void SetDashStyle(DashStyle dashStyle);
	void SetStartColor(const tstring& strColor);
	void SetEndColor(const tstring& strColor);

public:
	virtual void InitAttribute(const CXMLNode& node);

	virtual void DrawForeground(HDC hdc);
	virtual void DrawBackground(HDC hdc){}

private:
	DashStyle	m_dashStyle;
	tstring		m_strStartColor;
	tstring		m_strEndColor;
};

class SKINUI_API CSkinProgress : public CSkinView
{
public:
	CSkinProgress(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void SetPos(uint64 nPos);
	uint64 GetPos();

	void SetRange(uint64 nRange);
	uint64 GetRange();

protected:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void DrawForeground(HDC hdc);

protected:
	uint64	m_nPos;
	uint64	m_nRange;
};

class SKINUI_API CSkinSplitter : public CSkinLine
{
public:
	CSkinSplitter(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void SetMoveRange(LONG nMin, LONG nMax);

	void SetHorzSplitter(BOOL bHorzSplitter);
	BOOL IsHorzSplitter();

public:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void HandleMouseMove(CPoint point, UINT nFlags);
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void HandleLButtonUp(CPoint point);
	virtual void DrawForeground(HDC hdc);

private:
	CPoint	m_ptLButtonDown;
	BOOL	m_bHorzSplitter;
	LONG	m_nMinValue;
	LONG	m_nMaxValue;
	LONG	m_nCurValue;
};

class SKINUI_API CSkinSlider : public CSkinView
{
public:
	CSkinSlider(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void SetPos(LONG nPos);
	LONG GetPos();

	void SetRange(LONG nRange);
	LONG GetRange();

	void SetThumbImage(const tstring& strThumbImage);

public:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void SetTips(const tstring& strTips);
	virtual void SetRect(const CRect& rect);
	virtual void DrawForeground(HDC hdc);

private:
	CRect GetThumbRect();

private:
	LONG				m_nPos;
	LONG				m_nRange;
	CSkinView*			m_pSliderThumb;
};

class CSkinScrollView;
class SKINUI_API CSkinScrollBar : public CSkinView
{
public:
	CSkinScrollBar(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void SetScrollView(CSkinScrollView* pView);
	void SetScrollInfo(const ScrollInfo& info);
	void SetScrollPos(LONG nPos);
	ScrollInfo GetScrollInfo();

	LONG GetScrollBarWidth();
	LONG GetScrollBarHeight();

public:
	virtual void SetRect(const CRect& rect);

private:
	CSkinScrollView*	m_pScrollView;
};

class SKINUI_API CSkinWndView : public CSkinView
{
public:
	CSkinWndView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void CreateWindowHost();
	HWND GetHostHWND();

public:
	virtual void SetRect(const CRect& rect);
	virtual void HandleInitDialogFinish(){}
	virtual void HandleBuildFinish();
	virtual void HandleStartEndDialog();
	virtual void HandleVisibleStateChange();
	virtual void HandleWindowPosChanged();

protected:
	HWND	m_hWndHost;
};

inline HWND CSkinWndView::GetHostHWND()
{
	return m_hWndHost;
}

class CSkinScrollBar;
class SKINUI_API CSkinScrollView : public CSkinView
{
public:
	CSkinScrollView(CSkinView* pParent);
	~CSkinScrollView();

public:
	void SetScrollStep(LONG nStep);
	void SetVertScrollBar(const tstring& strLayout);
	void SetHorzScrollBar(const tstring& strLayout);
	void ScrollTop();
	void ScrollBottom();
	void TryPostScrollMessage();

public:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void SetState(ViewState state);

	virtual void SetScrollPos(LONG nPos, BOOL bVScroll);
	virtual void SetScrollInfo(const ScrollInfo& info, BOOL bVScroll);
	virtual ScrollInfo GetScrollInfo(BOOL bVScroll);

public:
	virtual void ResetScrollInfo() = 0;
	virtual void ResetScrollCache(LONG nOldPos, LONG nNewPos);
	virtual void RedrawView(BOOL bUpdateWindow = TRUE);

	virtual void DrawForeground(HDC hdc);
	virtual void DrawClient(HDC hdc);

public:
	virtual void HandleMouseWheel(LONG nStep);
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void HandleTimer(UINT_PTR nIDEvent);

public:
	virtual void SetAnimationScroll(BOOL bAnimationScroll);
	virtual BOOL IsAnimationScroll();

	virtual void SetHandleMouseWheel(BOOL bHandleMouseWheel);
	virtual BOOL IsHandleMouseWheel();

	virtual CSkinView* HitTest(CPoint& point);
	virtual CRect GetClientRect();

protected:
	void HandleMouseWheel();
	void ReleaseScrollCache();

protected:
	CSkinScrollBar*			m_pVertBar;
	CSkinScrollBar*			m_pHorzBar;
	ScrollInfo				m_vertInfo;
	ScrollInfo				m_horzInfo;
	vector<LONG>			m_vecScrollPos;
	BOOL					m_bHandleMouseWheel;
	BOOL					m_bAnimationScroll;
	LONG					m_nScrollStep;

protected:
	HDC						m_hdcScrollCache;
	HBITMAP					m_hBitmapScrollCache;
	LONG					m_nOldScrollCachePos;
	LONG					m_nNewScrollCachePos;
};

class CSkinEditObject;
class CSkinEditViewImpl;
class SKINUI_API CSkinEditView : public CSkinScrollView
{
public:
	CSkinEditView(CSkinView* pParent);
	~CSkinEditView();
	SKINUI_DECLARE_DYNCREATE()

public:
	void InitEditAttribute(const CXMLNode& node);

	void InsertText(const tstring& strText, BOOL bHighlight = FALSE, const tstring& strFontStyle = tstring(), const tstring& strFontColor = tstring());
	void InsertText(const tstring& strText, LONG nAfter, BOOL bHighlight = FALSE, const tstring& strFontStyle = tstring(), const tstring& strFontColor = tstring());
	void AppendText(const tstring& strText, BOOL bHighlight = FALSE, const tstring& strFontStyle = tstring(), const tstring& strFontColor = tstring());

	void InsertImage(const tstring& strImage, BOOL bLButtonDownOpen = FALSE);
	void InsertImage(const tstring& strImage, LONG nAfter, BOOL bLButtonDownOpen = FALSE);
	void AppendImage(const tstring& strImage, BOOL bLButtonDownOpen = FALSE);

	void InsertHyperlink(const tstring& strHyperlink, UINT nCommandId, BOOL bHighlight = FALSE, const tstring& strFontStyle = tstring(), const tstring& strFontColor = tstring());
	void InsertHyperlink(const tstring& strHyperlink, LONG nAfter, UINT nCommandId, BOOL bHighlight = FALSE, const tstring& strFontStyle = tstring(), const tstring& strFontColor = tstring());
	void AppendHyperlink(const tstring& strHyperlink, UINT nCommandId, BOOL bHighlight = FALSE, const tstring& strFontStyle = tstring(), const tstring& strFontColor = tstring());

	void InsertView(CSkinView* pView);
	void InsertView(CSkinView* pView, LONG nAfter);
	void AppendView(CSkinView* pView);

	void InsertXML(const tstring& strXML);
	void InsertXML(const tstring& strXML, LONG nAfter);
	void AppendXML(const tstring& strXML);

public:
	tstring GetXML();
	tstring GetSelectedImage();

	void ResetImageObjectVisibleState();
	void GetAllImage(map<LONG, tstring>& mapImage);
	void GetAllView(map<LONG, CSkinView*>& mapView);
	const vector<CSkinEditObject*>& GetAllEditObject();

public:
	void GetSel(UINT& nBegin, UINT& nEnd);
	void SetSel(UINT nBegin, UINT nEnd);
	void SetSelCount(UINT nSelCount);
	void SetSelNone();
	void SetSelAll();

	void SetCaretPos(LONG nPos);
	void ShowCaret(BOOL bShow);

public:
	CRect GetCaretRect();
	LONG GetCaretPos();
	HDC GetEditBkgDC();

public:
	void SetFontStyle(const tstring& strFontStyle, const tstring& strLinkFontStyle = tstring());
	tstring GetFontStyle();
	tstring GetLinkFontStyle();

	void SetFontColor(const tstring& strFontColor);
	tstring GetFontColor();

	void SetLinkFontColor(const tstring& strFontColor);
	tstring GetLinkFontColor();

	void SetSelFontColor(const tstring& strFontColor);
	tstring GetSelFontColor();

	void SetSelBkgColor(const tstring& strFontColor);
	tstring GetSelBkgColor();

	void SetTipsColor(const tstring& strTipsColor);
	tstring GetTipsColor();

	void SetAutoSelectAll(BOOL bAutoSelectAll);
	BOOL IsAutoSelectAll();

	void SetAllowSelect(BOOL bAllowSelect);
	BOOL IsAllowSelect();

	void SetRedrawEditView(BOOL bRedrawEditView);
	BOOL IsRedrawEditView();

	void SetNotifyTextChange(BOOL bNotifyTextChange);
	BOOL IsNotifyTextChange();

	virtual void SetLimit(LONG nLimit);
	virtual LONG GetLimit();

public:
	virtual void SetReadOnly(BOOL bReadOnly);
	virtual BOOL IsReadOnly();

	virtual void SetMultiLine(BOOL bMultiLine);
	virtual BOOL IsMultiLine();

	virtual void SetUpperCase(BOOL bUpperCase);
	virtual BOOL IsUpperCase();

	virtual void SetLowerCase(BOOL bLowerCase);
	virtual BOOL IsLowerCase();

	virtual void SetPassword(BOOL bPassword);
	virtual BOOL IsPassword();

	virtual void SetNumber(BOOL bNumber);
	virtual BOOL IsNumber();

	virtual void SetLetter(BOOL bLetter);
	virtual BOOL IsLetter();

	virtual void SetEnglishName(BOOL bEnglishName);
	virtual BOOL IsEnglishName();

	virtual void SetEmail(BOOL bEmail);
	virtual BOOL IsEmail();

	virtual void SetMobile(BOOL bMobile);
	virtual BOOL IsMobile();

	virtual void SetPhone(BOOL bPhone);
	virtual BOOL IsPhone();

	virtual void SetRichEdit(BOOL bRichEdit);
	virtual BOOL IsRichEdit();

public:
	virtual void Copy();
	virtual void Cut();
	virtual void Paste();
	virtual void Delete();
	virtual void SelectAll();
	virtual void SaveAs();
	virtual void Clear();

public:
	BOOL IsEmpty();
	BOOL IsSelected();
	BOOL IsSaveAsEnable();
	BOOL IsPasteEnable();

public:
	virtual void InitAttribute(const CXMLNode& node);

	virtual void ResetScrollInfo();
	virtual void SetScrollInfo(const ScrollInfo& info, BOOL bVScroll);

	virtual void SetEnable(BOOL bEnabled);
	virtual CSkinView* HitTest(CPoint& point);

	virtual void SetText(const tstring& strText);
	virtual tstring GetText();

	virtual void SetRect(const CRect& rect);
	virtual CRect GetClientRect();

	virtual CRect GetDropSourceRect();
	virtual void GetWrapContentSize(CSize& size);

	virtual BOOL IsHandleTabKeyDown();
	virtual BOOL IsEditView();

	virtual void DrawBackground(HDC hdc){}
	virtual void DrawForeground(HDC hdc);
	virtual void DrawEditBkg(HDC hdc);
	virtual void DrawEditClient(HDC hdc);
	virtual void DrawDropSource(HDC hdc);

public:
	virtual void HandleMouseEnter();
	virtual void HandleMouseLeave();
	virtual void HandleDragMouseMove(CPoint point);
	virtual void HandleMouseMove(CPoint point, UINT nFlags);

	virtual void HandleLButtonDblClk(CPoint point, BOOL& bHandle);
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void HandleLButtonUp(CPoint point);
	virtual void HandleRButtonDown(CPoint point);
	virtual void HandleRButtonUp(CPoint point, BOOL& bHandle);

	virtual void HandleKeyDown(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);
	virtual void HandleKeyUp(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);
	virtual void HandleChar(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);

	virtual void HandleSetCursor(CPoint& point, BOOL& bHandle);
	virtual void HandlePasteView(const CXMLNode& node);
	virtual void HandleFontSizeChange();

	virtual void HandleDragSourceFinish();
	virtual void HandleDragTargetFinish();
	virtual void HandleInputTextFinish(){}
	virtual void HandleDragFinish();

	virtual void HandleTabKeyDownSetFocus();
	virtual void HandleSetFocus();
	virtual void HandleKillFocus();

protected:
	CSkinEditViewImpl*	m_pEditViewImpl;
	BOOL				m_bLButtonDown;
	BOOL				m_bAutoSelectAll;
	BOOL				m_bLinkUnderline;
	BOOL				m_bRedrawEditView;
	BOOL				m_bNotifyTextChange;
	BOOL				m_bAllowSelect;
	DWORD				m_dwLastRedraw;
	LONG				m_nLimit;

	tstring				m_strTipsColor;
	tstring				m_strFontColor;
	tstring				m_strLinkFontColor;
	tstring				m_strSelFontColor;
	tstring				m_strSelBkgColor;
	tstring				m_strFontStyle;
	tstring				m_strLinkFontStyle;

protected:
	HDC					m_hdcBkg;
	HBITMAP				m_hBitmapBkg;

public:
	static HHOOK		s_hHookMouse;
};

inline void CSkinEditView::SetFontColor(const tstring& strFontColor)
{
	m_strFontColor = strFontColor;
}

inline tstring CSkinEditView::GetFontColor()
{
	return IsEnable() ? m_strFontColor : _T("ID_COLOR_DISABLE");
}

inline void CSkinEditView::SetLinkFontColor(const tstring& strFontColor)
{
	m_strLinkFontColor = strFontColor;
}

inline tstring CSkinEditView::GetLinkFontColor()
{
	return m_strLinkFontColor;
}

inline void CSkinEditView::SetSelFontColor(const tstring& strFontColor)
{
	m_strSelFontColor = strFontColor;
}

inline tstring CSkinEditView::GetSelFontColor()
{
	return m_strSelFontColor;
}

inline void CSkinEditView::SetSelBkgColor(const tstring& strFontColor)
{
	m_strSelBkgColor = strFontColor;
}

inline tstring CSkinEditView::GetSelBkgColor()
{
	return m_strSelBkgColor;
}

inline void CSkinEditView::SetTipsColor(const tstring& strTipsColor)
{
	m_strTipsColor = strTipsColor;
}

inline void CSkinEditView::SetAutoSelectAll(BOOL bAutoSelectAll)
{
	m_bAutoSelectAll = bAutoSelectAll;
}

inline BOOL CSkinEditView::IsAutoSelectAll()
{
	return m_bAutoSelectAll;
}

inline void CSkinEditView::SetAllowSelect(BOOL bAllowSelect)
{
	m_bAllowSelect = bAllowSelect;
}

inline BOOL CSkinEditView::IsAllowSelect()
{
	return m_bAllowSelect;
}

inline void CSkinEditView::SetRedrawEditView(BOOL bRedrawEditView)
{
	m_bRedrawEditView = bRedrawEditView;
}

inline BOOL CSkinEditView::IsRedrawEditView()
{
	return m_bRedrawEditView;
}

inline void CSkinEditView::SetNotifyTextChange(BOOL bNotifyTextChange)
{
	m_bNotifyTextChange = bNotifyTextChange;
}

inline BOOL CSkinEditView::IsNotifyTextChange()
{
	return m_bNotifyTextChange;
}

inline void CSkinEditView::SetLimit(LONG nLimit)
{
	m_nLimit = nLimit;
}

inline LONG CSkinEditView::GetLimit()
{
	return m_nLimit;
}

inline tstring CSkinEditView::GetLinkFontStyle()
{
	return m_strLinkFontStyle.empty() ? m_strFontStyle : m_strLinkFontStyle;
}

inline tstring CSkinEditView::GetFontStyle()
{
	return m_strFontStyle;
}

inline tstring CSkinEditView::GetTipsColor()
{
	return m_strTipsColor;
}

inline HDC CSkinEditView::GetEditBkgDC()
{
	return m_hdcBkg;
}

class SKINUI_API CSkinEditViewEx : public CSkinEditView
{
public:
	CSkinEditViewEx(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void SetFocusSelAll(BOOL bFocusSelAll);
	void SetFocusedColor(const tstring& strColor);
	void SetKillFocusColor(const tstring& strColor);

public:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void DrawForeground(HDC hdc);

	virtual void HandleKeyDown(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void HandleSetFocus();
	virtual void HandleKillFocus();

private:
	tstring		m_strKillFocusColor;
	tstring		m_strFocusedColor;
	BOOL		m_bFocusSelAll;
};

inline void CSkinEditViewEx::SetFocusSelAll(BOOL bFocusSelAll)
{
	m_bFocusSelAll = bFocusSelAll;
}

inline void CSkinEditViewEx::SetFocusedColor(const tstring& strColor)
{
	m_strFocusedColor = strColor;
}

inline void CSkinEditViewEx::SetKillFocusColor(const tstring& strColor)
{
	m_strKillFocusColor = strColor;
}

class SKINUI_API CSkinEditTextView : public CSkinEditView
{
public:
	CSkinEditTextView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void SetEditMode(BOOL bEditMode);

public:
	virtual BOOL IsReadOnly();
	virtual void HandleBuildFinish();
	virtual void SetScrollPos(LONG nPos, BOOL bVScroll);
	virtual void DrawEditBkg(HDC hdc);

private:
	BOOL		m_bEditMode;
};

class SKINUI_API CSkinHotKeyView : public CSkinEditViewEx
{
public:
	CSkinHotKeyView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void SetHotKey(WORD wVirtualKeyCode, WORD wModifiers);
	void GetHotKey(WORD& wVirtualKeyCode, WORD& wModifiers);

public:
	static tstring GetHotKeyText(WORD wVirtualKeyCode, WORD wModifiers);
	tstring GetHotKeyText();

protected:
	virtual void InitAttribute(const CXMLNode& node);

	virtual void HandleMouseMove(CPoint point, UINT nFlags){}
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void HandleLButtonUp(CPoint point){}

	virtual void HandleChar(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle){}
	virtual void HandleKeyDown(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);
	virtual void HandleKeyUp(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);

private:
	BOOL		m_bKeyUpClear;
	WORD		m_wVirtualKeyCode;
	WORD		m_wModifiers;
};

class SKINUI_API CSkinListItem : public CSkinRelativeLayout
{
public:
	CSkinListItem(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	friend class CSkinListView;

public:
	void SetAllowMoveWindow(BOOL bAllow);
	BOOL IsAllowMoveWindow();

	void SetColorChecked(const tstring& strColor);
	tstring GetColorChecked();

	void SetColorMouseOver(const tstring& strColor);
	tstring GetColorMouseOver();

	void SetAllowChecked(BOOL bAllowChecked);
	BOOL IsAllowChecked();

	void SetLazyLoad(BOOL bLazyLoad);
	BOOL IsLazyLoad();

	void SetRectNeedReset();
	BOOL IsRectNeedReset();

public:
	virtual void SetLevel(LONG nLevel);
	virtual LONG GetLevel();

	virtual void SetChecked(BOOL bChecked);
	virtual BOOL IsChecked();

	virtual void SetCheckedState(CheckedState state);
	virtual void SetDisabledState(BOOL bDisabled);
	virtual CheckedState GetCheckedState();
	virtual BOOL IsCheckBoxDisable();

	virtual BOOL IsVisible();
	virtual BOOL IsTreeItem();

public:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void SetLayout(const tstring& strLayout);
	virtual void SetRect(const CRect& rect);
	virtual void DrawForeground(HDC hdc);

public:
	virtual void HandleMouseEnter();
	virtual void HandleMouseLeave();

	virtual void HandleLButtonUp(CPoint point);
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void HandleLButtonDblClk(CPoint point, BOOL& bHandle);
	virtual void HandleRButtonUp(CPoint point, BOOL& bHandle);

	virtual void HandleItemStateChangeToVisible(){}

protected:
	void LazySetLayout();

	void SetCacheNeedUpdate();
	BOOL IsCacheNeedUpdate();

	VisibleState GetVisibleState(const CRect& rcParent, const ScrollInfo& vertInfo, const ScrollInfo& horzInfo);

protected:
	BOOL			m_bChecked;
	BOOL			m_bLazyLoad;
	BOOL			m_bRectNeedReset;
	BOOL			m_bCacheNeedUpdate;
	BOOL			m_bAllowMoveWindow;
	BOOL			m_bAllowChecked;
	LONG			m_nLevel;

	tstring			m_strLayout;
	tstring			m_strColorChecked;
	tstring			m_strColorMouseOver;
	CheckedState	m_CheckedState;
	BOOL			m_bCheckBoxDisable;
};

inline void CSkinListItem::SetRectNeedReset()
{
	m_bRectNeedReset = TRUE;
}

inline BOOL CSkinListItem::IsRectNeedReset()
{
	BOOL bRectNeedReset = m_bRectNeedReset;
	m_bRectNeedReset = FALSE;
	return bRectNeedReset;
}

inline void CSkinListItem::SetCacheNeedUpdate()
{
	m_bCacheNeedUpdate = TRUE;
}

inline BOOL CSkinListItem::IsCacheNeedUpdate()
{
	BOOL bCacheNeedUpdate = m_bCacheNeedUpdate;
	m_bCacheNeedUpdate = FALSE;
	return bCacheNeedUpdate;
}

inline BOOL CSkinListItem::IsTreeItem()
{
	return FALSE;
}

inline void CSkinListItem::SetLevel(LONG nLevel)
{
	m_nLevel = nLevel;
}

inline LONG CSkinListItem::GetLevel()
{
	return m_nLevel;
}

class SKINUI_API CSkinListView : public CSkinScrollView
{
public:
	CSkinListView(CSkinView* pParent);
	~CSkinListView();
	SKINUI_DECLARE_DYNCREATE()

public:
	void MakeSureItemVisible(CSkinListItem* pListItem);
	CSkinListItem* GetChecked();

	void SetEmptyImage(const tstring& strEmptyImage);
	tstring GetEmptyImage();

	void SetEmptyTips(const tstring& strEmptyTips);
	tstring GetEmptyTips();

	void SetAllowCheckItem(BOOL bAllow);
	BOOL IsAllowCheckItem();

	void SetItemSortFunc(SortCompareFunc compare);

public:
	virtual void InitAttribute(const CXMLNode& node);

	virtual void SetRect(const CRect& rect);
	virtual void SetChecked(CSkinListItem* pListItem);

	virtual void HandleKeyDown(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);
	virtual void SetScrollInfo(const ScrollInfo& info, BOOL bVScroll);

	virtual void ResetScrollInfo();
	virtual void ResetScrollCache(LONG nOldPos, LONG nNewPos);

public:
	virtual const list<CSkinView*>& GetVisibleChild();
	virtual BOOL IsItemVisible(CSkinListItem* pListItem);

	virtual CSkinView* GetChildByIndex(UINT nIndex);
	virtual LONG GetChildIndex(CSkinView* pView);
	virtual CSkinView* GetChildById(LONG nId);

	virtual void DrawBackground(HDC hdc){}
	virtual void DrawForeground(HDC hdc);
	virtual void DrawClient(HDC hdc);

protected:
	virtual void GetNewScrollInfo(LONG& nTotalHeight, LONG& nScrollStep);
	virtual void ResetVisibleItem();
	virtual void ResetSortedItem();
	virtual void ResetItemRect();

protected:
	BOOL					m_bAllowCheckItem;
	tstring					m_strEmptyTips;
	tstring					m_strEmptyImage;

private:
	list<CSkinView*>		m_visible;
	list<CSkinView*>		m_lstNotHided;
	SortCompareFunc			m_compareItem;
};

inline void CSkinListView::SetEmptyImage(const tstring& strEmptyImage)
{
	m_strEmptyImage = strEmptyImage;
}

inline tstring CSkinListView::GetEmptyImage()
{
	return m_strEmptyImage;
}

inline void CSkinListView::SetEmptyTips(const tstring& strEmptyTips)
{
	m_strEmptyTips = strEmptyTips;
}

inline tstring CSkinListView::GetEmptyTips()
{
	return m_strEmptyTips;
}

inline void CSkinListView::SetAllowCheckItem(BOOL bAllow)
{
	m_bAllowCheckItem = bAllow;
}

inline BOOL CSkinListView::IsAllowCheckItem()
{
	return m_bAllowCheckItem;
}

inline void CSkinListView::SetItemSortFunc(SortCompareFunc compare)
{
	m_compareItem = compare;
}

class SKINUI_API CSkinGridView : public CSkinListView
{
public:
	CSkinGridView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void SetCellSize(const CSize& size);
	void SetMarginSize(const CSize& size);
	void SetColumnCount(LONG nColumnCount);

public:
	virtual void InitAttribute(const CXMLNode& node);

protected:
	virtual void GetNewScrollInfo(LONG& nTotalHeight, LONG& nScrollStep);
	virtual void ResetItemRect();

protected:
	CRect GetCellRectByIndex(LONG nIndex, const CRect& rcClient, const CSize& szCell);

private:
	CSize	m_szCell;
	CSize	m_szMargin;
	LONG	m_nColumnCount;
};

inline void CSkinGridView::SetCellSize(const CSize& size)
{
	m_szCell = size;
}

inline void CSkinGridView::SetMarginSize(const CSize& size)
{
	m_szMargin = size;
}

inline void CSkinGridView::SetColumnCount(LONG nColumnCount)
{
	m_nColumnCount = nColumnCount;
}

class SKINUI_API CSkinTreeItem : public CSkinListItem
{
public:
	CSkinTreeItem(CSkinView* pParent);
	~CSkinTreeItem();
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void AddItem(CSkinTreeItem* pItem);
	virtual void AddItem(CSkinListItem* pItem);

	virtual void RemoveItem(CSkinListItem* pItem);
	virtual void DeleteItem(CSkinListItem* pItem);
	virtual void DeleteAllItem();

	virtual void GetItem(list<CSkinView*>& lstChild);

public:
	void Expand(BOOL bExpand);
	void ShowChildItem(BOOL bShow);
	void SetTreeItemSortFunc(SortCompareFunc compare);
	void SetListItemSortFunc(SortCompareFunc compare);

public:
	CSkinTreeItem* GetParentItem(CSkinListItem* pItem);
	UINT GetItemCount();
	BOOL IsExpand();

public:
	virtual BOOL IsTreeItem();
	virtual void SetState(ViewState state);
	virtual void SetLevel(LONG nLevel);

	virtual const list<CSkinTreeItem*>& GetChildTreeItem();
	virtual const list<CSkinListItem*>& GetChildListItem();

	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void HandleLButtonDblClk(CPoint point, BOOL& bHandle);
	virtual void HandleBuildFinish();
	virtual void HandleExpandStateChange(BOOL bExpand){}

protected:
	void HandleChildItemCountChange();

protected:
	list<CSkinTreeItem*>	m_lstTreeItem;
	list<CSkinListItem*>	m_lstListItem;
	SortCompareFunc			m_compareTreeItem;
	SortCompareFunc			m_compareListItem;

private:
	BOOL					m_bExpanded;
};

inline BOOL CSkinTreeItem::IsExpand()
{
	return m_bExpanded;
}

inline BOOL CSkinTreeItem::IsTreeItem()
{
	return TRUE;
}

inline const list<CSkinTreeItem*>& CSkinTreeItem::GetChildTreeItem()
{
	return m_lstTreeItem;
}

inline const list<CSkinListItem*>& CSkinTreeItem::GetChildListItem()
{
	return m_lstListItem;
}

inline void CSkinTreeItem::SetTreeItemSortFunc(SortCompareFunc compare)
{
	m_compareTreeItem = compare;
}

inline void CSkinTreeItem::SetListItemSortFunc(SortCompareFunc compare)
{
	m_compareListItem = compare;
}

class CSkinTreeFloatItem;
class SKINUI_API CSkinTreeView : public CSkinListView
{
public:
	CSkinTreeView(CSkinView* pParent);
	~CSkinTreeView();
	SKINUI_DECLARE_DYNCREATE()

public:
	void InsertItem(CSkinTreeItem* pParentItem, CSkinTreeItem* pItem);
	void InsertItem(CSkinTreeItem* pParentItem, CSkinListItem* pItem);
	void ExpandItem(CSkinTreeItem* pItem, BOOL bExpand);

	void RemoveItem(CSkinTreeItem* pParentItem, CSkinListItem* pItem);
	void DeleteItem(CSkinTreeItem* pParentItem, CSkinListItem* pItem);
	void DeleteAllItem();

public:
	const list<CSkinTreeItem*>& GetRootItem();
	CSkinTreeItem* GetParentItem(CSkinListItem* pItem);
	void SetFloatItemLayout(const tstring& strLayout);

public:
	virtual void InitAttribute(const CXMLNode& node);

	virtual void SetChecked(CSkinListItem* pListItem);
	virtual void SetScrollInfo(const ScrollInfo& info, BOOL bVScroll);

	virtual void HandleChildItemCountChange(CSkinTreeItem* pTreeItem){}
	virtual void UpdateTreeFloatItem(CSkinTreeItem* pTreeItem);
	virtual void ResetSortedItem();

protected:
	list<CSkinTreeItem*>	m_lstRootItem;
	CSkinTreeFloatItem*		m_pTreeFloatItem;
};

inline const list<CSkinTreeItem*>& CSkinTreeView::GetRootItem()
{
	return m_lstRootItem;
}

class CSkinCheckTreeView : public CSkinTreeView
{
public:
	CSkinCheckTreeView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void ConfirmCheckState(CSkinTreeItem* pTreeItem);
	void TryChangeItemCheckState(CSkinListItem* pSkinListItem, BOOL bChecked);
	void HandleItemCheckStateChanged(CSkinListItem* pSkinListItem, BOOL bChecked);

protected:
	void ConfirmCheckedAll(CSkinTreeItem* pTreeItem);
	void ConfirmCheckedNone(CSkinTreeItem* pTreeItem);

	void CheckedAll(CSkinTreeItem* pTreeItem);
	void CheckedNone(CSkinTreeItem* pTreeItem);

public:
	virtual void OnCheckStateChanged(CSkinListItem* pSkinListItem, BOOL bChecked){}
	virtual void OnCheckStateChangeFinish(){}
	virtual BOOL IsOverLimit(CSkinListItem* pSkinListItem){ return FALSE; }

protected:
	void OnCheckBoxClicked(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()
};

class CSkinEditObject;
class SKINUI_API CSkinEditListView : public CSkinListView
{
public:
	CSkinEditListView(CSkinView* pParent);

	SKINUI_DECLARE_DYNCREATE()

public:
	virtual BOOL IsEditListView();
	virtual void SetScrollInfo(const ScrollInfo& info, BOOL bVScroll);

	virtual void HandleMouseMove(CPoint point, UINT nFlags);
	virtual void HandleKeyDown(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);
	virtual void HandleLButtonDblClk(CPoint point, BOOL& bHandle);
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void HandleLButtonUp(CPoint point);
	virtual void HandleRButtonDown(CPoint point);

public:
	void SetSelNone();
	void GetAllImage(vector<tstring>& vecImage);

	BOOL IsSelected();
	BOOL IsSaveAsEnable();

	tstring GetSelectedImage();
	CSkinView* GetMenuPopupView();

public:
	void Copy();
	void SelectAll();
	void SaveAs();

protected:
	UINT GetPosFromPoint(const CPoint& point);
	CSkinEditView* HitTestReadOnlyEditView(const CPoint& point);
	CSkinEditObject* HitTestReadOnlyEditObject(const CPoint& point);
	void GetAllReadOnlyEditObject(vector<CSkinEditObject*>& vecEditObject, BOOL bOnlyVisible = FALSE);

	void SetSel(UINT nBegin, UINT nEnd);
	void SetSelCount(UINT nSelCount);

protected:
	void HandleLeftKeyDown();
	void HandleRightKeyDown();
	void HandleSelectAll();
	void HandleCopy();

public:
	void SetTextToClipboard(const vector<CSkinEditObject*>& vecEditObject);
	void SetXMLToClipboard(const vector<CSkinEditObject*>& vecEditObject);

private:
	BOOL					m_bLButtonDown;
	UINT					m_nSelCount;
	UINT					m_nFixedCaretPos;
	UINT					m_nActiveCaretPos;
	set<CSkinEditView*>		m_setEditRedraw;
};

inline BOOL CSkinEditListView::IsEditListView()
{
	return TRUE;
}

class CWebHost;
class SKINUI_API CSkinIEView : public CSkinWndView
{
public:
	CSkinIEView(CSkinView* pParent);
	~CSkinIEView();

	SKINUI_DECLARE_DYNCREATE()
	SKINUI_DECLARE_EXTENSION_MESSAGE_MAP()

public:
	void LoadURL(const tstring& strURL);
	void RunJavaScript(const tstring& strScript);

	HWND GetWebHostHWND();
	tstring GetURL();

public:
	virtual void OnDocumentComplete(){}

protected:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void HandleInitDialogFinish();

private:
	void CreateHost();

private:
	CWebHost*	m_pWebHost;
	tstring		m_strURL;
};

inline tstring CSkinIEView::GetURL()
{
	return m_strURL;
}

class SKINUI_API CSkinCefView : public CSkinView
{
public:
	CSkinCefView(CSkinView* pParent);
	~CSkinCefView();

	SKINUI_DECLARE_DYNCREATE()
	SKINUI_DECLARE_EXTENSION_MESSAGE_MAP()

public:
	static set<CSkinCefView*> s_setWebView;

public:
	void LoadURL(const tstring& strURL);
	void RunJavaScript(const tstring& strScript);
	void SetCheckCaretPos(BOOL bCheckCaretPos);
	void SetAlphaBlend(BOOL bAlphaBlend);

	bool CanGoBack();
	void GoBack();

	bool CanGoForward();
	void GoForward();
	bool IsLoading();

	void Reload();
	void ReloadIgnoreCache();

	void UpdateBrowerCache(const list<CRect>& lstDirty, int nWidth, int nHeight);
	void ReleaseBrowerCache();

	void SetBrowerCursor(HCURSOR hCursorBrower);

	tstring GetURL();

public:
	virtual void InitAttribute(const CXMLNode& node);
	virtual void SetRect(const CRect& rect);
	virtual void DrawForeground(HDC hdc);

protected:
	virtual void HandleVisibleStateChange();
	virtual void HandleSetCursor(CPoint& point, BOOL& bHandle);
	virtual void HandleSetFocus();
	virtual void HandleKillFocus();

protected:
	virtual BOOL IsHandleMouseWheel();
	virtual BOOL IsCefView();

private:
	BOOL GetImeInfo(const list<CRect>& lstDirty, int nWidth, int nHeight, CPoint& ptCaretPos);

private:
	tstring		m_strURL;
	HDC			m_hdcBrower;
	HBITMAP		m_hBitmapBrower;
	BYTE*		m_pBufferBrower;

	HCURSOR		m_hCursorBrower;
	LONG		m_nWidthBrower;
	LONG		m_nHeightBrower;

private:
	CRect		m_rcLastDirty;
	BOOL		m_bImeUpdate;
	BOOL		m_bCheckCaretPos;
	BOOL		m_bAlphaBlend;
};

inline tstring CSkinCefView::GetURL()
{
	return m_strURL;
}

inline void CSkinCefView::SetCheckCaretPos(BOOL bCheckCaretPos)
{
	m_bCheckCaretPos = bCheckCaretPos;
}

inline void CSkinCefView::SetAlphaBlend(BOOL bAlphaBlend)
{
	m_bAlphaBlend = bAlphaBlend;
}

class SKINUI_API CSkinDateView : public CSkinRelativeLayout
{
public:
	enum
	{
		IDC_TEXTVIEW_DATE = 100001,
		IDC_BUTTON_ARROW = 100002,
	};

public:
	CSkinDateView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()
	friend class CSkinDateDialog;

public:
	void SetTimestamp(uint64 nTimestamp);
	void SetMinTimestamp(uint64 nTimestamp);
	void SetMaxTimestamp(uint64 nTimestamp);
	void SetDate(LONG nYear, LONG nMonth, LONG nDay);
	void GetDate(LONG& nYear, LONG& nMonth, LONG& nDay);

public:
	virtual void HandleBuildFinish();
	virtual void HandleMouseEnter();
	virtual void HandleMouseLeave();
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void DrawForeground(HDC hdc);

private:
	LONG				m_nYear;
	LONG				m_nMonth;
	LONG				m_nDay;

	uint64				m_nTimestampMin;
	uint64				m_nTimestampMax;
	CSkinTextView*		m_pTextView;
};

class SKINUI_API CSkinDateDayItem : public CSkinListItem
{
public:
	enum
	{
		IDC_TEXTVIEW_DAY = 100001,
	};

public:
	CSkinDateDayItem(CSkinView* pParent);

public:
	void SetDate(const YearMonthDay& day);
	YearMonthDay GetDay() { return m_day; }

protected:
	virtual void HandleDayChange();
	virtual tstring GetFontColor();

protected:
	YearMonthDay m_day;
};

class SKINUI_API CSkinDateLayout : public CSkinVertPercentLayout
{
public:
	enum
	{
		IDC_BUTTON_LAST_YEAR = 100001,
		IDC_BUTTON_LAST_MONTH = 100002,
		IDC_BUTTON_NEXT_MONTH = 100003,
		IDC_BUTTON_NEXT_YEAR = 100004,
		IDC_TEXTVIEW_DATE = 100005,
		IDC_GRIDVIEW_DAY = 102000,
	};

public:
	CSkinDateLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void HandleBuildFinish();
	virtual void HandleDateBeforeChange(const YearMonthDay& begin, const YearMonthDay& end){}
	virtual CSkinDateDayItem* CreateDateDayItem();

public:
	void SetMinTimestamp(uint64 nTimestamp);
	void SetMaxTimestamp(uint64 nTimestamp);

	void SetDate(uint64 nTimestamp);
	void SetDate(LONG nYear, LONG nMonth, LONG nDay = 0);
	YearMonthDay GetDate() { return m_day; }

protected:
	void OnBtnClickedLastYear(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedLastMonth(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedNextYear(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedNextMonth(UINT uNotifyCode, int nID, CSkinView* pView);

	LRESULT OnListItemCheckedChange(WPARAM wParam, LPARAM lParam);
	SKINUI_DECLARE_MESSAGE_MAP()

protected:
	LONG				m_nYear;
	LONG				m_nMonth;

	LONG				m_nEndYear;
	LONG				m_nStartYear;
	LONG				m_nEndMonth;
	LONG				m_nStartMonth;

	uint64				m_nTimestampMin;
	uint64				m_nTimestampMax;

	YearMonthDay		m_day;

	CSkinGridView*		m_pSkinGridView;
	CSkinButton*		m_pButtonLastYear;
	CSkinButton*		m_pButtonNextYear;
	CSkinButton*		m_pButtonLastMonth;
	CSkinButton*		m_pButtonNextMonth;
};

class SKINUI_API CSkinTimeView : public CSkinRelativeLayout
{
public:
	enum
	{
		IDC_TEXTVIEW_HOUR = 100001,
		IDC_BUTTON_LAST_HOUR = 100002,
		IDC_BUTTON_NEXT_HOUR= 100003,
		IDC_TEXTVIEW_MINUTE = 100011,
		IDC_BUTTON_LAST_MINUTE = 100012,
		IDC_BUTTON_NEXT_MINUTE = 100013,
		IDC_TEXTVIEW_SECOND = 100021,
		IDC_BUTTON_LAST_SECOND = 100022,
		IDC_BUTTON_NEXT_SECOND = 100023,
	};

public:
	CSkinTimeView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void SetTimestamp(uint64 nTimestamp);
	void SetTime(LONG nHour, LONG nMinute, LONG nSecond);
	void GetTime(LONG& nHour, LONG& nMinute, LONG& nSecond);

public:
	virtual void HandleBuildFinish();
	virtual void HandleMouseEnter();
	virtual void HandleMouseLeave();
	virtual void DrawForeground(HDC hdc);

protected:
	void OnBtnClickedLastHour(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedNextHour(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedLastMinute(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedNextMinute(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedLastSecond(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedNextSecond(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	void UpdateHour(LONG nHour);
	void UpdateMinute(LONG nMinute);
	void UpdateSecond(LONG nSecond);

private:
	LONG				m_nHour;
	LONG				m_nMinute;
	LONG				m_nSecond;

	CSkinTextView*		m_pTextViewHour;
	CSkinTextView*		m_pTextViewMinute;
	CSkinTextView*		m_pTextViewSecond;
	CSkinButton*		m_pButtonLastHour;
	CSkinButton*		m_pButtonNextHour;
	CSkinButton*		m_pButtonLastMinute;
	CSkinButton*		m_pButtonNextMinute;
	CSkinButton*		m_pButtonLastSecond;
	CSkinButton*		m_pButtonNextSecond;
};

class SKINUI_API CSkinComboItem : public CSkinListItem
{
public:
	CSkinComboItem(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void HandleMouseEnter();
	virtual void HandleMouseLeave();
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
};

};
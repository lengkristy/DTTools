#pragma once
namespace UI {

class CSkinDialog;
class SKINUI_API CSkinView : public CTimerListener
{
public:
	CSkinView(CSkinView* pParent);
	virtual ~CSkinView();

	SKINUI_DECLARE_DYNCREATE()
	SKINUI_DECLARE_MESSAGE_MAP()

	friend class CRedrawLocker;

public:
	virtual void InitAttribute(const CXMLNode& node);

	virtual void SetId(LONG nId);
	virtual LONG GetId();

	virtual void SetMode(LONG nMode);
	virtual LONG GetMode();

	virtual void SwitchChildMode(LONG nMode);
	virtual LONG GetChildMode();

	virtual void SetCursor(LONG nCursor);
	virtual LONG GetCursor();

	virtual void SetText(const tstring& strText);
	virtual tstring GetText();

	virtual void SetTips(const tstring& strTips);
	virtual tstring GetTips();

	virtual void SetSkinTips(const tstring& strLayout);
	virtual tstring GetSkinTips();

	virtual void SetSkinTipsOffset(const CPoint& point);
	virtual CPoint GetSkinTipsOffset();

	virtual void SetMenu(const tstring& strMenu);
	virtual tstring GetMenu();

	virtual void SetImage(const tstring& strImage);
	virtual tstring GetImage();

	virtual void SetColor(const tstring& strColor);
	virtual tstring GetColor();

	virtual void SetBkgImage(const tstring& strImage);
	virtual tstring GetBkgImage();

	virtual void SetBkgColor(const tstring& strColor);
	virtual tstring GetBkgColor();

	virtual void SetBorderColor(const tstring& strColor);
	virtual tstring GetBorderColor();

	virtual void SetMaxWidth(LONG nMaxWidth);
	virtual LONG GetMaxWidth();

	virtual void SetMinWidth(LONG nMinWidth);
	virtual LONG GetMinWidth();

	virtual void SetMaxHeight(LONG nMaxHeight);
	virtual LONG GetMaxHeight();

	virtual void SetMinHeight(LONG nMaxHeight);
	virtual LONG GetMinHeight();

	virtual void SetLayoutWidth(LONG nLayoutWidth);
	virtual LONG GetLayoutWidth();

	virtual void SetLayoutHeight(LONG nLayoutHeight);
	virtual LONG GetLayoutHeight();

	virtual void SetLayoutMargin(LayoutMargin layoutMargin);
	virtual void SetHorizontalAlignment(HorizontalAlignment horizontalAlignment);
	virtual void SetVerticalAlignment(VerticalAlignment verticalAlignment);

	virtual void SetLayoutToLeftOf(LONG nId, LONG nOffset);
	virtual void SetLayoutToTopOf(LONG nId, LONG nOffset);
	virtual void SetLayoutToRightOf(LONG nId, LONG nOffset);
	virtual void SetLayoutToBottomOf(LONG nId, LONG nOffset);
	virtual void SetLayoutAlignLeftOf(LONG nId, LONG nOffset);
	virtual void SetLayoutAlignTopOf(LONG nId, LONG nOffset);
	virtual void SetLayoutAlignRightOf(LONG nId, LONG nOffset);
	virtual void SetLayoutAlignBottomOf(LONG nId, LONG nOffset);
	virtual void SetLayoutAlignParentLeft(LONG nOffset);
	virtual LONG GetLayoutAlignParentLeft();
	virtual void SetLayoutAlignParentTop(LONG nOffset);
	virtual LONG GetLayoutAlignParentTop();
	virtual void SetLayoutAlignParentRight(LONG nOffset);
	virtual LONG GetLayoutAlignParentRight();
	virtual void SetLayoutAlignParentBottom(LONG nOffset);
	virtual LONG GetLayoutAlignParentBottom();
	virtual void SetLayoutAlignParentHorizontalCenter(LONG nOffset);
	virtual void SetLayoutAlignParentVerticalCenter(LONG nOffset);

	virtual LayoutMargin GetLayoutMargin();
	virtual HorizontalAlignment GetHorizontalAlignment();
	virtual VerticalAlignment GetVerticalAlignment();
	virtual LayoutRelative GetLayoutRelative();

	virtual void SetRect(const CRect& rect);
	virtual CRect GetRect();
	virtual CRect GetClientRect();

	virtual void SetLayout(const tstring& strLayout);

	virtual void SetState(ViewState state);
	virtual ViewState GetState();

	virtual CSkinDialog* GetOwner();
	virtual void SetParent(CSkinView* pParent);
	virtual CSkinView* GetParent();

	virtual void SetChildText(LONG nId, const tstring& strText);
	virtual void SetChildImage(LONG nId, const tstring& strImage);
	virtual void SetChildColor(LONG nId, const tstring& strColor);
	virtual void SetChildFontColor(LONG nId, const tstring& strColor);
	virtual void SetChildFontStyle(LONG nId, const tstring& strStyle);

	virtual void SetRedrawOwner(BOOL bRedrawOwner);
	virtual BOOL IsRedrawOwner();

	virtual void SetRedrawParent(BOOL bRedrawParent);
	virtual BOOL IsRedrawParent();

	virtual void SetRedrawAllChild(BOOL bRedrawAllChild);
	virtual BOOL IsRedrawAllChild();

	virtual void SetAllowLButtonDownCheckListItem(BOOL bAllow);
	virtual BOOL IsAllowLButtonDownCheckListItem();

	virtual void SetAllowGetChild(BOOL bAllow);
	virtual BOOL IsAllowGetChild();

	virtual void SetDrag(const vector<UINT>& vecDrag);
	virtual BOOL IsDrag(UINT nDrag);

	virtual void SetAllowDrag(BOOL bAllow);
	virtual BOOL IsAllowDrag();

	virtual void SetMenuPopup(BOOL bMenuPopup);
	virtual BOOL IsMenuPopup();

	virtual void SetVisible(BOOL bVisible);
	virtual BOOL IsVisible();

	virtual void SetEnable(BOOL bEnabled);
	virtual BOOL IsEnable();

	virtual void SetFocus(BOOL bFocus);
	virtual BOOL IsFocus();

	void SetAttribute(LPARAM pAttribute);
	LPARAM GetAttribute();

	void SetAttribute(const tstring& strKey, const tstring& strValue);
	tstring GetAttribute(const tstring& strKey);

	void SetLongAttribute(const tstring& strKey, LONG nValue);
	LONG GetLongAttribute(const tstring& strKey);

public:
	virtual CPoint GetScrollOffset(CRect& rcScrollClient);
	virtual ScrollInfo GetScrollInfo(BOOL bVScroll);
	virtual void GetWrapContentSize(CSize& size);
	virtual void GetLayoutSize(CSize& size);

public:
	virtual BOOL IsHandleMouseMove();
	virtual BOOL IsHandleMouseWheel();
	virtual BOOL IsHandleTabKeyDown();
	virtual BOOL IsHandleUpdateUI();

	virtual BOOL IsEditListView();
	virtual BOOL IsEditView();
	virtual BOOL IsCefView();
	virtual BOOL IsFloatView();

	virtual BOOL IsDragIng();
	virtual BOOL IsUpdateUI(CSkinView** ppNotifyView);

	virtual HDC GetBkgDC();
	virtual HDC GetMemDC();

public:
	virtual void AddChild(CSkinView* pView);
	virtual void RemoveChild(CSkinView* pView);
	virtual void DeleteChild(CSkinView* pView);
	virtual void DeleteAllChild();

	virtual BOOL IsChild(CSkinView* pView);
	virtual LONG GetChildIndex(CSkinView* pView);
	virtual CSkinView* GetFloatParent();
	virtual CSkinView* GetChildByIndex(UINT nIndex);
	virtual CSkinView* GetChildById(LONG nId);
	virtual const list<CSkinView*>& GetAllChild();
	virtual const list<CSkinView*>& GetVisibleChild();

	virtual CSkinView* HitTest(CPoint& point);
	virtual CSkinView* HitTestDrag(CPoint& point, UINT nDragType);
	virtual CSkinView* HitTestMouseWheel(CPoint& point);

public:
	virtual void HandleBuildFinish();
	virtual void HandleVisibleStateChange();
	virtual void HandleChildDelete(CSkinView* pView);
	virtual void HandleSetCursor(CPoint& point, BOOL& bHandle);

	virtual void HandleMouseEnter();
	virtual void HandleMouseLeave();
	virtual void HandleMouseWheel(LONG nStep);
	virtual void HandleMouseMove(CPoint point, UINT nFlags);
	virtual void HandleDragMouseMove(CPoint point);
	virtual void HandleMouseHover(CPoint point);

	virtual void HandleLButtonUp(CPoint point);
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
	virtual void HandleLButtonDblClk(CPoint point, BOOL& bHandle);
	virtual void HandleRButtonUp(CPoint point, BOOL& bHandle);
	virtual void HandleRButtonDown(CPoint point);

	virtual void HandleKeyDown(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);
	virtual void HandleKeyUp(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);
	virtual void HandleChar(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);

	virtual void HandleBeginDragDrop(){}
	virtual void HandleEndDragDrop(){}
	virtual void HandleDragDrop(CPoint& point);

	virtual void HandleTimer(UINT_PTR nIDEvent){}
	virtual void HandleTabKeyDownSetFocus(){}
	virtual void HandleSetFocus(){}
	virtual void HandleKillFocus(){}

public:
	virtual void DrawBackground(HDC hdc);
	virtual void DrawForeground(HDC hdc);
	virtual void RedrawView(BOOL bUpdateWindow = TRUE);

public:
	BOOL IsLockRedraw();

private:
	void LockRedraw(BOOL bLockRedraw);

protected:
	list<CSkinView*>		m_child;
	ViewState				m_state;
	CRect					m_rect;

private:
	CSkinView*				m_parent;
	CSkinView*				m_mouse;

	LayoutMargin			m_margin;
	HorizontalAlignment		m_horizontalAlignment;
	VerticalAlignment		m_verticalAlignment;
	LayoutRelative			m_relative;
	set<UINT>				m_setDrag;

private:
	LONG					m_nId;
	LONG					m_nMode;
	LONG					m_nCursor;
	LONG					m_nMaxWidth;
	LONG					m_nMinWidth;
	LONG					m_nMaxHeight;
	LONG					m_nMinHeight;
	LONG					m_nLayoutWidth;
	LONG					m_nLayoutHeight;
	LONG					m_nLockRedraw;
	BOOL					m_bAllowDrag;
	BOOL					m_bDragIng;
	BOOL					m_bMenuPopup;
	BOOL					m_bAllowGetChild;
	BOOL					m_bAllowLButtonDownCheckListItem;
	BOOL					m_bRedrawOwner;
	BOOL					m_bRedrawParent;
	BOOL					m_bRedrawAllChild;
	CPoint					m_ptDrag;
	CPoint					m_ptOffset;

	tstring					m_strText;
	tstring					m_strTips;
	tstring					m_strSkinTips;
	tstring					m_strMenu;
	tstring					m_strImage;
	tstring					m_strColor;
	tstring					m_strBkgImage;
	tstring					m_strBkgColor;
	tstring					m_strBorderColor;

	LPARAM					m_pAttribute;
	map<tstring, tstring>	m_mapAttribute;
};

inline void CSkinView::SetId(LONG nId)
{
	m_nId = nId;
}

inline LONG CSkinView::GetId()
{
	return m_nId;
}

inline void CSkinView::SetMode(LONG nMode)
{
	m_nMode = nMode;
}

inline LONG CSkinView::GetMode()
{
	return m_nMode;
}

inline void CSkinView::SetCursor(LONG nCursor)
{
	m_nCursor = nCursor;
}

inline LONG CSkinView::GetCursor()
{
	return m_nCursor;
}

inline void CSkinView::SetMaxWidth(LONG nMaxWidth)
{
	m_nMaxWidth = nMaxWidth;
}

inline LONG CSkinView::GetMaxWidth()
{
	return m_nMaxWidth;
}

inline void CSkinView::SetMinWidth(LONG nMinWidth)
{
	m_nMinWidth = nMinWidth;
}

inline LONG CSkinView::GetMinWidth()
{
	return m_nMinWidth;
}

inline void CSkinView::SetMaxHeight(LONG nMaxHeight)
{
	m_nMaxHeight = nMaxHeight;
}

inline LONG CSkinView::GetMaxHeight()
{
	return m_nMaxHeight;
}

inline void CSkinView::SetMinHeight(LONG nMinHeight)
{
	m_nMinHeight = nMinHeight;
}

inline LONG CSkinView::GetMinHeight()
{
	return m_nMinHeight;
}

inline void CSkinView::SetLayoutWidth(LONG nLayoutWidth)
{
	m_nLayoutWidth = nLayoutWidth;
}

inline LONG CSkinView::GetLayoutWidth()
{
	return m_nLayoutWidth;
}

inline void CSkinView::SetLayoutHeight(LONG nLayoutHeight)
{
	m_nLayoutHeight = nLayoutHeight;
}

inline LONG CSkinView::GetLayoutHeight()
{
	return m_nLayoutHeight;
}

inline void CSkinView::SetText(const tstring& strText)
{
	m_strText = strText;
}

inline tstring CSkinView::GetText()
{
	return m_strText;
}

inline void CSkinView::SetTips(const tstring& strTips)
{
	m_strTips = strTips;
}

inline tstring CSkinView::GetTips()
{
	return m_strTips;
}

inline void CSkinView::SetSkinTips(const tstring& strLayout)
{
	m_strSkinTips = strLayout;
}

inline tstring CSkinView::GetSkinTips()
{
	return m_strSkinTips;
}

inline void CSkinView::SetSkinTipsOffset(const CPoint& point)
{
	m_ptOffset = point;
}

inline CPoint CSkinView::GetSkinTipsOffset()
{
	return m_ptOffset;
}

inline void CSkinView::SetMenu(const tstring& strMenu)
{
	m_strMenu = strMenu;
}

inline tstring CSkinView::GetMenu()
{
	return m_strMenu;
}

inline void CSkinView::SetImage(const tstring& strImage)
{
	m_strImage = strImage;
}

inline tstring CSkinView::GetImage()
{
	return m_strImage;
}

inline void CSkinView::SetColor(const tstring& strColor)
{
	m_strColor = strColor;
}

inline tstring CSkinView::GetColor()
{
	return m_strColor;
}

inline void CSkinView::SetBkgImage(const tstring& strImage)
{
	m_strBkgImage = strImage;
}

inline tstring CSkinView::GetBkgImage()
{
	return m_strBkgImage;
}

inline void CSkinView::SetBkgColor(const tstring& strColor)
{
	m_strBkgColor = strColor;
}

inline tstring CSkinView::GetBkgColor()
{
	return m_strBkgColor;
}

inline void CSkinView::SetBorderColor(const tstring& strColor)
{
	m_strBorderColor = strColor;
}

inline tstring CSkinView::GetBorderColor()
{
	return m_strBorderColor;
}

inline LPARAM CSkinView::GetAttribute()
{
	return m_pAttribute;
}

inline void CSkinView::SetAttribute(LPARAM pAttribute)
{
	m_pAttribute = pAttribute;
}

inline void CSkinView::SetAttribute(const tstring& strKey, const tstring& strValue)
{
	m_mapAttribute[strKey] = strValue;
}

inline tstring CSkinView::GetAttribute(const tstring& strKey)
{
	map<tstring, tstring>::iterator iter = m_mapAttribute.find(strKey);
	if(iter != m_mapAttribute.end())
	{
		return iter->second;
	}
	return tstring();
}

inline void CSkinView::SetLongAttribute(const tstring& strKey, LONG nValue)
{
	m_mapAttribute[strKey] = SkinUI::IntToString(nValue);
}

inline LONG CSkinView::GetLongAttribute(const tstring& strKey)
{
	map<tstring, tstring>::iterator iter = m_mapAttribute.find(strKey);
	if(iter != m_mapAttribute.end())
	{
		return SkinUI::StringToLong(iter->second);
	}
	return 0;
}

inline BOOL CSkinView::IsHandleMouseWheel()
{
	return FALSE;
}

inline BOOL CSkinView::IsHandleTabKeyDown()
{
	return FALSE;
}

inline BOOL CSkinView::IsHandleUpdateUI()
{
	return FALSE;
}

inline BOOL CSkinView::IsEditListView()
{
	return FALSE;
}

inline BOOL CSkinView::IsCefView()
{
	return FALSE;
}

inline BOOL CSkinView::IsEditView()
{
	return FALSE;
}

inline ScrollInfo CSkinView::GetScrollInfo(BOOL bVScroll)
{
	return ScrollInfo();
}

typedef bool (*SortCompareFunc)(CSkinView* pView1, CSkinView* pView2);
};
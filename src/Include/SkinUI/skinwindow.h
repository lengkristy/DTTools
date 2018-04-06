#pragma once
namespace UI {

class SKINUI_API CSkinWindow : public CSkinRelativeLayout
{
public:
	CSkinWindow(CSkinView* pParent);
	virtual ~CSkinWindow();

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg)
	{
		return FALSE;
	}

	virtual BOOL OnPreMessage(uint nMsg, WPARAM wParam, LPARAM lParam)
	{
		return FALSE;
	}

	virtual void RedrawView(BOOL bUpdateWindow = TRUE)
	{
	
	}

	virtual void OnIdle()
	{
	
	}

public:
	BOOL IsWindow()
	{
		assert(m_hWnd);
		return ::IsWindow(m_hWnd);
	}

	BOOL IsIconic()
	{
		assert(m_hWnd);
		return ::IsIconic(m_hWnd);
	}

	BOOL IsZoomed()
	{
		assert(m_hWnd);
		return ::IsZoomed(m_hWnd);
	}

	BOOL IsWindowEnabled()
	{
		assert(m_hWnd);
		return ::IsWindowEnabled(m_hWnd);
	}

	BOOL IsWindowVisible()
	{
		assert(m_hWnd);
		return ::IsWindowVisible(m_hWnd);
	}

	BOOL GetWindowRect(CRect& rect)
	{
		assert(m_hWnd);
		return ::GetWindowRect(m_hWnd, &rect);
	}

	BOOL SetWindowText(LPCTSTR lpszString)
	{
		assert(m_hWnd);
		return ::SetWindowText(m_hWnd, lpszString);
	}

	BOOL UpdateWindow()
	{
		assert(m_hWnd);
		if(GetStyleEx() & WS_EX_LAYERED)
		{
			return SendMessage(WM_PAINT) == 1L;
		}
		else
		{
			InvalidateRect(m_hWnd, &GetRect(), FALSE);
			return ::UpdateWindow(m_hWnd);
		}
	}

	BOOL CenterWindow();

	BOOL DestroyWindow()
	{
		assert(m_hWnd);
		return ::DestroyWindow(m_hWnd);
	}

	BOOL ShowWindow(int nCmdShow)
	{
		assert(m_hWnd);
		return ::ShowWindow(m_hWnd, nCmdShow);
	}


	BOOL EnableWindow(BOOL bEnabled)
	{
		assert(m_hWnd);
		return ::EnableWindow(m_hWnd, bEnabled);
	}

	BOOL FlashWindow(BOOL bFlash)
	{
		FLASHWINFO info;
		if(bFlash)
		{
			info.uCount = -1;
			info.dwTimeout = 0;
			info.hwnd = m_hWnd;
			info.cbSize = sizeof(FLASHWINFO);
			info.dwFlags = FLASHW_ALL | FLASHW_TIMER;
		}
		else
		{
			info.uCount = 0;
			info.dwTimeout = 0;
			info.hwnd = m_hWnd;
			info.cbSize = sizeof(FLASHWINFO);
			info.dwFlags = FLASHW_STOP;
		}
		return FlashWindowEx(&info);
	}

	BOOL ClientToScreen(CRect& rect)
	{
		assert(m_hWnd);
		CPoint pointLeftTop(rect.left, rect.top);
		CPoint pointRightBottom(rect.right, rect.bottom);
		if(::ClientToScreen(m_hWnd, &pointLeftTop) && ::ClientToScreen(m_hWnd, &pointRightBottom))
		{
			rect.left = pointLeftTop.x;
			rect.top = pointLeftTop.y;
			rect.right = pointRightBottom.x;
			rect.bottom = pointRightBottom.y;
			return TRUE;
		}
		return FALSE;
	}

	BOOL ClientToScreen(CPoint& point)
	{
		assert(m_hWnd);
		return ::ClientToScreen(m_hWnd, &point);
	}

	BOOL ScreenToClient(CRect& rect)
	{
		assert(m_hWnd);
		CPoint pointLeftTop(rect.left, rect.top);
		CPoint pointRightBottom(rect.right, rect.bottom);
		if(::ScreenToClient(m_hWnd, &pointLeftTop) && ::ScreenToClient(m_hWnd, &pointRightBottom))
		{
			rect.left = pointLeftTop.x;
			rect.top = pointLeftTop.y;
			rect.right = pointRightBottom.x;
			rect.bottom = pointRightBottom.y;
			return TRUE;
		}
		return FALSE;
	}

	BOOL ScreenToClient(CPoint& point)
	{
		assert(m_hWnd);
		return ::ScreenToClient(m_hWnd, &point);
	}

	BOOL MoveWindow(const CRect& rect)
	{
		assert(m_hWnd);
		return ::MoveWindow(m_hWnd, rect.left, rect.top, rect.Width(), rect.Height(), TRUE);
	}

	BOOL SetWindowPos(HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags)
	{
		assert(m_hWnd);
		return ::SetWindowPos(m_hWnd, hWndInsertAfter, X, Y, cx, cy, uFlags);
	}

	BOOL KillTimer(UINT nId)
	{
		assert(m_hWnd);
		return ::KillTimer(m_hWnd, nId);
	}

	UINT_PTR SetTimer(UINT nId, UINT uElapse, TIMERPROC lpTimerFunc = NULL)
	{
		assert(m_hWnd);
		return ::SetTimer(m_hWnd, nId, uElapse, lpTimerFunc);
	}

	HDC GetDC()
	{
		assert(m_hWnd);
		return ::GetDC(m_hWnd);
	}

	int ReleaseDC(HDC hDC)
	{
		assert(m_hWnd);
		return ::ReleaseDC(m_hWnd, hDC);
	}

	int SetWindowRgn(HRGN hRgn, BOOL bRedraw)
	{
		assert(m_hWnd);
		return ::SetWindowRgn(m_hWnd, hRgn, bRedraw);
	}

	LONG GetStyle()
	{
		assert(m_hWnd);
		return GetWindowLong(GWL_STYLE);
	}

	LONG GetStyleEx()
	{
		assert(m_hWnd);
		return GetWindowLong(GWL_EXSTYLE);
	}

	LONG GetWindowLong(int nIndex)
	{
		assert(m_hWnd);
		return ::GetWindowLong(m_hWnd, nIndex);
	}

	LONG ModifyStyle(DWORD dwRemove, DWORD dwAdd)
	{
		assert(m_hWnd);
		LONG dwNewLong = GetStyle();
		dwNewLong |= dwRemove;
		dwNewLong ^= dwRemove;
		dwNewLong |= dwAdd;
		return SetWindowLong(m_hWnd, GWL_STYLE, dwNewLong);
	}

	LONG ModifyStyleEx(DWORD dwRemove, DWORD dwAdd)
	{
		assert(m_hWnd);
		LONG dwNewLong = GetStyleEx();
		dwNewLong |= dwRemove;
		dwNewLong ^= dwRemove;
		dwNewLong |= dwAdd;
		return SetWindowLong(m_hWnd, GWL_EXSTYLE, dwNewLong);
	}

	void TrackMouseEvent(DWORD dwFlag, DWORD dwTime)
	{
		TRACKMOUSEEVENT trackMouseEvent = { 0 };
		trackMouseEvent.cbSize = sizeof(trackMouseEvent);
		trackMouseEvent.dwFlags = dwFlag;
		trackMouseEvent.dwHoverTime = dwTime;
		trackMouseEvent.hwndTrack = m_hWnd;
		::TrackMouseEvent(&trackMouseEvent);
	}

	LRESULT SetIcon(HICON hIcon, BOOL bBigIcon)
	{
		assert(m_hWnd);
		return SendMessage(WM_SETICON, bBigIcon ? ICON_BIG : ICON_SMALL, (LPARAM)hIcon);
	}

	HICON GetIcon(BOOL bBigIcon)
	{
		assert(m_hWnd);
		return (HICON)SendMessage(WM_GETICON, bBigIcon ? ICON_BIG : ICON_SMALL, NULL);
	}

	HWND GetHWND()
	{
		return m_hWnd;
	}

	BOOL OpenClipboard()
	{
		return ::OpenClipboard(m_hWnd);
	}

	HWND SetActiveWindow()
	{
		assert(m_hWnd);
		return ::SetActiveWindow(m_hWnd);
	}

	void SetForegroundWindow()
	{
		if(IsIconic())
		{
			ShowWindow(SW_RESTORE);
		}
		else
		{
			ShowWindow(SW_SHOW);
		}

		::SetForegroundWindow(GetHWND());
		::SetFocus(GetHWND());
	}

	HWND SetFocus()
	{
		assert(m_hWnd);
		return ::SetFocus(m_hWnd);
	}

	BOOL PostMessage(uint nMsg, WPARAM wParam = NULL, LPARAM lParam = NULL)
	{
		assert(m_hWnd);
		return ::PostMessage(m_hWnd, nMsg, wParam, lParam);
	}

	LRESULT SendMessage(uint nMsg, WPARAM wParam = NULL, LPARAM lParam = NULL)
	{
		assert(m_hWnd);
		return ::SendMessage(m_hWnd, nMsg, wParam, lParam);
	}

public:
	static CSkinWindow* FromHandle(HWND hWnd);
	static map<HWND, CSkinWindow*> s_mapWndHost;

public:
	LRESULT WindowProc(uint nMsg, WPARAM wParam, LPARAM lParam);
	BOOL OnSkinUIMessage(uint nMsg, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	BOOL OnMessage(uint nMsg, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	BOOL OnUpdateCommandUI(WPARAM wParam, LPARAM lParam);
	BOOL OnCommandRange(WPARAM wParam, LPARAM lParam);
	BOOL OnCommand(WPARAM wParam, LPARAM lParam);

public:
	void UpdateAreo();
	void OpenAreo(BOOL bOpen);

	virtual CRect GetAreoRect();
	virtual void HandleSkinChange(){}
	virtual void HandleFontSizeChange(){}

protected:
	HWND m_hWnd;
	HWND m_hWndParent;
	BOOL m_bOpenAreo;
};

void inline CSkinWindow::OpenAreo(BOOL bOpen)
{
	m_bOpenAreo = bOpen;
}

};
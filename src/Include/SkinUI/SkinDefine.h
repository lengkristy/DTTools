#pragma once
#pragma warning(disable:4251)
#pragma warning(disable:4275)

#define SKINUI_API __declspec(dllexport)
#define WIN32_LEAN_AND_MEAN                     // Exclude rarely-used stuff from Windows headers
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

#ifndef WINVER                          // Specifies that the minimum required platform is Windows Vista.
#define WINVER 0x0600           // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT            // Specifies that the minimum required platform is Windows Vista.
#define _WIN32_WINNT 0x0600     // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINDOWS          // Specifies that the minimum required platform is Windows 98.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE                       // Specifies that the minimum required platform is Internet Explorer 7.0.
#define _WIN32_IE 0x0700        // Change this to the appropriate value to target other versions of IE.
#endif

#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

//基本类型定义
#ifndef tstring
	#define tstring				wstring
#endif
#ifndef int64
	typedef __int64				int64;
#endif
#ifndef uint64
	typedef unsigned __int64	uint64;
#endif
#ifndef uint32
	typedef unsigned __int32	uint32;
#endif
#ifndef uint
	typedef unsigned int		uint;
#endif

namespace UI {

//系统配置项
#define SYS_CONFIG_DIALOG_SHADOW_PATCH						_T("DialogShadowPatch")
#define SYS_CONFIG_DIALOG_BORDER_COLOR						_T("DialogBorderColor")
#define SYS_CONFIG_DIALOG_RADIUS							_T("DialogRadius")
#define SYS_CONFIG_DIALOG_TITLE_HEIGHT						_T("DialogTitleHeight")
#define SYS_CONFIG_DIALOG_CAPTION_FONT_STYLE				_T("DialogCaptionFontStyle")
#define SYS_CONFIG_DIALOG_CAPTION_ALIGNMENT					_T("DialogCaptionAlignment")
#define SYS_CONFIG_DIALOG_SYSBUTTON_TOP_OFFSET				_T("DialogSysButtonTopOffset")
#define SYS_CONFIG_DIALOG_SYSBUTTON_RIGHT_OFFSET			_T("DialogSysButtonRightOffset")
#define SYS_CONFIG_DIALOG_BKG_BOTTOM_COLOR					_T("DialogBkgBottomColor")
#define SYS_CONFIG_DIALOG_BKG_LINE_COLOR					_T("DialogBkgLineColor")
#define SYS_CONFIG_MENU_MIN_WIDTH							_T("MenuMinWidth")
#define SYS_CONFIG_MENU_ITEM_HEIGHT							_T("MenuItemHeight")
#define SYS_CONFIG_MENU_SEPARATOR_HEIGHT					_T("MenuSeparatorHeight")
#define SYS_CONFIG_MENU_ITEM_BKG_IMAGE						_T("MenuItemBkgImage")
#define SYS_CONFIG_MENU_ITEM_HOT_BKG_COLOR					_T("MenuItemHotBkgColor")
#define SYS_CONFIG_MENU_ITEM_HOT_TEXT_COLOR					_T("MenuItemHotTextColor")
#define SYS_CONFIG_FULL_TRANSPARENT_SKIN					_T("FullTransparentSkin")
#define SYS_CONFIG_MORE_SKIN_URL							_T("MoreSkinURL")
#define SYS_CONFIG_CEF_EXTERNAL								_T("CefExternal")
#define SYS_CONFIG_SELECTED_MASK							_T("SelectedMask")

//应用配置项
#define APP_CONFIG_CUR_SKIN									_T("CurSkin")
#define APP_CONFIG_OPEN_AREO								_T("OpenAreo")
#define APP_CONFIG_WINDOW_ALPHA								_T("WindowAlpha")
#define APP_CONFIG_WHITE_BKG_ALPHA							_T("WhiteBkgAlpha")
#define APP_CONFIG_FONT_SIZE_CHANGE							_T("FontSizeChange")
#define APP_CONFIG_STRING_LANGUAGE							_T("StringLanguage")

//SkinDiaolog
#define SKINUI_ATTRIBUTE_RESIZE								_T("Resize")
#define SKINUI_ATTRIBUTE_ALLOW_MOVE							_T("AllowMove")
#define SKINUI_ATTRIBUTE_MINWIDTH							_T("MinWidth")
#define SKINUI_ATTRIBUTE_MINHEIGHT							_T("MinHeight")
#define SKINUI_ATTRIBUTE_DEFAULTWIDTH						_T("DefaultWidth")
#define SKINUI_ATTRIBUTE_DEFAULTHEIGHT						_T("DefaultHeight")
#define SKINUI_ATTRIBUTE_TITLEHEIGHT						_T("TitleHeight")
#define SKINUI_ATTRIBUTE_THEMEHEIGHT						_T("ThemeHeight")
#define SKINUI_ATTRIBUTE_CAPTION							_T("Caption")
#define SKINUI_ATTRIBUTE_SYSBUTTON							_T("SysButton")
#define SKINUI_ATTRIBUTE_OPEN_AREO							_T("OpenAreo")
#define SKINUI_ATTRIBUTE_TRAY_MENU							_T("TrayMenu")
#define SKINUI_ATTRIBUTE_SKIN								_T("Skin")
#define SKINUI_ATTRIBUTE_ICON								_T("Icon")

//SkinAnimation
#define SKINUI_ATTRIBUTE_ELAPSE								_T("Elapse")
#define SKINUI_ATTRIBUTE_ANIMATION							_T("Animation")
#define SKINUI_ATTRIBUTE_FIXEDPOINT							_T("FixedPoint")

//SkinView
#define SKINUI_ATTRIBUTE_ID									_T("Id")
#define SKINUI_ATTRIBUTE_TEXT								_T("Text")
#define SKINUI_ATTRIBUTE_TIPS								_T("Tips")
#define SKINUI_ATTRIBUTE_SKIN_TIPS							_T("SkinTips")
#define SKINUI_ATTRIBUTE_SKIN_TIPS_OFFSET					_T("SkinTipsOffset")
#define SKINUI_ATTRIBUTE_ALLOW_GET_CHILD					_T("AllowGetChild")
#define SKINUI_ATTRIBUTE_ALLOW_LBUTTON_DOWN_CHECK_LISTITEM	_T("AllowLButtonDownCheckListItem")
#define SKINUI_ATTRIBUTE_VISIBLE							_T("Visible")
#define SKINUI_ATTRIBUTE_ENABLE								_T("Enable")
#define SKINUI_ATTRIBUTE_FOCUSED							_T("Focused")
#define SKINUI_ATTRIBUTE_IMAGE								_T("Image")
#define SKINUI_ATTRIBUTE_COLOR								_T("Color")
#define SKINUI_ATTRIBUTE_BORDER								_T("Border")
#define SKINUI_ATTRIBUTE_BKGIMAGE							_T("BkgImage")
#define SKINUI_ATTRIBUTE_BKGCOLOR							_T("BkgColor")
#define SKINUI_ATTRIBUTE_MENU								_T("Menu")
#define SKINUI_ATTRIBUTE_MAXWIDTH							_T("MaxWidth")
#define SKINUI_ATTRIBUTE_MAXHEIGHT							_T("MaxHeight")
#define SKINUI_ATTRIBUTE_MODE								_T("Mode")
#define SKINUI_ATTRIBUTE_DRAG								_T("Drag")
#define SKINUI_ATTRIBUTE_ALLOW_DRAG							_T("AllowDrag")
#define SKINUI_ATTRIBUTE_MARGIN								_T("Margin")
#define SKINUI_ATTRIBUTE_CURSOR								_T("Cursor")
#define SKINUI_ATTRIBUTE_REDRAWOWNER						_T("RedrawOwner")
#define SKINUI_ATTRIBUTE_REDRAWPARENT						_T("RedrawParent")
#define SKINUI_ATTRIBUTE_REDRAWALLCHILD						_T("RedrawAllChild")
#define SKINUI_ATTRIBUTE_LAYOUT								_T("Layout")
#define SKINUI_ATTRIBUTE_LAYOUTWIDTH						_T("LayoutWidth")
#define SKINUI_ATTRIBUTE_LAYOUTHEIGHT						_T("LayoutHeight")
#define SKINUI_ATTRIBUTE_HORZALIGNMENT						_T("HorzAlignment")
#define SKINUI_ATTRIBUTE_VERTALIGNMENT						_T("VertAlignment")
#define SKINUI_ATTRIBUTE_TOLEFTOF							_T("ToLeftOf")
#define SKINUI_ATTRIBUTE_TOTOPOF							_T("ToTopOf")
#define SKINUI_ATTRIBUTE_TORIGHTOF							_T("ToRightOf")
#define SKINUI_ATTRIBUTE_TOBOTTOMOF							_T("ToBottomOf")
#define SKINUI_ATTRIBUTE_ALIGNLEFTOF						_T("AlignLeftOf")
#define SKINUI_ATTRIBUTE_ALIGNTOPOF							_T("AlignTopOf")
#define SKINUI_ATTRIBUTE_ALIGNRIGHTOF						_T("AlignRightOf")
#define SKINUI_ATTRIBUTE_ALIGNBOTTOMOF						_T("AlignBottomOf")
#define SKINUI_ATTRIBUTE_ALIGNPARENTLEFT					_T("AlignParentLeft")
#define SKINUI_ATTRIBUTE_ALIGNPARENTTOP						_T("AlignParentTop")
#define SKINUI_ATTRIBUTE_ALIGNPARENTRIGHT					_T("AlignParentRight")
#define SKINUI_ATTRIBUTE_ALIGNPARENTBOTTOM					_T("AlignParentBottom")
#define SKINUI_ATTRIBUTE_ALIGNPARENTHORIZONTALCENTER		_T("AlignParentHorizontalCenter")
#define SKINUI_ATTRIBUTE_ALIGNPARENTVERTICALCENTER			_T("AlignParentVerticalCenter")

//SkinComboBox
#define SKINUI_ATTRIBUTE_OPTIONTEXT							_T("OptionText")
#define SKINUI_ATTRIBUTE_LISTMAXHEIGHT						_T("ListMaxHeight")
#define SKINUI_ATTRIBUTE_DEFAULT_TEXT						_T("DefaultText")
#define SKINUI_ATTRIBUTE_CURSEL								_T("CurSel")

//SkinLine
#define SKINUI_ATTRIBUTE_DASHSTYLE							_T("DashStyle")
#define SKINUI_ATTRIBUTE_STARTCOLOR							_T("StartColor")
#define SKINUI_ATTRIBUTE_ENDCOLOR							_T("EndColor")

//SkinProgress SkinSlider
#define SKINUI_ATTRIBUTE_RANGE								_T("Range")
#define SKINUI_ATTRIBUTE_POS								_T("Pos")

//ScrollArrow
#define SKINUI_ATTRIBUTE_DIRECTION							_T("Direction")

//SkinSlider
#define SKINUI_ATTRIBUTE_THUMBIMAGE							_T("ThumbImage")

//SkinSplitter
#define SKINUI_ATTRIBUTE_HORZSPLITTER						_T("HorzSplitter")
#define SKINUI_ATTRIBUTE_MIN								_T("Min")
#define SKINUI_ATTRIBUTE_MAX								_T("Max")

//SkinEditView
#define SKINUI_ATTRIBUTE_RICHEDIT							_T("RichEdit")
#define SKINUI_ATTRIBUTE_MULTILINE							_T("MultiLine")
#define SKINUI_ATTRIBUTE_UPPERCASE							_T("UpperCase")
#define SKINUI_ATTRIBUTE_LOWERCASE							_T("LowerCase")
#define SKINUI_ATTRIBUTE_PASSWORD							_T("Password")
#define SKINUI_ATTRIBUTE_READONLY							_T("ReadOnly")
#define SKINUI_ATTRIBUTE_NUMBER								_T("Number")
#define SKINUI_ATTRIBUTE_TIPS_COLOR							_T("TipsColor")
#define SKINUI_ATTRIBUTE_LIMIT								_T("Limit")
#define SKINUI_ATTRIBUTE_AUTO_SELECT_ALL					_T("AutoSelectAll")
#define SKINUI_ATTRIBUTE_REDRAW_EDIT_VIEW					_T("RedrawEditView")
#define SKINUI_ATTRIBUTE_FOCUSED_COLOR						_T("FocusedColor")
#define SKINUI_ATTRIBUTE_KILLFOCUS_COLOR					_T("KillFocusColor")
#define SKINUI_ATTRIBUTE_ENGLISHNAME						_T("EnglishName")
#define SKINUI_ATTRIBUTE_LETTER								_T("Letter")
#define SKINUI_ATTRIBUTE_EMAIL								_T("Email")
#define SKINUI_ATTRIBUTE_MOBILE								_T("Mobile")
#define SKINUI_ATTRIBUTE_PHONE								_T("Phone")

//SkinTextView
#define SKINUI_ATTRIBUTE_FONTCOLOR							_T("FontColor")
#define SKINUI_ATTRIBUTE_FONTSTYLE							_T("FontStyle")
#define SKINUI_ATTRIBUTE_AUTOLAYOUT							_T("AutoLayout")

//SkinImageView
#define SKINUI_ATTRIBUTE_AUTOPLAY							_T("AutoPlay")
#define SKINUI_ATTRIBUTE_CLICKABLE							_T("ClickAble")

//SkinButton
#define SKINUI_ATTRIBUTE_PRESSDOWNOFFSET					_T("PressDownOffset")
#define SKINUI_ATTRIBUTE_MOUSEOVEROFFSET					_T("MouseOverOffset")

//SkinHyperlink
#define SKINUI_ATTRIBUTE_HOTFONTSTYLE						_T("HotFontStyle")
#define SKINUI_ATTRIBUTE_HOTFONTCOLOR						_T("HotFontColor")
#define SKINUI_ATTRIBUTE_URL								_T("URL")

//CSkinRadioGroup
#define SKINUI_ATTRIBUTE_ALLOWNOCHECKED						_T("AllowNoChecked")

//CSkinRadioButton
#define SKINUI_ATTRIBUTE_BINDVIEW							_T("BindView")
#define SKINUI_ATTRIBUTE_CHECKED							_T("Checked")

//SkinScrollView
#define SKINUI_ATTRIBUTE_VSCROLLBAR							_T("VScrollBar")
#define SKINUI_ATTRIBUTE_HSCROLLBAR							_T("HScrollBar")
#define SKINUI_ATTRIBUTE_MOUSE_WHEEL						_T("MouseWheel")
#define SKINUI_ATTRIBUTE_ANIMATION_SCROLL					_T("AnimationScroll")
#define SKINUI_ATTRIBUTE_SCROLL_STEP						_T("ScrollStep")

//SkinListItem
#define SKINUI_ATTRIBUTE_LAZY_LOAD							_T("LazyLoad")
#define SKINUI_ATTRIBUTE_ALLOWMOVEWINDOW					_T("AllowMoveWindow")
#define SKINUI_ATTRIBUTE_ALLOWCHECKED						_T("AllowChecked")
#define SKINUI_ATTRIBUTE_COLORCHECKED						_T("ColorChecked")
#define SKINUI_ATTRIBUTE_COLORMOUSEOVER						_T("ColorMouseOver")

//SkinListView
#define SKINUI_ATTRIBUTE_ALLOW_CHECK_ITEM					_T("AllowCheckItem")
#define SKINUI_ATTRIBUTE_EMPTY_IMAGE						_T("EmptyImage")
#define SKINUI_ATTRIBUTE_EMPTY_TIPS							_T("EmptyTips")

//SkinTreeView
#define SKINUI_ATTRIBUTE_FLOAT_ITEM_LAYOUT					_T("FloatItemLayout")

//SkinGridView
#define SKINUI_ATTRIBUTE_COLUMN_COUNT						_T("ColumnCount")
#define SKINUI_ATTRIBUTE_CELL_SIZE							_T("CellSize")
#define SKINUI_ATTRIBUTE_MARGIN_SIZE						_T("MarginSize")

//SkinFloatLayout
#define SKINUI_ATTRIBUTE_LBUTTONDOWN_HIDED					_T("LButtonDownHided")
#define SKINUI_ATTRIBUTE_TRANSPARENT						_T("Transparent")

//SkinCefView
#define SKINUI_ATTRIBUTE_QUERY_KEY							_T("key")
#define SKINUI_ATTRIBUTE_QUERY_DATA							_T("data")
#define SKINUI_ATTRIBUTE_QUERY_CALLBACK						_T("callback")
#define SKINUI_ATTRIBUTE_CHECK_CARET_POS					_T("CheckCaretPos")
#define SKINUI_ATTRIBUTE_ALPHA_BLEND						_T("AlphaBlend")

//SkinTimeView
#define SKINUI_ATTRIBUTE_INCLUDE_SECOND						_T("IncludeSecond")

//窗口动画
#define SKINUI_DIALOG_ANIMATION_SIZECHANGE					_T("SizeChange")
#define SKINUI_DIALOG_ANIMATION_LEFTRIGHTEXPAND				_T("LeftRightExpand")
#define SKINUI_DIALOG_ANIMATION_TOPBOTTOMEXPAND				_T("TopBottomExpand")

//切换动画
#define SKINUI_SWITCH_ANIMATION_LEFTRIGHTSLIDE				_T("LeftRightSlide")
#define SKINUI_SWITCH_ANIMATION_TOPBOTTOMSLIDE				_T("TopBottomSlide")

//隐藏动画
#define SKINUI_HIDE_ANIMATION_LEFTRIGHTHIDE					_T("LeftRightHide")
#define SKINUI_HIDE_ANIMATION_TOPBOTTOMHIDE					_T("TopBottomHide")

//圆角位置&弹出方向
#define SKINUI_LEFT_TOP										_T("LeftTop")
#define SKINUI_RIGHT_TOP									_T("RightTop")
#define SKINUI_LEFT_BOTTOM									_T("LeftBottom")
#define SKINUI_RIGHT_BOTTOM									_T("RightBottom")

//系统托盘ID
#define ID_SYSTEMTRAY             10000

//光标ID定义
#define ID_CURSOR_SEARCH          30000
#define ID_CURSOR_ARROW           32512
#define ID_CURSOR_IBEAM           32513
#define ID_CURSOR_WAIT            32514
#define ID_CURSOR_CROSS           32515
#define ID_CURSOR_UPARROW         32516
#define ID_CURSOR_SIZE            32640  /* OBSOLETE: use IDC_SIZEALL */
#define ID_CURSOR_ICON            32641  /* OBSOLETE: use IDC_ARROW */
#define ID_CURSOR_SIZENWSE        32642
#define ID_CURSOR_SIZENESW        32643
#define ID_CURSOR_SIZEWE          32644
#define ID_CURSOR_SIZENS          32645
#define ID_CURSOR_SIZEALL         32646
#define ID_CURSOR_NO              32648 /*not in win3.1 */
#if(WINVER >= 0x0500)
#define ID_CURSOR_HAND            32649
#endif /* WINVER >= 0x0500 */
#define ID_CURSOR_APPSTARTING     32650 /*not in win3.1 */
#if(WINVER >= 0x0400)
#define ID_CURSOR_HELP            32651
#endif /* WINVER >= 0x0400 */

//控件ID定义
#define IDC_SCROLL_SLIDER         100001
#define IDC_SCROLL_THUMB          100002

#define IDC_MENU_LIST             100001
#define IDC_MENU_TEXT             100002
#define IDC_MENU_ICON             100003
#define IDC_MENU_MASK             100004
#define IDC_MENU_ARROW            100005

#define IDC_COMBO_EDIT            100001
#define IDC_COMBO_ARROW           100002
#define IDC_COMBO_LIST            100002
#define IDC_COMBO_TEXT            100003
#define IDC_COMBO_CLOSE           100004

#define IDC_MSGBOX_TEXTVIEW       100001
#define IDC_MSGBOX_CHECKBOX       100002
#define IDC_MSGBOX_EDITVIEW       100003

#define IDC_TIPS_TEXTVIEW         100001

#define IDC_TREEITEM_EXPAND       100001
#define IDC_TREEITEM_CAPTION      100002
#define IDC_LISTITEM_CHECKBOX     100003

#define START_YEAR                1971
#define END_YEAR                  2050
#define START_MONTH               1
#define END_MONTH                 12
#define START_DAY                 1
#define END_DAY                   31
#define START_HOUR                0
#define END_HOUR                  23
#define START_MINUTE              0
#define END_MINUTE                59
#define START_SECOND              0
#define END_SECOND                59

#define ES_LETTER                 0x0001L
#define ES_EMAIL                  0x0002L
#define ES_MOBILE                 0x0004L
#define ES_PHONE                  0x0008L
#define ES_ENGLISHNAME            0x0010L

//编辑框菜单ID
enum
{
	ID_CUT = 11001,
	ID_COPY = 11002,
	ID_PASTE = 11003,
	ID_DELETE = 11004,
	ID_SELECT_ALL = 11005,
	ID_SAVE_AS = 11006,
};

//资源类型
enum ResType
{
	RT_FILE = 0,				//文件资源
	RT_FILE_PACKAGE,			//文件资源包
	RT_RC_PACKAGE,				//RC资源包
};

//视图状态
enum ViewState
{
	VS_NORMAL = 0,				//普通状态
	VS_MOUSE_OVER,				//悬停状态
	VS_PRESS_DOWN,				//按下状态
	VS_DISABLE,					//禁用状态
	VS_HIDED,					//隐藏状态
};

//可视状态
enum VisibleState
{
	VS_INVISIBLE = 0,			//不可见状态
	VS_PART_VISIBLE,			//部分可见状态
	VS_FULL_VISIBLE,			//完全可见状态
};

//选中状态
enum CheckedState
{
	CS_UNCHECKED = 0,			//未选中状态
	CS_CHECKED,					//完全选中状态
	CS_PART_CHECKED,			//部分选中状态
};

//Toast Icon类型
enum
{
	TOAST_ICON_NONE = -1,
	TOAST_ICON_SUCCESS = 0,
	TOAST_ICON_ERROR = 1,
};

//弹出方向
enum PopupDirection
{
	PD_UNKNOWN = 0x0000,		//自适应
	PD_LEFT_TOP = 0x0001,		//左上弹出
	PD_RIGHT_TOP = 0x0002,		//右上弹出
	PD_LEFT_BOTTOM = 0x0004,	//左下弹出
	PD_RIGHT_BOTTOM = 0x0008	//右下弹出
};

//滚动条箭头方向
enum ArrowDirection
{
	AD_TOP = 0,					//向上的箭头
	AD_BOTTOM,					//向下的箭头
	AD_LEFT,					//向左的箭头
	AD_RIGHT,					//向右的箭头
};

//视图宽度和高度
enum
{
	WRAP_CONTENT = -1,			//仅仅包含自己
	FILL_PARENT = -2,			//跟父视图一致
};

//系统控件ID定义
enum
{
	IDC_CHILD_CTRL_BASE = 100000,
	IDC_SYS_BUTTON_CLOSE = 110000,
	IDC_SYS_BUTTON_MAX,
	IDC_SYS_BUTTON_RESTORE,
	IDC_SYS_BUTTON_MIN,
	IDC_SYS_BUTTON_SKIN,
	IDC_SYS_BUTTON_TOPMOST,
	IDC_SYS_BUTTON_NOTOPMOST,
	IDC_SYS_BUTTON_MENU,
	IDC_SYS_BUTTON_FEED,
	IDC_SYS_BUTTON_HELP,
	IDC_SYS_ICON,
	IDC_SYS_CAPTION,
	IDC_CHECKBOX_LISTITEM,
};

//滚动方式
enum ScrollType
{
	ST_STEP = 0,	//滚一步
	ST_PAGE,		//滚一页
	ST_POS,			//滚到特定位置
};

//圆角方向
enum RoundDirection
{
	RD_LEFT_TOP = 0x0001,		//左上圆角
	RD_RIGHT_TOP = 0x0002,		//右上圆角
	RD_LEFT_BOTTOM = 0x0004,	//左下圆角
	RD_RIGHT_BOTTOM = 0x0008,	//右下圆角
	ROUND_ALL = RD_LEFT_TOP | RD_RIGHT_TOP | RD_LEFT_BOTTOM | RD_RIGHT_BOTTOM,
};

//系统消息定义
enum
{
	WM_SYSTEMTRAY = WM_USER + 1,
	WM_INITDIALOG_FINISH,
	WM_END_MSG_BOX_RESULT,
	WM_BEGIN_DO_MODAL,
	WM_END_DO_MODAL,
	WM_ACTIVE_MODAL_DIALOG,
	WM_FAST_TIMER,
	WM_VIEW_IMAGE,
	WM_IE_QUERY_MESSAGE,
	WM_CEF_QUERY_MESSAGE,

	WM_SKINUI_BEGIN = WM_USER + 1000,
	WM_SKINUI_DROP_BITMAP,
	WM_SKINUI_DROP_FILES,
	WM_SKINUI_DROP_TEXT,
	WM_SKINUI_DROP_VIEW,
	WM_SKINUI_SWITCH_ANIMATION_FINISH,
	WM_SKINUI_SLIDE_ANIMATION_FINISH,
	WM_SKINUI_COMBOBOX_SEL_CHANGE,
	WM_SKINUI_COMBOBOX_CLOSE_ITEM,
	WM_SKINUI_RADIO_GROUP_CHECKED_CHANGE,
	WM_SKINUI_CHECKBOX_STATE_CHANGE,
	WM_SKINUI_HOT_KEY_CHANGE,
	WM_SKINUI_EDIT_TEXT_CHANGE,
	WM_SKINUI_SLIDER_POS_CHANGE,
	WM_SKINUI_SPLITTER_POS_CHANGE,
	WM_SKINUI_DATE_CHANGE,
	WM_SKINUI_LIST_ITEM_CHECKED_CHANGE,
	WM_SKINUI_LIST_ITEM_LBUTTON_DBLCLK,
	WM_SKINUI_CEF_LOAD_START,
	WM_SKINUI_CEF_LOAD_END,
	WM_SKINUI_CEF_LOAD_ERROR,
	WM_SKINUI_CEF_TITLE_CHANGE,
	WM_SKINUI_EDIT_SET_FOCUS,
	WM_SKINUI_EDIT_KILL_FOCUS,
	WM_SKINUI_SCROLL_TOP,
	WM_SKINUI_SCROLL_BOTTOM,
	WM_SKINUI_END = WM_USER + 1100,

	WM_SPY_WINDOW = WM_USER + 10000,
	WM_ACTIVE_INSTANCE,
	WM_SPY_CLEAR,
};

//系统消息定义
enum
{
	COPYDATA_SPY_WINDOW = 1000,
	COPYDATA_CREATE_CEF_HOST = 1001,
	COPYDATA_MOUSE_MOVE_EVENT = 1002,
	COPYDATA_MOUSE_WHEEL_EVENT = 1003,
	COPYDATA_MOUSE_CLICK_EVENT = 1004,
	COPYDATA_KEY_EVENT = 1005,
	COPYDATA_CAPTURE_LOST_EVENT = 1006,
	COPYDATA_FOCUS_EVENT = 1007,
	COPYDATA_LOAD_URL = 1008,
	COPYDATA_RUN_JAVASCRIPT = 1009,
	COPYDATA_SET_RECT = 1010,
	COPYDATA_CLOSE_CEF_HOST = 1011,
	COPYDATA_VISIBLE_EVENT = 1012,
	COPYDATA_CAN_GO_BACK = 1013,
	COPYDATA_GO_BACK = 1014,
	COPYDATA_CAN_GO_FORWARD = 1015,
	COPYDATA_GO_FORWARD = 1016,
	COPYDATA_IS_LOADING = 1017,
	COPYDATA_RELOAD = 1018,
	COPYDATA_RELOAD_IGNORE_CACHE = 1019,
	COPYDATA_SET_CEF_HOST_HWND = 2001,
	COPYDATA_REDRAW_WEB_VIEW = 2002,
	COPYDATA_SET_CURSOR = 2003,
	COPYDATA_MESSAGE_QUERY = 2004,
	COPYDATA_LOAD_START = 2005,
	COPYDATA_LOAD_END = 2006,
	COPYDATA_LOAD_ERROR = 2007,
	COPYDATA_TITLE_CHANGE = 2008,
};

//水平对齐方式
enum HorizontalAlignment
{
	HA_LEFT = 0,
	HA_RIGHT,
	HA_CENTER,
};

//垂直对齐方式
enum VerticalAlignment
{
	VA_TOP = 0,
	VA_BOTTOM,
	VA_CENTER,
};

//布局对齐方式
struct LayoutAlignment
{
	HorizontalAlignment horizontalAlignment;
	VerticalAlignment verticalAlignment;

	LayoutAlignment()
	{
		this->horizontalAlignment = HA_CENTER;
		this->verticalAlignment = VA_CENTER;
	}

	LayoutAlignment(HorizontalAlignment horizontalAlignment, VerticalAlignment verticalAlignment)
	{
		this->horizontalAlignment = horizontalAlignment;
		this->verticalAlignment = verticalAlignment;
	}
};

//布局间距
struct LayoutMargin
{
	LONG left;
	LONG top;
	LONG right;
	LONG bottom;

	LayoutMargin()
	{
		this->left = 0;
		this->top = 0;
		this->right = 0;
		this->bottom = 0;
	}

	LayoutMargin(LONG left, LONG top, LONG right, LONG bottom)
	{
		this->left = left;
		this->top = top;
		this->right = right;
		this->bottom = bottom;
	}
};

//相对布局类型
enum LayoutRelativeType
{
	LRT_TO_LEFT_OF = 0,
	LRT_TO_TOP_OF,
	LRT_TO_RIGHT_OF,
	LRT_TO_BOTTOM_OF,
	LRT_ALIGN_LEFT_OF,
	LRT_ALIGN_TOP_OF,
	LRT_ALIGN_RIGHT_OF,
	LRT_ALIGN_BOTTOM_OF,
	LRT_ALIGN_PARENT_LEFT,
	LRT_ALIGN_PARENT_TOP,
	LRT_ALIGN_PARENT_RIGHT,
	LRT_ALIGN_PARENT_BOTTOM,
	LRT_ALIGN_PARENT_HORIZONTAL_CENTER,
	LRT_ALIGN_PARENT_VERTICAL_CENTER,
};

//相对布局
struct LayoutRelative
{
	map<LayoutRelativeType, pair<LONG, LONG>> mapLayoutRelative;

	void SetLayoutRelative(LayoutRelativeType type, LONG nOffset)
	{
		mapLayoutRelative[type] = make_pair(0, nOffset);
	}

	LONG GetLayoutRelative(LayoutRelativeType type)
	{
		map<LayoutRelativeType, pair<LONG, LONG>>::iterator iter = mapLayoutRelative.find(type);
		if(iter != mapLayoutRelative.end())
		{
			return iter->second.second;
		}
		assert(false);
		return 0;
	}

	void SetLayoutRelative(LayoutRelativeType type, LONG nId, LONG nOffset)
	{
		mapLayoutRelative[type] = make_pair(nId, nOffset);
	}

	void GetLayoutRelative(LayoutRelativeType type, LONG& nId, LONG& nOffset)
	{
		map<LayoutRelativeType, pair<LONG, LONG>>::iterator iter = mapLayoutRelative.find(type);
		if(iter != mapLayoutRelative.end())
		{
			nId = iter->second.first;
			nOffset = iter->second.second;
		}
		assert(false);
	}
};

//滚动条信息
struct ScrollInfo
{
	LONG nMax;
	LONG nPage;
	LONG nStep;
	LONG nPos;
	ScrollInfo() : nMax(0), nPage(0), nStep(0), nPos(0){}
};

//字符格式
struct CharFormat
{
	BOOL bBold;
	BOOL bItalic;
	BOOL bUnderline;
	BOOL bStrikeout;
	BOOL bFixedSize;

	LONG size;
	tstring family;

	CharFormat() : size(10), bBold(FALSE), bItalic(FALSE), bUnderline(FALSE), bStrikeout(FALSE), bFixedSize(FALSE){}
};

//九宫格信息
struct CPatch
{
	LONG left;
	LONG top;
	LONG right;
	LONG bottom;

	CPatch()
	{
		this->left = 7;
		this->top = 7;
		this->right = 7;
		this->bottom = 7;
	}

	CPatch(LONG left, LONG top, LONG right, LONG bottom)
	{
		this->left = left;
		this->top = top;
		this->right = right;
		this->bottom = bottom;
	}
};

//资源包信息
#pragma pack(1)
struct ResHead
{
	uint32 unMagic;
	uint32 unHeadSize;
	uint32 unMetaSize;
	uint32 unResSize;
	uint32 aReserved[50];
};
#pragma pack()

//资源包信息
struct YearMonthDay
{
	LONG nYear;
	LONG nMonth;
	LONG nDay;
	BOOL bInRange;
	BOOL bCurMonth;
	YearMonthDay()
	{
		nYear = 0;
		nMonth = 0;
		nDay = 0;
		bInRange = TRUE;
		bCurMonth = FALSE;
	}

	YearMonthDay(LONG nYear, LONG nMonth)
	{
		nYear = nYear;
		nMonth = nMonth;
		nDay = 0;
		bInRange = TRUE;
		bCurMonth = FALSE;
	}
};

class CPoint;class CRect;
class CSize : public SIZE
{
public:
	CSize()
	{
		cx = 0;
		cy = 0;
	}

	CSize(int initCX, int initCY)
	{
		cx = initCX;
		cy = initCY;
	}

	CSize(SIZE initSize)
	{
		*(SIZE*)this = initSize;
	}

	CSize(POINT initPt)
	{
		*(POINT*)this = initPt;
	}

	CSize(DWORD dwSize)
	{
		cx = (short)LOWORD(dwSize);
		cy = (short)HIWORD(dwSize);
	}

	BOOL operator ==(SIZE size) const
	{
		return (cx == size.cx && cy == size.cy);
	}

	BOOL operator !=(SIZE size) const
	{
		return (cx != size.cx || cy != size.cy);
	}

	void operator +=(SIZE size)
	{
		cx += size.cx;
		cy += size.cy;
	}

	void operator -=(SIZE size)
	{
		cx -= size.cx;
		cy -= size.cy;
	}

	void SetSize(int CX, int CY)
	{
		cx = CX;
		cy = CY;
	}

	CSize operator +(SIZE size) const
	{
		return CSize(cx + size.cx, cy + size.cy);
	}

	CSize operator -(SIZE size) const
	{
		return CSize(cx - size.cx, cy - size.cy);
	}

	CSize operator -() const
	{
		return CSize(-cx, -cy);
	}

	CPoint operator +(POINT point) const;
	CPoint operator -(POINT point) const;
	CRect operator +(const RECT* lpRect) const;
	CRect operator -(const RECT* lpRect) const;
};

class CPoint : public POINT
{
public:
	CPoint()
	{
		x = 0;
		y = 0;
	}

	CPoint(int initX, int initY)
	{
		x = initX;
		y = initY;
	}

	CPoint(POINT initPt)
	{
		*(POINT*)this = initPt;
	}

	CPoint(SIZE initSize)
	{
		*(SIZE*)this = initSize;
	}

	CPoint(DWORD dwPoint)
	{
		x = (short)LOWORD(dwPoint);
		y = (short)HIWORD(dwPoint);
	}

	void Offset(int xOffset, int yOffset)
	{
		x += xOffset;
		y += yOffset;
	}

	void Offset(POINT point)
	{
		x += point.x;
		y += point.y;
	}

	void Offset(SIZE size)
	{
		x += size.cx;
		y += size.cy;
	}

	BOOL operator ==(POINT point) const
	{
		return (x == point.x && y == point.y);
	}

	BOOL operator !=(POINT point) const
	{
		return (x != point.x || y != point.y);
	}

	void operator +=(SIZE size)
	{
		x += size.cx;
		y += size.cy;
	}

	void operator -=(SIZE size)
	{
		x -= size.cx;
		y -= size.cy;
	}

	void operator +=(POINT point)
	{
		x += point.x;
		y += point.y;
	}

	void operator -=(POINT point)
	{
		x -= point.x;
		y -= point.y;
	}

	void SetPoint(int X, int Y)
	{
		x = X;
		y = Y;
	}

	CPoint operator +(SIZE size) const
	{
		return CPoint(x + size.cx, y + size.cy);
	}

	CPoint operator -(SIZE size) const
	{
		return CPoint(x - size.cx, y - size.cy);
	}

	CPoint operator -() const
	{
		return CPoint(-x, -y);
	}

	CPoint operator +(POINT point) const
	{
		return CPoint(x + point.x, y + point.y);
	}

	CSize operator -(POINT point) const
	{
		return CSize(x - point.x, y - point.y);
	}

	CRect operator +(const RECT* lpRect) const;
	CRect operator -(const RECT* lpRect) const;
};

class CRect : public RECT
{
public:
	CRect()
	{
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}

	CRect(int l, int t, int r, int b)
	{
		left = l;
		top = t;
		right = r;
		bottom = b;
	}

	CRect(const RECT& srcRect)
	{
		::CopyRect(this, &srcRect);
	}

	CRect(LPCRECT lpSrcRect)
	{
		::CopyRect(this, lpSrcRect);
	}

	CRect(POINT point, SIZE size)
	{
		right = (left = point.x) + size.cx;
		bottom = (top = point.y) + size.cy;
	}

	CRect(POINT topLeft, POINT bottomRight)
	{
		left = topLeft.x;
		top = topLeft.y;
		right = bottomRight.x;
		bottom = bottomRight.y;
	}

	int Width() const
	{
		return right - left;
	}

	int Height() const
	{
		return bottom - top;
	}

	CSize Size() const
	{
		return CSize(right - left, bottom - top);
	}

	CPoint& TopLeft()
	{
		return *((CPoint*)this);
	}

	CPoint& BottomRight()
	{
		return *((CPoint*)this + 1);
	}

	const CPoint& TopLeft() const
	{
		return *((CPoint*)this);
	}

	const CPoint& BottomRight() const
	{
		return *((CPoint*)this + 1);
	}

	CPoint CenterPoint() const
	{
		return CPoint((left + right) / 2, (top + bottom) / 2);
	}

	operator LPRECT()
	{
		return this;
	}

	operator LPCRECT() const
	{
		return this;
	}

	BOOL IsRectEmpty() const
	{
		return ::IsRectEmpty(this);
	}

	BOOL IsRectNull() const
	{
		return (left == 0 && right == 0 && top == 0 && bottom == 0);
	}

	BOOL PtInRect(POINT point) const
	{
		return ::PtInRect(this, point);
	}

	void SetRect(int x1, int y1, int x2, int y2)
	{
		::SetRect(this, x1, y1, x2, y2);
	}

	void SetRect(POINT topLeft, POINT bottomRight)
	{
		::SetRect(this, topLeft.x, topLeft.y, bottomRight.x, bottomRight.y);
	}

	void SetRectEmpty()
	{
		::SetRectEmpty(this);
	}

	void CopyRect(LPCRECT lpSrcRect)
	{
		::CopyRect(this, lpSrcRect);
	}

	BOOL EqualRect(LPCRECT lpRect) const
	{
		return ::EqualRect(this, lpRect);
	}

	void InflateRect(int x, int y)
	{
		::InflateRect(this, x, y);
	}

	void InflateRect(SIZE size)
	{
		::InflateRect(this, size.cx, size.cy);
	}

	void InflateRect(LPCRECT lpRect)
	{
		left -= lpRect->left;
		top -= lpRect->top;
		right += lpRect->right;
		bottom += lpRect->bottom;
	}

	void InflateRect(int l, int t, int r, int b)
	{
		left -= l;
		top -= t;
		right += r;
		bottom += b;
	}

	void DeflateRect(int x, int y)
	{
		::InflateRect(this, -x, -y);
	}

	void DeflateRect(SIZE size)
	{
		::InflateRect(this, -size.cx, -size.cy);
	}

	void DeflateRect(LPCRECT lpRect)
	{
		left += lpRect->left;
		top += lpRect->top;
		right -= lpRect->right;
		bottom -= lpRect->bottom;
	}

	void DeflateRect(int l, int t, int r, int b)
	{
		left += l;
		top += t;
		right -= r;
		bottom -= b;
	}

	void OffsetRect(int x, int y)
	{
		::OffsetRect(this, x, y);
	}
	void OffsetRect(SIZE size)
	{
		::OffsetRect(this, size.cx, size.cy);
	}

	void OffsetRect(POINT point)
	{
		::OffsetRect(this, point.x, point.y);
	}

	void NormalizeRect()
	{
		int nTemp;
		if (left > right)
		{
			nTemp = left;
			left = right;
			right = nTemp;
		}
		if (top > bottom)
		{
			nTemp = top;
			top = bottom;
			bottom = nTemp;
		}
	}

	void MoveToY(int y)
	{
		bottom = Height() + y;
		top = y;
	}

	void MoveToX(int x)
	{
		right = Width() + x;
		left = x;
	}

	void MoveToXY(int x, int y)
	{
		MoveToX(x);
		MoveToY(y);
	}

	void MoveToXY(POINT pt)
	{
		MoveToX(pt.x);
		MoveToY(pt.y);
	}

	BOOL IntersectRect(LPCRECT lpRect1, LPCRECT lpRect2)
	{
		return ::IntersectRect(this, lpRect1, lpRect2);
	}

	BOOL UnionRect(LPCRECT lpRect1, LPCRECT lpRect2)
	{
		return ::UnionRect(this, lpRect1, lpRect2);
	}

	BOOL SubtractRect(LPCRECT lpRectSrc1, LPCRECT lpRectSrc2)
	{
		return ::SubtractRect(this, lpRectSrc1, lpRectSrc2);
	}

	void operator =(const RECT& srcRect)
	{
		::CopyRect(this, &srcRect);
	}

	BOOL operator ==(const RECT& rect) const
	{
		return ::EqualRect(this, &rect);
	}

	BOOL operator !=(const RECT& rect) const
	{
		return !::EqualRect(this, &rect);
	}

	void operator +=(POINT point)
	{
		::OffsetRect(this, point.x, point.y);
	}

	void operator +=(SIZE size)
	{
		::OffsetRect(this, size.cx, size.cy);
	}

	void operator +=(LPCRECT lpRect)
	{
		InflateRect(lpRect);
	}

	void operator -=(POINT point)
	{
		::OffsetRect(this, -point.x, -point.y);
	}

	void operator -=(SIZE size)
	{
		::OffsetRect(this, -size.cx, -size.cy);
	}

	void operator -=(LPCRECT lpRect)
	{
		DeflateRect(lpRect);
	}

	void operator &=(const RECT& rect)
	{
		::IntersectRect(this, this, &rect);
	}

	void operator |=(const RECT& rect)
	{
		::UnionRect(this, this, &rect);
	}

	CRect operator +(POINT pt) const
	{
		CRect rect(*this);
		::OffsetRect(&rect, pt.x, pt.y);
		return rect;
	}

	CRect operator -(POINT pt) const
	{
		CRect rect(*this);
		::OffsetRect(&rect, -pt.x, -pt.y);
		return rect;
	}

	CRect operator +(LPCRECT lpRect) const
	{
		CRect rect(this);
		rect.InflateRect(lpRect);
		return rect;
	}

	CRect operator +(SIZE size) const
	{
		CRect rect(*this);
		::OffsetRect(&rect, size.cx, size.cy);
		return rect;
	}

	CRect operator -(SIZE size) const
	{
		CRect rect(*this);
		::OffsetRect(&rect, -size.cx, -size.cy);
		return rect;
	}

	CRect operator -(LPCRECT lpRect) const
	{
		CRect rect(this);
		rect.DeflateRect(lpRect);
		return rect;
	}

	CRect operator &(const RECT& rect2) const
	{
		CRect rect;
		::IntersectRect(&rect, this, &rect2);
		return rect;
	}

	CRect operator |(const RECT& rect2) const
	{
		CRect rect;
		::UnionRect(&rect, this, &rect2);
		return rect;
	}

	CRect MulDiv(int nMultiplier, int nDivisor) const
	{
		return CRect(
			::MulDiv(left, nMultiplier, nDivisor),
			::MulDiv(top, nMultiplier, nDivisor),
			::MulDiv(right, nMultiplier, nDivisor),
			::MulDiv(bottom, nMultiplier, nDivisor));
	}
};

inline CPoint CSize::operator +(POINT point) const
{ return CPoint(cx + point.x, cy + point.y); }

inline CPoint CSize::operator -(POINT point) const
{ return CPoint(cx - point.x, cy - point.y); }

inline CRect CSize::operator +(const RECT* lpRect) const
{ return CRect(lpRect) + *this; }

inline CRect CSize::operator -(const RECT* lpRect) const
{ return CRect(lpRect) - *this; }

inline CRect CPoint::operator +(const RECT* lpRect) const
{ return CRect(lpRect) + *this; }

inline CRect CPoint::operator -(const RECT* lpRect) const
{ return CRect(lpRect) - *this; }

struct CMonitor
{
	CRect rcMonitor;
	CRect rcWork;
};

struct CSkin
{
	tstring name;
	CPoint start;
	Color color;
};
#define RES_PACKAGE_TYPE		_T("SKIN")
#define ID_RES_PACKAGE_SKINUI	10000
#define ID_RES_PACKAGE_MODULE	10001
#define RES_FILE_MAGIC			0x12733721
#define RES_FILE_VER			1
static const LPTSTR s_lpstrAllFileFilter = _T("所有文件(*.*)\0*.*\0\0");
static const LPTSTR s_lpstrAllPicFilter = _T("图片文件(*.bmp;*.jpg;*.jpeg;*.gif;*.tif;*.tiff;*.png;*.ico)\0*.bmp;*.jpg;*.jpeg;*.gif;*.tif;*.tiff;*.png;*.ico\0位图文件(*.bmp)\0*.bmp\0jpeg 文件(*.jpg;*.jpeg)\0*.jpg;*.jpeg\0gif 文件(*.gif)\0*.gif\0tiff 文件(*.tif;*.tiff)\0*.tif;*.tiff\0png 文件(*.png)\0*.png\0图标文件(*.ico)\0*.ico||\0\0");
static const LPTSTR s_lpstrSkinFilter = _T("皮肤文件(*.syls)\0*.syls\0\0");

class CTimerListener;
struct TimerId
{
public:
	UINT_PTR nIDEvent;
	CTimerListener* pTimerListener;
	TimerId(CTimerListener* pTimerListener, UINT_PTR nIDEvent)
	{
		s_setTimerId.insert(this);
		this->pTimerListener = pTimerListener;
		this->nIDEvent = nIDEvent;
	}

	~TimerId()
	{
		set<TimerId*>::iterator iter = s_setTimerId.find(this);
		if(iter != s_setTimerId.end())
		{
			s_setTimerId.erase(iter);
		}
	}

public:
	static BOOL IsExist(TimerId* pTimerId);
	static set<TimerId*> s_setTimerId;
};

class CTimerListener
{
public:
	CTimerListener();
	virtual ~CTimerListener();

public:
	void SetTimer(UINT_PTR nIDEvent = 0, UINT nElapse = 10);
	void KillTimer(UINT_PTR nIDEvent = 0);

public:
	virtual void HandleTimer(UINT_PTR nIDEvent) = 0;

protected:
	map<UINT_PTR, UINT_PTR>		m_mapId;
	map<UINT_PTR, TimerId*>		m_mapTimerId;
};

class CFastTimerListener : public CTimerListener
{
public:
	CFastTimerListener();

public:
	void SetTimer(UINT_PTR nIDEvent = 0, UINT nElapse = 10);
	void KillTimer(UINT_PTR nIDEvent = 0);

private:
	UINT	m_wPeriod;
};

class CXMLNode
{
public:
	void SetName(const tstring& strName)
	{
		m_strName = strName;
	}

	void SetValue(const tstring& strValue)
	{
		m_strValue = strValue;
	}

	void SetAttribute(const tstring& strKey, const tstring& strValue)
	{
		m_mapAttribute[strKey] = strValue;
	}

	void AddChildNode(const CXMLNode& node)
	{
		m_vecChildNode.push_back(node);
	}

	void AddChildNode(const tstring& strName, const tstring& strValue)
	{
		CXMLNode node;
		node.SetName(strName);
		node.SetValue(strValue);
		m_vecChildNode.push_back(node);
	}

public:
	const tstring& GetName() const
	{
		return m_strName;
	}

	const tstring& GetValue() const
	{
		return m_strValue;
	}

	const vector<CXMLNode>& GetChildNode() const
	{
		return m_vecChildNode;
	}

	vector<CXMLNode>& GetChildNode()
	{
		return m_vecChildNode;
	}

	size_t GetChildCount() const
	{
		return m_vecChildNode.size();
	}

	const map<tstring, tstring>& GetAttribute() const
	{
		return m_mapAttribute;
	}

	tstring GetAttribute(const tstring& strKey) const
	{
		map<tstring, tstring>::const_iterator iter = m_mapAttribute.find(strKey);
		if(iter != m_mapAttribute.end())
		{
			return iter->second;
		}
		else
		{
			return tstring();
		}
	}

	BOOL GetAttribute(const tstring& strKey, tstring& strValue) const
	{
		map<tstring, tstring>::const_iterator iter = m_mapAttribute.find(strKey);
		if(iter != m_mapAttribute.end())
		{
			strValue = iter->second;
			return TRUE;
		}
		else
		{
			strValue = tstring();
			return FALSE;
		}
	}

private:
	tstring					m_strName;			//节点名
	tstring					m_strValue;			//节点值
	map<tstring, tstring>	m_mapAttribute;		//节点属性
	vector<CXMLNode>		m_vecChildNode;		//子节点
};


class JsonValue;
class JsonObject
{
public:
	void AddChild(const tstring& key, const int& value);

	void AddChild(const tstring& key, const uint& value);

	void AddChild(const tstring& key, const uint64& value);

	void AddChild(const tstring& key, const bool& value);

	void AddChild(const tstring& key, const double& value);

	void AddChild(const tstring& key, const tstring& value);

	void AddChild(const tstring& key, const TCHAR* value);

	void AddChild(const tstring& key, const JsonObject& value);

	void AddChild(const tstring& key, const list<JsonValue>& value);

	void AddChild(const tstring& key, const JsonValue& value);

public:
	bool GetValue(const tstring& key, int& value) const;

	bool GetValue(const tstring& key, uint& value) const;

	bool GetValue(const tstring& key, uint64& value) const;

	bool GetValue(const tstring& key, bool& value) const;

	bool GetValue(const tstring& key, double& value) const;

	bool GetValue(const tstring& key, tstring& value) const;

	bool GetValue(const tstring& key, JsonObject& value) const;

	bool GetValue(const tstring& key, list<JsonValue>& value) const;

	bool GetValue(const tstring& key, JsonValue& value) const;

public:
	const map<tstring, JsonValue>& GetKeyValue() const { return m_mapKeyValue; }

private:
	map<tstring, JsonValue>		m_mapKeyValue;
};

class JsonValue
{
public:
	enum JsonValueType
	{
		JVT_NULL = 0,
		JVT_INT,
		JVT_UINT,
		JVT_UINT64,
		JVT_BOOL,
		JVT_DOUBLE,
		JVT_STRING,
		JVT_ARRAY,
		JVT_OBJECT,
	};

public:
	JsonValue()
	{
		m_typeValue = JVT_NULL;
	}

	JsonValue(int value)
	{
		m_typeValue = JVT_INT;
		m_nValue = value;
	}

	JsonValue(uint value)
	{
		m_typeValue = JVT_UINT;
		m_unValue = value;
	}

	JsonValue(uint64 value)
	{
		m_typeValue = JVT_UINT64;
		m_unValue64 = value;
	}

	JsonValue(bool value)
	{
		m_typeValue = JVT_BOOL;
		m_bValue = value;
	}

	JsonValue(double value)
	{
		m_typeValue = JVT_DOUBLE;
		m_dValue = value;
	}

	JsonValue(const tstring& value)
	{
		m_typeValue = JVT_STRING;
		m_strValue = value;
	}

	JsonValue(const JsonObject& value)
	{
		m_typeValue = JVT_OBJECT;
		m_objValue = value;
	}

	JsonValue(const list<JsonValue>& value)
	{
		m_typeValue = JVT_ARRAY;
		m_lstValue = value;
	}

public:
	JsonValueType JsonValue::GetValueType() const
	{
		return m_typeValue;
	}

public:
	int GetInt() const;
	uint GetUint() const;
	uint64 GetUint64() const;
	bool GetBool() const;
	double GetDouble() const;
	const tstring& GetString() const;
	const JsonObject& GetObject() const;
	const list<JsonValue>& GetArray() const;

private:
	bool				m_bValue;
	int					m_nValue;
	uint				m_unValue;
	uint64				m_unValue64;
	double				m_dValue;
	tstring				m_strValue;
	JsonObject			m_objValue;
	list<JsonValue>		m_lstValue;
	JsonValueType		m_typeValue;
};

class CImageObject
{
public:
	virtual BOOL IsImageVisible() = 0;
	virtual void RedrawImageObject() = 0;
};

class CSkinDialog;
class SKINUI_API CSkinImage
{
private:
	CSkinImage(const tstring& strImage, CSkinDialog* pImageHost, const CSize& szMax = CSize());
	CSkinImage(Image* pImage, CSkinDialog* pImageHost, const CSize& szMax = CSize());
	~CSkinImage();

	friend class CSkinDialog;

public:
	void Play();
	void Stop();
	void Draw(HDC hdc, const CRect& rect, ImageAttributes* pImageAttributes = NULL);

public:
	void SetCurElapse(UINT nElapse);

	BOOL IsNeedSelectNextActiveFrame(DWORD dwTickCount);
	void SelectNextActiveFrame();

public:
	void AddObject(CImageObject* pImageObject);
	void RemoveObject(CImageObject* pImageObject);
	UINT GetObjectCount();

public:
	Image* GetImage();
	tstring GetImagePath();

	CSize GetImageSize();
	CSize GetImageMaxSize();

protected:
	void Load();
	void Release();

	BOOL IsGifImage();
	UINT GetNextElapse();

private:
	CSize					m_size;
	CSize					m_szMax;
	Image*					m_pImage;
	tstring					m_strImage;
	BOOL					m_bNeedDelete;

	UINT					m_nCurFrame;
	UINT					m_nTotalFrame;
	UINT					m_nCurElapse;
	DWORD					m_nLastTickCount;

	CSkinDialog*			m_pImageHost;
	PropertyItem*			m_pProperty;
	list<CImageObject*>		m_lstObject;
};

inline Image* CSkinImage::GetImage()
{
	return m_pImage;
}

inline tstring CSkinImage::GetImagePath()
{
	return m_strImage;
}

inline CSize CSkinImage::GetImageSize()
{
	return m_size;
}

inline CSize CSkinImage::GetImageMaxSize()
{
	return m_szMax;
}

inline void CSkinImage::AddObject(CImageObject* pImageObject)
{
	m_lstObject.push_back(pImageObject);
}

inline UINT CSkinImage::GetObjectCount()
{
	return m_lstObject.size();
}

inline void CSkinImage::SetCurElapse(UINT nElapse)
{
	m_nLastTickCount = ::GetTickCount();
	m_nCurElapse = nElapse;
}

class CCopyDataPacketOut
{
public:
	CCopyDataPacketOut();
	~CCopyDataPacketOut();

public:
	BYTE* GetBuffer() const;
	DWORD GetSize() const;

public:
	void PackBool(BOOL data);
	void PackUint32(uint32 data);
	void PackString(const string& data);
	void PackWString(const wstring& data);

private:
	uint32 m_uBufPos;
	BYTE* m_pBuffer;
};

inline BYTE* CCopyDataPacketOut::GetBuffer() const
{
	return m_pBuffer;
}

inline DWORD CCopyDataPacketOut::GetSize() const
{
	return m_uBufPos;
}

class CCopyDataPacketIn
{
public:
	CCopyDataPacketIn(PVOID pBuf, int nLen);

public:
	BOOL UnPackBool();
	uint32 UnPackUint32();
	string UnPackString();
	wstring UnPackWString();

private:
	uint32 m_uBufPos;
	uint32 m_uBufLen;
	BYTE* m_pBuffer;
};

class CSkinView;
class CRedrawLocker
{
public:
	CRedrawLocker(CSkinView* pSkinView);

	~CRedrawLocker();

private:
	CSkinView* m_pSkinView;
};

class GraphicsRoundPath: public GraphicsPath
{
public:
	GraphicsRoundPath(const CRect& rect, LONG nRadius, UINT nRoundMask = ROUND_ALL);
};

typedef struct _DATASTORAGE
{
	FORMATETC* m_formatEtc;
	STGMEDIUM* m_stgMedium;
}
DATASTORAGE_t,* LPDATASTORAGE_t;

class CDropSource;
class CSkinEditView;
class SKINUI_API CDataObject : public IDataObject
{
public:
	CDataObject();

public:
	BOOL SetView(CSkinView* pView);

	BOOL SetEditView(CSkinEditView* pView);

public:
	IFACEMETHODIMP QueryInterface(REFIID riid, void** ppv);
	IFACEMETHODIMP_(ULONG) AddRef();
	IFACEMETHODIMP_(ULONG) Release();
	IFACEMETHODIMP GetData(FORMATETC* pformatetcIn, STGMEDIUM* pmedium);
	IFACEMETHODIMP SetData(FORMATETC* pformatetc, STGMEDIUM* pmedium, BOOL fRelease);
	IFACEMETHODIMP GetDataHere(FORMATETC* pformatetc , STGMEDIUM* pmedium );
	IFACEMETHODIMP QueryGetData(FORMATETC* pformatetc);
	IFACEMETHODIMP GetCanonicalFormatEtc(FORMATETC* pformatetcIn, FORMATETC* pformatetcOut) { return E_NOTIMPL; }
	IFACEMETHODIMP EnumFormatEtc(DWORD dwDirection, IEnumFORMATETC** ppenumFormatEtc);
	IFACEMETHODIMP DAdvise(FORMATETC* pformatetc, DWORD advf, IAdviseSink* pAdvSnk , DWORD* pdwConnection);
	IFACEMETHODIMP DUnadvise(DWORD dwConnection);
	IFACEMETHODIMP EnumDAdvise(IEnumSTATDATA** ppenumAdvise);

private:
	~CDataObject(void);
	CDataObject(const CDataObject&);
	CDataObject& operator = (const CDataObject&);
	HRESULT CopyMedium(STGMEDIUM* pMedDest, STGMEDIUM* pMedSrc, FORMATETC* pFmtSrc);
	HRESULT SetBlob(CLIPFORMAT cf, const void* pvBlob, UINT cbBlob);

private:
	volatile LONG			m_lRefCount;
	vector<DATASTORAGE_t>	m_dataStorageCL;
};

class CSkinEditView;
class CDropSourceWindow;
class SKINUI_API CDropSource : public IDropSource
{
public:
	CDropSource(CSkinView* pView, const CPoint& ptPopup);
	CDropSource(CSkinEditView* pView, const CPoint& ptPopup);
	~CDropSource();

public:
	IFACEMETHODIMP QueryInterface(REFIID riid, void **ppv);
	IFACEMETHODIMP_(ULONG) AddRef(void);
	IFACEMETHODIMP_(ULONG) Release(void);

public:
	IFACEMETHODIMP QueryContinueDrag(BOOL fEscapePressed, DWORD grfKeyState);
	IFACEMETHODIMP GiveFeedback(DWORD dwEffect);

private:
	volatile LONG			m_lRefCount;
	CDropSourceWindow*		m_pDropSource;
};

class SKINUI_API CDropTarget : public IDropTarget
{
public:
	CDropTarget();
	~CDropTarget();

public:
	ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void** ppvObject);

public:
	HRESULT STDMETHODCALLTYPE Drop(IDataObject* pDataObject, ULONG grfKeyState, POINTL pMouse, ULONG* pdwEffect);
	HRESULT STDMETHODCALLTYPE DragEnter(IDataObject* pDataObject, ULONG grfKeyState, POINTL pMouse, ULONG* pDropEffect);
	HRESULT STDMETHODCALLTYPE DragOver(ULONG grfKeyState, POINTL pMouse, ULONG *pEffect);
	HRESULT STDMETHODCALLTYPE DragLeave();

public:
	BOOL Register(HWND hWnd, const vector<UINT>& vecDataType);
	UINT QueryDataObject(IDataObject *pDataObject);
	void Revoke();

public:
	virtual void GotDrop();
	virtual void GotLeave();
	virtual DWORD GotDrag();
	virtual DWORD GotEnter();

public:
	BYTE*	m_Data;
	DWORD	m_dwKeyState;
	CPoint	m_DropPoint;

protected:
	HWND			m_hTarget;
	DWORD			m_dwRefCount;

private:
	UINT			m_nCurType;
	CSkinView*		m_pCurDrag;
	vector<UINT>	m_vecDataType;
};

#define SKINUI_DECLARE_DYNCREATE() \
	public: \
	static CSkinView* Create(CSkinView* pParent); \
	virtual tstring GetClassName();

#define SKINUI_IMPLEMENT_DYNCREATE(Class) \
	CSkinView* Class::Create(CSkinView* pParent) \
	{ return new Class(pParent); } \
	static void RegisterWindow##Class()  \
{CSkinFactory::GetInstance()->Register(#Class, &Class::Create);}\
	static CRegisterWindowHelper helper##Class(&RegisterWindow##Class);\
	tstring Class::GetClassName() { return SkinUI::MultiByteToWideChar(#Class); }

typedef void (*ReginsterHandle)(void);
struct CRegisterWindowHelper
{
	CRegisterWindowHelper(ReginsterHandle registerHandle)
	{
		registerHandle();
	}
};

class SKINUI_API CSkinView;
typedef CSkinView* (*CreateHandle)(CSkinView* pParent);
class SKINUI_API CSkinFactory
{
private:
	CSkinFactory(){}
	~CSkinFactory(){}
	static CSkinFactory* s_inst;

public:
	static CSkinFactory* GetInstance();
	static void ReleaseInstance();

public:
	CSkinView* Create(const tstring& strClass, CSkinView* pParent);
	void  Register(const string& strClass, CreateHandle handle);

private:
	map<tstring, CreateHandle> m_mapWindowCreateHandle;
};

typedef void (*MsgHelper)(void);
typedef void (CSkinView::*MsgHandle)(void);
#define CN_SKINUI_UPDATE_COMMAND_UI 65378

class SKINUI_API CSkinMsgMap
{
public:
	CSkinMsgMap(): m_pBaseMap(NULL) {}

public:
	void AddHandle(uint nMsg, MsgHandle msgHandle)
	{
		m_mapHandle.insert(make_pair(nMsg, msgHandle));
	}

	void AddCommandHandle(uint nCmdId, MsgHandle msgHandle)
	{
		m_mapCmdHandle.insert(make_pair(nCmdId, msgHandle));
	}

	void AddCommandRangeHandle(uint nCmdIdBegin, uint nCmdIdEnd, MsgHandle msgHandle)
	{
		m_mapCmdRangeHandle.insert(make_pair(make_pair(nCmdIdBegin, nCmdIdEnd), msgHandle));
	}

	void AddUpdateCommandUIHandle(uint nCmdId, MsgHandle msgHandle)
	{
		m_mapUpdateCmdUIHandle.insert(make_pair(nCmdId, msgHandle));
	}

	MsgHandle FindCommandRangeHandle(uint nId)
	{
		for(map<pair<uint, uint>, MsgHandle>::iterator iter = m_mapCmdRangeHandle.begin(); iter != m_mapCmdRangeHandle.end(); ++iter)
		{
			if(iter->first.first <= nId&& iter->first.second >= nId)
			{
				return iter->second;
			}
		}

		if(m_pBaseMap)
		{
			MsgHandle handle = m_pBaseMap->FindCommandRangeHandle(nId);
			if(handle)
			{
				return handle;
			}
		}

		return NULL;
	}

public:
	CSkinMsgMap*								m_pBaseMap;				//基类消息映射
	map<uint, MsgHandle>						m_mapHandle;			//普通消息处理
	map<uint, MsgHandle>						m_mapCmdHandle;			//命令消息处理
	map<pair<uint, uint>, MsgHandle>			m_mapCmdRangeHandle;	//命令消息处理
	map<uint, MsgHandle>						m_mapUpdateCmdUIHandle;	//更新命令消息
};

class SKINUI_API CSkinExtensionMsgMap
{
public:
	CSkinExtensionMsgMap(): m_pBaseMap(NULL) {}

public:
	void AddHandle(const tstring& strMsg, MsgHandle msgHandle)
	{
		m_mapHandle.insert(make_pair(strMsg, msgHandle));
	}

	MsgHandle FindHandle(const tstring& strMsg)
	{
		map<tstring, MsgHandle>::iterator iter = m_mapHandle.find(strMsg);
		if(iter != m_mapHandle.end())
		{
			return iter->second;
		}

		if(m_pBaseMap)
		{
			MsgHandle handle = m_pBaseMap->FindHandle(strMsg);
			if(handle)
			{
				return handle;
			}
		}

		return NULL;
	}

public:
	CSkinExtensionMsgMap*		m_pBaseMap;				//基类消息映射
	map<tstring, MsgHandle>		m_mapHandle;			//普通消息处理
};

struct CMessageMapHelper
{
	CMessageMapHelper(MsgHelper msgHelper)
	{
		msgHelper();
	}
};

#define SKINUI_DECLARE_MESSAGE_MAP()\
public:\
	static CSkinMsgMap messageMap;\
	virtual CSkinMsgMap* GetMessageMap();\
public:\
	static void InitMessageMap();

#define SKINUI_BEGIN_MESSAGE_MAP(theClass, baseClass)\
	typedef theClass TheClass;\
	typedef baseClass TheBaseClass;\
	CSkinMsgMap TheClass::messageMap;\
	CSkinMsgMap* TheClass::GetMessageMap()\
	{ return &messageMap;}\
	void TheClass::InitMessageMap() {\
		if(&TheBaseClass::messageMap != &TheClass::messageMap)\
			TheClass::messageMap.m_pBaseMap = &TheBaseClass::messageMap;\

#define SKINUI_END_MESSAGE_MAP()\
	}\
	static CMessageMapHelper initHelper (TheClass::InitMessageMap);

#define ON_SKINUI_COMMAND(id, commandMsgHandle)\
	{\
		void(TheClass::*commandHandle)(UINT, int, CSkinView*) = &commandMsgHandle;\
		MsgHandle* pCommandMsgHandle = reinterpret_cast<MsgHandle*>(&commandHandle);\
		messageMap.AddCommandHandle(id, *pCommandMsgHandle);\
	}

#define ON_SKINUI_COMMAND_RANGE(idBegin, idEnd, commandMsgHandle)\
	{\
		void(TheClass::*commandHandle)(UINT, int, CSkinView*) = &commandMsgHandle;\
		MsgHandle* pCommandMsgHandle = reinterpret_cast<MsgHandle*>(&commandHandle);\
		messageMap.AddCommandRangeHandle(idBegin, idEnd, *pCommandMsgHandle);\
	}

#define ON_SKINUI_UPDATE_COMMAND_UI(id, updateCommandUIMsgHandle)\
	{\
		void(TheClass::*updateCommandHandle)(CSkinView*) = &updateCommandUIMsgHandle;\
		MsgHandle* pUpdateCommandUIMsgHandle = reinterpret_cast<MsgHandle*>(&updateCommandHandle);\
		messageMap.AddUpdateCommandUIHandle(id, *pUpdateCommandUIMsgHandle);\
	}

#define ON_SKINUI_MESSAGE(nMsg, messageHandle)\
	{\
		LRESULT(TheClass::*msgHandle)(WPARAM wParam, LPARAM lParam) = &messageHandle;\
		MsgHandle* pMessageHandle = reinterpret_cast<MsgHandle*>(&msgHandle);\
		messageMap.AddHandle(nMsg, *pMessageHandle);\
	}

#define ON_SKINUI_WM_CREATE()\
	void(TheClass::*createHandle)(BOOL&) = &TheClass::OnCreate;\
	MsgHandle* pCreateHandle = reinterpret_cast<MsgHandle*>(&createHandle);\
	messageMap.AddHandle(WM_CREATE, *pCreateHandle);

#define ON_SKINUI_WM_PAINT()\
	void(TheClass::*paintHandle)(HDC, BOOL&) = &TheClass::OnPaint;\
	MsgHandle* pPaintHandle = reinterpret_cast<MsgHandle*>(&paintHandle);\
	messageMap.AddHandle(WM_PAINT, *pPaintHandle);

#define ON_SKINUI_WM_ERASEBKGND()\
	LRESULT(TheClass::*eraseBkgndHandle)(BOOL&) = &TheClass::OnEraseBkgnd;\
	MsgHandle* pEraseBkgndHandle = reinterpret_cast<MsgHandle*>(&eraseBkgndHandle);\
	messageMap.AddHandle(WM_ERASEBKGND, *pEraseBkgndHandle);

#define ON_SKINUI_WM_SETCURSOR()\
	LRESULT(TheClass::*setCursorHandle)(HWND, UINT, UINT, BOOL&) = &TheClass::OnSetCursor;\
	MsgHandle* pSetCursorHandle = reinterpret_cast<MsgHandle*>(&setCursorHandle);\
	messageMap.AddHandle(WM_SETCURSOR, *pSetCursorHandle);

#define ON_SKINUI_WM_DESTROY()\
	void(TheClass::*destroyHandle)(BOOL&) = &TheClass::OnDestroy;\
	MsgHandle* pDestroyHandle = reinterpret_cast<MsgHandle*>(&destroyHandle);\
	messageMap.AddHandle(WM_DESTROY, *pDestroyHandle);

#define ON_SKINUI_WM_SETFOCUS()\
	void(TheClass::*setFocusHandle)(HWND, BOOL&) = &TheClass::OnSetFocus;\
	MsgHandle* pSetFocusHandle = reinterpret_cast<MsgHandle*>(&setFocusHandle);\
	messageMap.AddHandle(WM_SETFOCUS, *pSetFocusHandle);

#define ON_SKINUI_WM_NCDESTROY()\
	void(TheClass::*ncDestroyHandle)(BOOL&) = &TheClass::OnNcDestroy;\
	MsgHandle* pNcDestroyHandle = reinterpret_cast<MsgHandle*>(&ncDestroyHandle);\
	messageMap.AddHandle(WM_NCDESTROY, *pNcDestroyHandle);

#define ON_SKINUI_WM_NCLBUTTONDOWN()\
	void(TheClass::*ncLButtonDownHandle)(UINT, CPoint, BOOL&) = &TheClass::OnNcLButtonDown;\
	MsgHandle* pNcLButtonDownHandle = reinterpret_cast<MsgHandle*>(&ncLButtonDownHandle);\
	messageMap.AddHandle(WM_NCLBUTTONDOWN, *pNcLButtonDownHandle);

#define ON_SKINUI_WM_NCLBUTTONUP()\
	void(TheClass::*ncLButtonUpHandle)(UINT, CPoint, BOOL&) = &TheClass::OnNcLButtonUp;\
	MsgHandle* pNcLButtonUpHandle = reinterpret_cast<MsgHandle*>(&ncLButtonUpHandle);\
	messageMap.AddHandle(WM_NCLBUTTONUP, *pNcLButtonUpHandle);

#define ON_SKINUI_WM_KILLFOCUS()\
	void(TheClass::*killFocusHandle)(BOOL&) = &TheClass::OnKillFocus;\
	MsgHandle* pKillFocusHandle = reinterpret_cast<MsgHandle*>(&killFocusHandle);\
	messageMap.AddHandle(WM_KILLFOCUS, *pKillFocusHandle);

#define ON_SKINUI_WM_SIZE()\
	void(TheClass::*sizeHandle)(UINT, CSize, BOOL&) = &TheClass::OnSize;\
	MsgHandle* pSizeHandle = reinterpret_cast<MsgHandle*>(&sizeHandle);\
	messageMap.AddHandle(WM_SIZE, *pSizeHandle);

#define ON_SKINUI_WM_SYSKEYDOWN()\
	void(TheClass::*sysKeyDownHandle)(TCHAR, UINT, UINT, BOOL&) = &TheClass::OnSysKeyDown;\
	MsgHandle* pSysKeyDownHandle = reinterpret_cast<MsgHandle*>(&sysKeyDownHandle);\
	messageMap.AddHandle(WM_SYSKEYDOWN, *pSysKeyDownHandle);

#define ON_SKINUI_WM_SYSKEYUP()\
	void(TheClass::*sysKeyUpHandle)(TCHAR, UINT, UINT, BOOL&) = &TheClass::OnSysKeyUp;\
	MsgHandle* pSysKeyUpHandle = reinterpret_cast<MsgHandle*>(&sysKeyUpHandle);\
	messageMap.AddHandle(WM_SYSKEYUP, *pSysKeyUpHandle);

#define ON_SKINUI_WM_KEYDOWN()\
	void(TheClass::*keyDownHandle)(TCHAR, UINT, UINT, BOOL&) = &TheClass::OnKeyDown;\
	MsgHandle* pKeyDownHandle = reinterpret_cast<MsgHandle*>(&keyDownHandle);\
	messageMap.AddHandle(WM_KEYDOWN, *pKeyDownHandle);

#define ON_SKINUI_WM_KEYUP()\
	void(TheClass::*keyUpHandle)(TCHAR, UINT, UINT, BOOL&) = &TheClass::OnKeyUp;\
	MsgHandle* pKeyUpHandle = reinterpret_cast<MsgHandle*>(&keyUpHandle);\
	messageMap.AddHandle(WM_KEYUP, *pKeyUpHandle);

#define ON_SKINUI_WM_CHAR()\
	void(TheClass::*charHandle)(TCHAR, UINT, UINT, BOOL&) = &TheClass::OnChar;\
	MsgHandle* pCharHandle = reinterpret_cast<MsgHandle*>(&charHandle);\
	messageMap.AddHandle(WM_CHAR, *pCharHandle);

#define ON_SKINUI_WM_SIZING()\
	void(TheClass::*sizingHandle)(UINT, LPRECT, BOOL&) = &TheClass::OnSizing;\
	MsgHandle* pSizingHandle = reinterpret_cast<MsgHandle*>(&sizingHandle);\
	messageMap.AddHandle(WM_SIZING, *pSizingHandle);

#define ON_SKINUI_WM_LBUTTONDOWN()\
	void(TheClass::*lButtonDownHandle)(UINT, CPoint, BOOL&) = &TheClass::OnLButtonDown;\
	MsgHandle* pLButtonDownHandle = reinterpret_cast<MsgHandle*>(&lButtonDownHandle);\
	messageMap.AddHandle(WM_LBUTTONDOWN, *pLButtonDownHandle);

#define ON_SKINUI_WM_LBUTTONUP()\
	void(TheClass::*lButtonUpHandle)(UINT, CPoint, BOOL&) = &TheClass::OnLButtonUp;\
	MsgHandle* pLButtonUpHandle = reinterpret_cast<MsgHandle*>(&lButtonUpHandle);\
	messageMap.AddHandle(WM_LBUTTONUP, *pLButtonUpHandle);

#define ON_SKINUI_WM_RBUTTONDOWN()\
	void(TheClass::*rButtonDownHandle)(UINT, CPoint, BOOL&) = &TheClass::OnRButtonDown;\
	MsgHandle* pRButtonDownHandle = reinterpret_cast<MsgHandle*>(&rButtonDownHandle);\
	messageMap.AddHandle(WM_RBUTTONDOWN, *pRButtonDownHandle);

#define ON_SKINUI_WM_RBUTTONUP()\
	void(TheClass::*rButtonUpHandle)(UINT, CPoint, BOOL&) = &TheClass::OnRButtonUp;\
	MsgHandle* pRButtonUpHandle = reinterpret_cast<MsgHandle*>(&rButtonUpHandle);\
	messageMap.AddHandle(WM_RBUTTONUP, *pRButtonUpHandle);

#define ON_SKINUI_WM_LBUTTONDBLCLK()\
	void(TheClass::*lButtonDBClkHandle)(UINT, CPoint, BOOL&) = &TheClass::OnLButtonDblClk;\
	MsgHandle* pLButtonDBClkHandle = reinterpret_cast<MsgHandle*>(&lButtonDBClkHandle);\
	messageMap.AddHandle(WM_LBUTTONDBLCLK, *pLButtonDBClkHandle);

#define ON_SKINUI_WM_MOUSEMOVE()\
	void(TheClass::*mouseMoveHandle)(UINT, CPoint, BOOL&) = &TheClass::OnMouseMove;\
	MsgHandle* pMouseMoveHandle = reinterpret_cast<MsgHandle*>(&mouseMoveHandle);\
	messageMap.AddHandle(WM_MOUSEMOVE, *pMouseMoveHandle);

#define ON_SKINUI_WM_MOUSEHOVER()\
	void(TheClass::*mouseHoverHandle)(WPARAM, CPoint, BOOL&) = &TheClass::OnMouseHover;\
	MsgHandle* pMouseHoverHandle = reinterpret_cast<MsgHandle*>(&mouseHoverHandle);\
	messageMap.AddHandle(WM_MOUSEHOVER, *pMouseHoverHandle);

#define ON_SKINUI_WM_MOUSELEAVE()\
	void(TheClass::*mouseLeaveHandle)(BOOL&) = &TheClass::OnMouseLeave;\
	MsgHandle* pMouseLeaveHandle = reinterpret_cast<MsgHandle*>(&mouseLeaveHandle);\
	messageMap.AddHandle(WM_MOUSELEAVE, *pMouseLeaveHandle);

#define ON_SKINUI_WM_MOUSEWHEEL()\
	LRESULT(TheClass::*mouseWheelHandle)(UINT, short, CPoint, BOOL&) = &TheClass::OnMouseWheel;\
	MsgHandle* pMouseWheelHandle = reinterpret_cast<MsgHandle*>(&mouseWheelHandle);\
	messageMap.AddHandle(WM_MOUSEWHEEL, *pMouseWheelHandle);

#define ON_SKINUI_WM_NCHITTEST()\
	LRESULT(TheClass::*ncHittestHandle)(CPoint, BOOL&) = &TheClass::OnNcHitTest;\
	MsgHandle* pNcHittestHandle = reinterpret_cast<MsgHandle*>(&ncHittestHandle);\
	messageMap.AddHandle(WM_NCHITTEST, *pNcHittestHandle);

#define ON_SKINUI_WM_GETMINMAXINFO()\
	void(TheClass::*getMinMaxInfoHandle)(MINMAXINFO*, BOOL&) = &TheClass::OnGetMinMaxInfo;\
	MsgHandle* pGetMinMaxInfoHandle = reinterpret_cast<MsgHandle*>(&getMinMaxInfoHandle);\
	messageMap.AddHandle(WM_GETMINMAXINFO, *pGetMinMaxInfoHandle);

#define ON_SKINUI_WM_TIMER()\
	void(TheClass::*timerHandle)(UINT_PTR, BOOL&) = &TheClass::OnTimer;\
	MsgHandle* pTimerHandle = reinterpret_cast<MsgHandle*>(&timerHandle);\
	messageMap.AddHandle(WM_TIMER, *pTimerHandle);

#define ON_SKINUI_WM_SYSCOMMAND()\
	void(TheClass::*sysCommandHandle)(UINT, LPARAM, BOOL&) = &TheClass::OnSysCommand;\
	MsgHandle* pSysCommandHandle = reinterpret_cast<MsgHandle*>(&sysCommandHandle);\
	messageMap.AddHandle(WM_SYSCOMMAND, *pSysCommandHandle);

#define ON_SKINUI_WM_CLOSE()\
	void(TheClass::*closeHandle)(BOOL&) = &TheClass::OnClose;\
	MsgHandle* pCloseHandle = reinterpret_cast<MsgHandle*>(&closeHandle);\
	messageMap.AddHandle(WM_CLOSE, *pCloseHandle);

#define ON_SKINUI_WM_MOVE()\
	void(TheClass::*moveHandle)(CPoint, BOOL&) = &TheClass::OnMove;\
	MsgHandle* pMoveHandle = reinterpret_cast<MsgHandle*>(&moveHandle);\
	messageMap.AddHandle(WM_MOVE, *pMoveHandle);

#define ON_SKINUI_WM_MOVING()\
	void(TheClass::*movingHandle)(UINT, LPRECT, BOOL&) = &TheClass::OnMoving;\
	MsgHandle* pMovingHandle = reinterpret_cast<MsgHandle*>(&movingHandle);\
	messageMap.AddHandle(WM_MOVING, *pMovingHandle);

#define ON_SKINUI_WM_COPYDATA()\
	LRESULT(TheClass::*copyDataHandle)(HWND, PCOPYDATASTRUCT, BOOL&) = &TheClass::OnCopyData;\
	MsgHandle* pCopyDataHandle = reinterpret_cast<MsgHandle*>(&copyDataHandle);\
	messageMap.AddHandle(WM_COPYDATA, *pCopyDataHandle);

#define ON_SKINUI_WM_WINDOWPOSCHANGED()\
	void(TheClass::*windowPosChangedHandle)(WINDOWPOS*, BOOL&) = &TheClass::OnWindowPosChanged;\
	MsgHandle* pWindowPosChangedHandle = reinterpret_cast<MsgHandle*>(&windowPosChangedHandle);\
	messageMap.AddHandle(WM_WINDOWPOSCHANGED, *pWindowPosChangedHandle);

#define ON_SKINUI_WM_ACTIVATE()\
	void(TheClass::*activateHandle)(UINT, BOOL, HWND, BOOL&) = &TheClass::OnActivate;\
	MsgHandle* pActivateHandle = reinterpret_cast<MsgHandle*>(&activateHandle);\
	messageMap.AddHandle(WM_ACTIVATE, *pActivateHandle);

#define ON_SKINUI_WM_HOTKEY()\
	void(TheClass::*hotkeyHandle)(int ,UINT, UINT, BOOL&) = &TheClass::OnHotKey;\
	MsgHandle* pHotkeyHandle = reinterpret_cast<MsgHandle*>(&hotkeyHandle);\
	messageMap.AddHandle(WM_HOTKEY, *pHotkeyHandle);

#define ON_SKINUI_WM_QUERYENDSESSION()\
	LRESULT(TheClass::*queryEndSessionHandle)(UINT, UINT, BOOL&) = &TheClass::OnQueryEndSession;\
	MsgHandle* pQueryEndSessionHandle = reinterpret_cast<MsgHandle*>(&queryEndSessionHandle);\
	messageMap.AddHandle(WM_QUERYENDSESSION, *pQueryEndSessionHandle);

#define ON_SKINUI_WM_IME_STARTCOMPOSITION()\
	LRESULT(TheClass::*imeStartComposition)(WPARAM wParam, LPARAM lParam, BOOL&) = &TheClass::OnImeStartComposition;\
	MsgHandle* pImeStartComposition = reinterpret_cast<MsgHandle*>(&imeStartComposition);\
	messageMap.AddHandle(WM_IME_STARTCOMPOSITION, *pImeStartComposition);

#define ON_SKINUI_WM_IME_ENDCOMPOSITION()\
	LRESULT(TheClass::*imeEndComposition)(WPARAM wParam, LPARAM lParam, BOOL&) = &TheClass::OnImeEndComposition;\
	MsgHandle* pImeEndComposition = reinterpret_cast<MsgHandle*>(&imeEndComposition);\
	messageMap.AddHandle(WM_IME_ENDCOMPOSITION, *pImeEndComposition);

#define ON_SKINUI_WM_IME_COMPOSITION()\
	LRESULT(TheClass::*imeComposition)(WPARAM wParam, LPARAM lParam, BOOL&) = &TheClass::OnImeComposition;\
	MsgHandle* pImeComposition = reinterpret_cast<MsgHandle*>(&imeComposition);\
	messageMap.AddHandle(WM_IME_COMPOSITION, *pImeComposition);

#define ON_SKINUI_WM_DISPLAYCHANGE()\
	LRESULT(TheClass::*displayChange)(BOOL&) = &TheClass::OnDisplayChange;\
	MsgHandle* pDisplayChange = reinterpret_cast<MsgHandle*>(&displayChange);\
	messageMap.AddHandle(WM_DISPLAYCHANGE, *pDisplayChange);

#define SKINUI_DECLARE_EXTENSION_MESSAGE_MAP()\
public:\
	static CSkinExtensionMsgMap extensionMessageMap;\
	virtual CSkinExtensionMsgMap* GetExtensionMessageMap();\
public:\
	static void InitExtensionMessageMap();

#define SKINUI_BEGIN_EXTENSION_MESSAGE_MAP(theClass, baseClass)\
	typedef theClass TheClass;\
	typedef baseClass TheBaseClass;\
	CSkinExtensionMsgMap TheClass::extensionMessageMap;\
	CSkinExtensionMsgMap* TheClass::GetExtensionMessageMap()\
	{ return &extensionMessageMap;}\
	void TheClass::InitExtensionMessageMap() {\
		if(&TheBaseClass::extensionMessageMap != &TheClass::extensionMessageMap)\
			TheClass::extensionMessageMap.m_pBaseMap = &TheBaseClass::extensionMessageMap;\

#define SKINUI_END_EXTENSION_MESSAGE_MAP()\
	}\
	static CMessageMapHelper initExtensionHelper (TheClass::InitExtensionMessageMap);

#define ON_SKINUI_EXTENSION_MESSAGE(id, extensionMsgHandle)\
	{\
		void(TheClass::*extensionHandle)() = reinterpret_cast<void(TheClass::* )()>(&extensionMsgHandle);\
		MsgHandle* pExtensionMsgHandle = reinterpret_cast<MsgHandle*>(&extensionHandle);\
		extensionMessageMap.AddHandle(SkinUI::MultiByteToWideChar(#id), *pExtensionMsgHandle);\
	}

};
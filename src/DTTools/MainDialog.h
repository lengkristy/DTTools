#pragma once
#include "Layout\CommonlyUsedLayout.h"
class CMainDialog : public CSkinDialog
{
public:
	//定义控件ID枚举
	enum
	{
		IDC_MAIN_DLG_SRG_TAB = 100,
		IDC_MAIN_DLG_SRB_LEFT_BTN = 101,
		IDC_MAIN_DLG_SRB_RIGHT_BTN = 102,
		IDC_MAIN_DLG_SFL = 1000,
		IDC_MAIN_DLG_SFL_SRL_LEFT = 1100,
		IDC_MAIN_DLG_SFL_SRL_RIGHT = 1200
	};
	//常用菜单项枚举
	enum
	{
		IDC_MAIN_MENU_COMMONLY_ADD_ITEM = 40001,
		IDC_MAIN_MENU_COMMONLY_DELETE_ITEM = 40002
	};
	//定义选项卡被选择的枚举
	enum
	{
		COMMONLY_USED = 1,//常用
		CLASSIFICATION = 2//分类
	};
public:
	CMainDialog();
	~CMainDialog();
	void CreateCommonlyUsedLayout();//创建公共面板
	void LoadCommonResource();//加载公共资源
private:
	CommonlyUsedLayout *m_pCommonlyUesedLayout;//常用面板布局
	unsigned int m_iCurrentSelectedTable;//当前选择tab页面

public:
	virtual void OnInitDialog();

protected:
	void OnNcDestroy(BOOL& bHandle);
	void OnSize(UINT nType, CSize size, BOOL& bHandle);
	void OnRButtonDown(UINT nType, CPoint point, BOOL& bHandle);
	void OnRadioButtonClicked(UINT uNotifyCode, int nID, CSkinView* pView);//选项卡被选择
	void OnMenuCommandAddCommonlyUsedItem(UINT uNotifyCode, int nID, CSkinView* pView);//常用新增项菜单点击事件
	void OnMenuCommandDeleteCommonlyUsedItem(UINT uNotifyCode, int nID, CSkinView* pView);//常用删除项菜单点击事件
	SKINUI_DECLARE_MESSAGE_MAP()
public:
	wstring GetProgramDir();//获取程序运行目录
};
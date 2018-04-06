#pragma once
#include "CommonlyUsedItem.h"

class CommonlyUsedLayout : public CSkinRelativeLayout
{
public:
	//定义控件ID枚举
	enum
	{
		IDC_COMMONLYUSED_SLV = 21001
	};
public:
	CommonlyUsedLayout(CSkinView* pParent);
	~CommonlyUsedLayout();
	SKINUI_DECLARE_DYNCREATE()
public:
	virtual void HandleBuildFinish();
protected:
	LRESULT OnListItemCheckedChange(WPARAM wParam, LPARAM lParam);
	LRESULT OnListItemLBDBClick(WPARAM wParam, LPARAM lParam);//列表被双击
	SKINUI_DECLARE_MESSAGE_MAP()
public:
	void InitResource();//初始化资源
	void DeleteSelectedAppItem();//删除被选择的app项目
	void AddAppItem(const TCHAR* imageName,const TCHAR* appName,const TCHAR* appPath);//添加项
private:
	CSkinListView* m_pListCU;//常用列表
	CommonlyUsedItem* m_pComputerItem;//我的电脑项
	list<CommonlyUsedItem*> m_pListItem;//item项
};
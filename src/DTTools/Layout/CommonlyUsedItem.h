#pragma once
#include "../stdafx.h"

class CommonlyUsedItem : public CSkinListItem
{
public:
	//定义控件ID枚举
	enum
	{
		IDC_COMMONLYUSEDITEM_SIV = 300001,
		IDC_COMMONLYUSEDITEM_STV = 300002
	};
public:
	CommonlyUsedItem(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()
public:
	virtual void HandleBuildFinish();
	/*static map<ConvId, CommonlyUsedLayout*> s_mapInst;
	static CChatLayout* GetExist(ConvId convId);
	static CChatLayout* GetInstance(CSkinView* pParent, ConvId convId);*/
protected:
	LRESULT OnListItemCheckedChange(WPARAM wParam, LPARAM lParam);
	SKINUI_DECLARE_MESSAGE_MAP()
public:
	void InitResource();
private:
	CSkinImageView* m_pImageView;//图像
	
};
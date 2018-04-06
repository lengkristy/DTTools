#include "CommonlyUsedItem.h"

SKINUI_BEGIN_MESSAGE_MAP(CommonlyUsedItem, CSkinListItem)
	ON_SKINUI_MESSAGE(WM_SKINUI_LIST_ITEM_CHECKED_CHANGE, OnListItemCheckedChange)//映射列表被选择消息
SKINUI_END_MESSAGE_MAP()

SKINUI_IMPLEMENT_DYNCREATE(CommonlyUsedItem)
CommonlyUsedItem::CommonlyUsedItem(CSkinView* pParent) : CSkinListItem(pParent)
{
	InitResource();
}

void CommonlyUsedItem::HandleBuildFinish()
{
	CSkinRelativeLayout::HandleBuildFinish();
	m_pImageView = static_cast<CSkinImageView*>(GetChildById(IDC_COMMONLYUSEDITEM_SIV));
}

void CommonlyUsedItem::InitResource()
{
	//加载布局文件
	this->SetLayout(_T("CommonlyUsedItem.xml"));
	this->SetLayoutHeight(50);
	this->SetLayoutWidth(FILL_PARENT);
}

LRESULT CommonlyUsedItem::OnListItemCheckedChange(WPARAM wParam, LPARAM lParam)
{
	CSkinListItem* pSLI = static_cast<CSkinListItem*>(GetChildById(wParam));
	return 1L;
}
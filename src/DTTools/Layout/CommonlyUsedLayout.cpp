#include "../stdafx.h"
#include "CommonlyUsedLayout.h"
#include "../Core/SysResource.h"
#include "../Core/Command.h"

SKINUI_BEGIN_MESSAGE_MAP(CommonlyUsedLayout, CSkinRelativeLayout)
	ON_SKINUI_MESSAGE(WM_SKINUI_LIST_ITEM_CHECKED_CHANGE, OnListItemCheckedChange)//映射列表被选择消息
	ON_SKINUI_MESSAGE(WM_SKINUI_LIST_ITEM_LBUTTON_DBLCLK, OnListItemLBDBClick)//列表双击消息
SKINUI_END_MESSAGE_MAP()

SKINUI_IMPLEMENT_DYNCREATE(CommonlyUsedLayout)
CommonlyUsedLayout::CommonlyUsedLayout(CSkinView* pParent) : CSkinRelativeLayout(pParent)
{
	m_pListCU = NULL;
	InitResource();
}

CommonlyUsedLayout::~CommonlyUsedLayout()
{
	//释放资源m_pCUIL
	if (this->m_pComputerItem)
	{
		//delete m_pComputerItem;
	}
}

void CommonlyUsedLayout::HandleBuildFinish()
{
	CSkinRelativeLayout::HandleBuildFinish();
}

void CommonlyUsedLayout::InitResource()
{
	//加载布局文件
	this->SetLayout(_T("CommonlyUsedLayout.xml"));
	this->SetLayoutWidth(FILL_PARENT);
	this->SetLayoutHeight(FILL_PARENT);

	m_pListCU = static_cast<CSkinListView*>(GetChildById(IDC_COMMONLYUSED_SLV));
	//测试动态添加项
	/*if (m_pListCU)
	{
		CSkinListItem* pListItem = new CSkinListItem(m_pListCU);
		if (pListItem)
		{
			pListItem->SetLayoutHeight(50);
			pListItem->SetImage(_T("ListItem.png"));
			pListItem->SetLayout(_T("CommonlyUsedItem.xml"));
			pListItem->SetChildImage(100001, _T("computer.png"));
			pListItem->SetChildText(100002, _T("测试"));
		}
		m_pListCU->ResetScrollInfo();
		m_pListCU->ScrollBottom();
		m_pListCU->RedrawView();
	}*/

	//默认加载我的电脑
	m_pComputerItem = new CommonlyUsedItem(m_pListCU);
	if (m_pComputerItem)
	{
		m_pComputerItem->SetId(IDD_SYS_COMPUTER);
		m_pComputerItem->SetImage(_T("ListItem.png"));
		m_pComputerItem->SetChildImage(100001, _T("computer.png"));
		m_pComputerItem->SetChildText(100002, _T("我的电脑"));
		m_pComputerItem->SetChildText(100003, _T("我的电脑我的电脑我的电脑我的电脑我的电脑我的电脑我的电脑"));
		m_pComputerItem->SetLayoutAlignParentLeft(5);
	}
	m_pListCU->ResetScrollInfo();
	m_pListCU->ScrollBottom();
	m_pListCU->RedrawView();
	
}

LRESULT CommonlyUsedLayout::OnListItemCheckedChange(WPARAM wParam, LPARAM lParam)
{
	CSkinListItem* pSLI = static_cast<CSkinListItem*>(GetChildById(wParam));
	return 1L;
}

LRESULT CommonlyUsedLayout::OnListItemLBDBClick(WPARAM wParam, LPARAM lParam)
{
	//m_pComputerItem->SetChildText(100003, _T("sasdasd"));
	Command cmd;
	if (wParam == IDD_SYS_COMPUTER)//如果是打开电脑
	{
		cmd.OpenMyComputer();
		return 1L;
	}
	CommonlyUsedItem* pSLI = (CommonlyUsedItem*)m_pListCU->GetChecked();
	CSkinView* viewName = pSLI->GetChildById(100002);
	wstring fs = viewName->GetText();
	CSkinView* viewPath = pSLI->GetChildById(100003);
	wstring path = viewPath->GetText();
	//执行程序
	cmd.StartApplication(path.c_str());
	return 1L;
}

void CommonlyUsedLayout::DeleteSelectedAppItem()//删除被选择的app项目
{
	CommonlyUsedItem* pSLI = (CommonlyUsedItem*)m_pListCU->GetChecked();//获取被选择的
	if (!pSLI)
	{
		CSkinDialog* pCd= (CSkinDialog*)this->GetParent()->GetParent()->GetParent()->GetParent();//寻找MainDialog指针
		tstring strText = _T("选择删除项！");
		int nIcon = TOAST_ICON_ERROR;
		int nDuration = 3;
		int nDelay = 0;
		pCd->Toast(strText, nIcon, nDuration, nDelay);
		return;
	}
	if (pSLI->GetId() == IDD_SYS_COMPUTER)//选择的是我的电脑则不能删除
	{
		CSkinDialog* pCd = (CSkinDialog*)this->GetParent()->GetParent()->GetParent()->GetParent();//寻找MainDialog指针
		tstring strText = _T("默认项不能删除！");
		int nIcon = TOAST_ICON_ERROR;
		int nDuration = 3;
		int nDelay = 0;
		pCd->Toast(strText, nIcon, nDuration, nDelay);
		return;
	}
	//删除项
	m_pListCU->RemoveChild(pSLI);
	m_pListCU->ResetScrollInfo();
	m_pListCU->ScrollBottom();
	m_pListCU->RedrawView();
	//释放资源
	this->m_pListItem.remove(pSLI);
	delete pSLI;
}

void CommonlyUsedLayout::AddAppItem(const TCHAR* imageName, const TCHAR* appName, const TCHAR* appPath)
{
	CommonlyUsedItem* pComputerItem = new CommonlyUsedItem(m_pListCU);
	if (pComputerItem)
	{
		pComputerItem->SetImage(_T("ListItem.png"));
		pComputerItem->SetChildImage(100001, imageName);
		pComputerItem->SetChildText(100002, appName);
		pComputerItem->SetChildText(100003, appPath);
		pComputerItem->SetLayoutAlignParentLeft(5);
	}
	m_pListCU->ResetScrollInfo();
	m_pListCU->ScrollBottom();
	m_pListCU->RedrawView();
	this->m_pListItem.push_back(pComputerItem);
}
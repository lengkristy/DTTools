#include "../stdafx.h"
#include "CommonlyUsedLayout.h"
#include "../Core/SysResource.h"
#include "../Core/Command.h"

SKINUI_BEGIN_MESSAGE_MAP(CommonlyUsedLayout, CSkinRelativeLayout)
	ON_SKINUI_MESSAGE(WM_SKINUI_LIST_ITEM_CHECKED_CHANGE, OnListItemCheckedChange)//ӳ���б�ѡ����Ϣ
	ON_SKINUI_MESSAGE(WM_SKINUI_LIST_ITEM_LBUTTON_DBLCLK, OnListItemLBDBClick)//�б�˫����Ϣ
SKINUI_END_MESSAGE_MAP()

SKINUI_IMPLEMENT_DYNCREATE(CommonlyUsedLayout)
CommonlyUsedLayout::CommonlyUsedLayout(CSkinView* pParent) : CSkinRelativeLayout(pParent)
{
	m_pListCU = NULL;
	InitResource();
}

CommonlyUsedLayout::~CommonlyUsedLayout()
{
	//�ͷ���Դm_pCUIL
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
	//���ز����ļ�
	this->SetLayout(_T("CommonlyUsedLayout.xml"));
	this->SetLayoutWidth(FILL_PARENT);
	this->SetLayoutHeight(FILL_PARENT);

	m_pListCU = static_cast<CSkinListView*>(GetChildById(IDC_COMMONLYUSED_SLV));
	//���Զ�̬�����
	/*if (m_pListCU)
	{
		CSkinListItem* pListItem = new CSkinListItem(m_pListCU);
		if (pListItem)
		{
			pListItem->SetLayoutHeight(50);
			pListItem->SetImage(_T("ListItem.png"));
			pListItem->SetLayout(_T("CommonlyUsedItem.xml"));
			pListItem->SetChildImage(100001, _T("computer.png"));
			pListItem->SetChildText(100002, _T("����"));
		}
		m_pListCU->ResetScrollInfo();
		m_pListCU->ScrollBottom();
		m_pListCU->RedrawView();
	}*/

	//Ĭ�ϼ����ҵĵ���
	m_pComputerItem = new CommonlyUsedItem(m_pListCU);
	if (m_pComputerItem)
	{
		m_pComputerItem->SetId(IDD_SYS_COMPUTER);
		m_pComputerItem->SetImage(_T("ListItem.png"));
		m_pComputerItem->SetChildImage(100001, _T("computer.png"));
		m_pComputerItem->SetChildText(100002, _T("�ҵĵ���"));
		m_pComputerItem->SetChildText(100003, _T("�ҵĵ����ҵĵ����ҵĵ����ҵĵ����ҵĵ����ҵĵ����ҵĵ���"));
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
	if (wParam == IDD_SYS_COMPUTER)//����Ǵ򿪵���
	{
		cmd.OpenMyComputer();
		return 1L;
	}
	CommonlyUsedItem* pSLI = (CommonlyUsedItem*)m_pListCU->GetChecked();
	CSkinView* viewName = pSLI->GetChildById(100002);
	wstring fs = viewName->GetText();
	CSkinView* viewPath = pSLI->GetChildById(100003);
	wstring path = viewPath->GetText();
	//ִ�г���
	cmd.StartApplication(path.c_str());
	return 1L;
}

void CommonlyUsedLayout::DeleteSelectedAppItem()//ɾ����ѡ���app��Ŀ
{
	CommonlyUsedItem* pSLI = (CommonlyUsedItem*)m_pListCU->GetChecked();//��ȡ��ѡ���
	if (!pSLI)
	{
		CSkinDialog* pCd= (CSkinDialog*)this->GetParent()->GetParent()->GetParent()->GetParent();//Ѱ��MainDialogָ��
		tstring strText = _T("ѡ��ɾ���");
		int nIcon = TOAST_ICON_ERROR;
		int nDuration = 3;
		int nDelay = 0;
		pCd->Toast(strText, nIcon, nDuration, nDelay);
		return;
	}
	if (pSLI->GetId() == IDD_SYS_COMPUTER)//ѡ������ҵĵ�������ɾ��
	{
		CSkinDialog* pCd = (CSkinDialog*)this->GetParent()->GetParent()->GetParent()->GetParent();//Ѱ��MainDialogָ��
		tstring strText = _T("Ĭ�����ɾ����");
		int nIcon = TOAST_ICON_ERROR;
		int nDuration = 3;
		int nDelay = 0;
		pCd->Toast(strText, nIcon, nDuration, nDelay);
		return;
	}
	//ɾ����
	m_pListCU->RemoveChild(pSLI);
	m_pListCU->ResetScrollInfo();
	m_pListCU->ScrollBottom();
	m_pListCU->RedrawView();
	//�ͷ���Դ
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
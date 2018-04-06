#include "stdafx.h"
#include "MainDialog.h"
#include "Core\IconSnap.h"
#include "Core\Command.h"

SKINUI_BEGIN_MESSAGE_MAP(CMainDialog, CSkinDialog)
	ON_SKINUI_WM_NCDESTROY()
	ON_SKINUI_WM_SIZE() //ӳ���С�ı���Ϣ
	ON_SKINUI_WM_RBUTTONDOWN()//����Ҽ�����
	ON_SKINUI_COMMAND(IDC_MAIN_DLG_SRB_LEFT_BTN, OnRadioButtonClicked)//�����б�ѡ���ѡ��
	ON_SKINUI_COMMAND(IDC_MAIN_DLG_SRB_RIGHT_BTN, OnRadioButtonClicked)//�����б�ѡ���ѡ��
	ON_SKINUI_COMMAND(IDC_MAIN_MENU_COMMONLY_ADD_ITEM, OnMenuCommandAddCommonlyUsedItem)//�˵������
	ON_SKINUI_COMMAND(IDC_MAIN_MENU_COMMONLY_DELETE_ITEM, OnMenuCommandDeleteCommonlyUsedItem)//�˵������
SKINUI_END_MESSAGE_MAP()

CMainDialog::CMainDialog()
: CSkinDialog(_T("MainDialog.xml"))
{
	m_pCommonlyUesedLayout = NULL;
	m_iCurrentSelectedTable = COMMONLY_USED;//Ĭ��Ϊ����tableҳ
}

CMainDialog::~CMainDialog()
{
	if (m_pCommonlyUesedLayout != NULL)
	{
		//DeleteChild(m_pCommonlyUesedLayout); �ͷ���Դ
	}
}


void CMainDialog::LoadCommonResource()
{

}


void CMainDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
	//
	//this->LoadCommonResource();
	CreateCommonlyUsedLayout();
	//
	
	
}

void CMainDialog::CreateCommonlyUsedLayout()
{
	//
	CSkinRelativeLayout* psrl = static_cast<CSkinRelativeLayout*>(GetChildById(IDC_MAIN_DLG_SFL_SRL_LEFT));
	m_pCommonlyUesedLayout = new CommonlyUsedLayout(psrl);
}

void CMainDialog::OnNcDestroy(BOOL& bHandle)
{
	bHandle = FALSE;
	PostQuitMessage(0);
}

void CMainDialog::OnSize(UINT nType, UI::CSize size, BOOL& bHandle)
{
	//��������ѡ��Ŀ���
	CSkinRadioGroup* pCSRG = static_cast<CSkinRadioGroup*>(GetChildById(100));
	if (pCSRG != NULL)
	{
		pCSRG->SetLayoutWidth(size.cx - 24);//����Ϊʲô��24�����ݲ��Եó�
		//����ѡ�λ��
		CSkinRadioButton* pSRBLeft = static_cast<CSkinRadioButton*>(GetChildById(101));
		if (pSRBLeft != NULL)
		{
			pSRBLeft->SetLayoutWidth((size.cx - 24) / 2);
		}
		CSkinRadioButton* pSRBRight = static_cast<CSkinRadioButton*>(GetChildById(102));
		if (pSRBRight != NULL)
		{
			pSRBRight->SetLayoutAlignParentLeft((size.cx - 24) / 2);
			pSRBRight->SetLayoutWidth((size.cx - 24) / 2);
		}
	}
	CSkinDialog::OnSize(nType, size, bHandle);
}

void CMainDialog::OnRadioButtonClicked(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if (nID == IDC_MAIN_DLG_SRB_LEFT_BTN)
	{
		this->m_iCurrentSelectedTable = COMMONLY_USED;
	}
	else if (nID == IDC_MAIN_DLG_SRB_RIGHT_BTN)
	{
		this->m_iCurrentSelectedTable = CLASSIFICATION;
	}
}

void CMainDialog::OnRButtonDown(UINT nType, CPoint point, BOOL& bHandle)
{
	if (this->m_iCurrentSelectedTable == COMMONLY_USED)
	{
		//���س������˵�
		CRect rect = this->GetRect();
		CPoint pt;
		pt.x = point.x;
		pt.y = point.y;
		this->GetOwner()->ClientToScreen(pt);
		PopupMenu(_T("CommonlyMenu.xml"), pt, rect.Size(), this, PD_UNKNOWN);
	}
	else if (this->m_iCurrentSelectedTable == CLASSIFICATION)
	{

	}
}


void CMainDialog::OnMenuCommandAddCommonlyUsedItem(UINT uNotifyCode, int nID, CSkinView* pView)
{
	//���Դ���
	//this->m_pCommonlyUesedLayout->AddAppItem(_T("test.ico"), _T("����"), _T("����"));
	TCHAR* filter = _T("Ƥ���ļ�(*.exe)\0*.exe\0\0");
	CSkinFileDialog dlg(_T("ѡ��Ӧ��"), filter, 5, TRUE);
	if (dlg.DoModal(m_hWnd) == IDOK)
	{
		IconSnap is;
		const list<tstring>& lstFile = dlg.GetFile();
		list<tstring>::const_iterator lstFileIterator;
		for (lstFileIterator = lstFile.begin(); lstFileIterator != lstFile.end(); ++lstFileIterator)
		{
			tstring fileName = *lstFileIterator;
			//��ȡͼ��
			wstring appName;
			wstring iconName;
			wstring path = GetProgramDir();
			path += _T("\\res\\DTTools\\image\\");
			int nameStart = fileName.find_last_of(_T("\\"), fileName.length()) + 1;
			int nameEnd = fileName.find_last_of(_T("."), fileName.length());
			appName = fileName.substr(nameStart, nameEnd - nameStart);
			iconName += appName;
			iconName += _T(".png");
			path += iconName;
			//is.ExtractIconToFile(fileName.c_str(), path.c_str());
			HICON hIcon = is.ExtractIconW(fileName.c_str());
			is.SaveHIconToPngFile(hIcon, path.c_str());
			//�����ݿ�

			//���½���
			this->m_pCommonlyUesedLayout->AddAppItem(iconName.c_str(), appName.c_str(), fileName.c_str());
		}

	}
}

void CMainDialog::OnMenuCommandDeleteCommonlyUsedItem(UINT uNotifyCode, int nID, CSkinView* pView)
{
	this->m_pCommonlyUesedLayout->DeleteSelectedAppItem();
}

wstring CMainDialog::GetProgramDir()
{
	TCHAR exeFullPath[MAX_PATH]; // Full path   
	wstring strPath = _T("");
	GetModuleFileName(NULL, exeFullPath, MAX_PATH);
	strPath = (wstring)exeFullPath;    // Get full path of the file   
	int pos = strPath.find_last_of('\\', strPath.length());
	return strPath.substr(0, pos);  // Return the directory without the file name
}
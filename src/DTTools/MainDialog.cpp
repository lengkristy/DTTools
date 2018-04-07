#include "stdafx.h"
#include "MainDialog.h"
#include "Core\IconSnap.h"
#include "Core\Command.h"
#include "sqlite\SQLite3Opt.h"

SKINUI_BEGIN_MESSAGE_MAP(CMainDialog, CSkinDialog)
	ON_SKINUI_WM_NCDESTROY()
	ON_SKINUI_WM_SIZE() //映射大小改变消息
	ON_SKINUI_WM_RBUTTONDOWN()//鼠标右键按下
	ON_SKINUI_COMMAND(IDC_MAIN_DLG_SRB_LEFT_BTN, OnRadioButtonClicked)//常用列表选项卡被选择
	ON_SKINUI_COMMAND(IDC_MAIN_DLG_SRB_RIGHT_BTN, OnRadioButtonClicked)//常用列表选项卡被选择
	ON_SKINUI_COMMAND(IDC_MAIN_MENU_COMMONLY_ADD_ITEM, OnMenuCommandAddCommonlyUsedItem)//菜单被点击
	ON_SKINUI_COMMAND(IDC_MAIN_MENU_COMMONLY_DELETE_ITEM, OnMenuCommandDeleteCommonlyUsedItem)//菜单被点击
SKINUI_END_MESSAGE_MAP()

CMainDialog::CMainDialog()
: CSkinDialog(_T("MainDialog.xml"))
{
	m_pCommonlyUesedLayout = NULL;
	m_iCurrentSelectedTable = COMMONLY_USED;//默认为常用table页
}

CMainDialog::~CMainDialog()
{
	if (m_pCommonlyUesedLayout != NULL)
	{
		//DeleteChild(m_pCommonlyUesedLayout); 释放资源
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
	SQLite3Opt sqlite("C:\\Users\\lengyue\\Desktop\\1.db");
	if (!sqlite.Connect())
	{
		return;
	}
	int i = sqlite.ExecuteNonQuery("insert into test(name) values('sasa')");
	sqlite.ExcecuteQuery("SELECT * FROM test");
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
	//重新设置选项卡的宽度
	CSkinRadioGroup* pCSRG = static_cast<CSkinRadioGroup*>(GetChildById(100));
	if (pCSRG != NULL)
	{
		pCSRG->SetLayoutWidth(size.cx - 24);//至于为什么减24，根据测试得出
		//设置选项卡位置
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
		//加载常用面板菜单
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
	//测试代码
	//this->m_pCommonlyUesedLayout->AddAppItem(_T("test.ico"), _T("测试"), _T("测试"));
	TCHAR* filter = _T("皮肤文件(*.exe)\0*.exe\0\0");
	CSkinFileDialog dlg(_T("选择应用"), filter, 5, TRUE);
	if (dlg.DoModal(m_hWnd) == IDOK)
	{
		IconSnap is;
		const list<tstring>& lstFile = dlg.GetFile();
		list<tstring>::const_iterator lstFileIterator;
		for (lstFileIterator = lstFile.begin(); lstFileIterator != lstFile.end(); ++lstFileIterator)
		{
			tstring fileName = *lstFileIterator;
			//提取图标
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
			//存数据库

			//更新界面
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
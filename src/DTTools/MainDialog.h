#pragma once
#include "Layout\CommonlyUsedLayout.h"
class CMainDialog : public CSkinDialog
{
public:
	//����ؼ�IDö��
	enum
	{
		IDC_MAIN_DLG_SRG_TAB = 100,
		IDC_MAIN_DLG_SRB_LEFT_BTN = 101,
		IDC_MAIN_DLG_SRB_RIGHT_BTN = 102,
		IDC_MAIN_DLG_SFL = 1000,
		IDC_MAIN_DLG_SFL_SRL_LEFT = 1100,
		IDC_MAIN_DLG_SFL_SRL_RIGHT = 1200
	};
	//���ò˵���ö��
	enum
	{
		IDC_MAIN_MENU_COMMONLY_ADD_ITEM = 40001,
		IDC_MAIN_MENU_COMMONLY_DELETE_ITEM = 40002
	};
	//����ѡ���ѡ���ö��
	enum
	{
		COMMONLY_USED = 1,//����
		CLASSIFICATION = 2//����
	};
public:
	CMainDialog();
	~CMainDialog();
	void CreateCommonlyUsedLayout();//�����������
	void LoadCommonResource();//���ع�����Դ
private:
	CommonlyUsedLayout *m_pCommonlyUesedLayout;//������岼��
	unsigned int m_iCurrentSelectedTable;//��ǰѡ��tabҳ��

public:
	virtual void OnInitDialog();

protected:
	void OnNcDestroy(BOOL& bHandle);
	void OnSize(UINT nType, CSize size, BOOL& bHandle);
	void OnRButtonDown(UINT nType, CPoint point, BOOL& bHandle);
	void OnRadioButtonClicked(UINT uNotifyCode, int nID, CSkinView* pView);//ѡ���ѡ��
	void OnMenuCommandAddCommonlyUsedItem(UINT uNotifyCode, int nID, CSkinView* pView);//����������˵�����¼�
	void OnMenuCommandDeleteCommonlyUsedItem(UINT uNotifyCode, int nID, CSkinView* pView);//����ɾ����˵�����¼�
	SKINUI_DECLARE_MESSAGE_MAP()
public:
	wstring GetProgramDir();//��ȡ��������Ŀ¼
};
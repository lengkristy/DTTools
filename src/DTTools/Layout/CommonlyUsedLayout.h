#pragma once
#include "CommonlyUsedItem.h"

class CommonlyUsedLayout : public CSkinRelativeLayout
{
public:
	//����ؼ�IDö��
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
	LRESULT OnListItemLBDBClick(WPARAM wParam, LPARAM lParam);//�б�˫��
	SKINUI_DECLARE_MESSAGE_MAP()
public:
	void InitResource();//��ʼ����Դ
	void DeleteSelectedAppItem();//ɾ����ѡ���app��Ŀ
	void AddAppItem(const TCHAR* imageName,const TCHAR* appName,const TCHAR* appPath);//�����
private:
	CSkinListView* m_pListCU;//�����б�
	CommonlyUsedItem* m_pComputerItem;//�ҵĵ�����
	list<CommonlyUsedItem*> m_pListItem;//item��
};
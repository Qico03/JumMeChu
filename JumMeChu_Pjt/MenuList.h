#pragma once
#include "afxcmn.h"


// MenuList ��ȭ �����Դϴ�.

class MenuList : public CDialog
{
	DECLARE_DYNAMIC(MenuList)

public:
	MenuList(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~MenuList();
	CString GetCurrentFilePath();//���������� �ּҸ� �ҷ��´�
	int Chkmenu_ea();//�޴������� ����� �˷��ִ� �Լ�
	
// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MENULIST };
private:
	CWnd		*m_pMomWnd;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();
public:

	DECLARE_MESSAGE_MAP()
	CListCtrl m_MenuList;
	void SetMenuList();
};

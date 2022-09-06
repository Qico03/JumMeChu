// MenuList.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "JumMeChu_Pjt.h"
#include "JumMeChu_PjtDlg.h"
#include "MenuList.h"
#include "afxdialogex.h"


// MenuList ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(MenuList, CDialog)

MenuList::MenuList(CWnd* pParent /*=NULL*/)
	: CDialog(MenuList::IDD, pParent)
{

}

MenuList::~MenuList()
{
}

void MenuList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_MENU, m_MenuList);
}

BOOL MenuList::OnInitDialog()
{
	CDialog::OnInitDialog();
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	m_MenuList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES | LVS_EX_GRIDLINES);
	m_MenuList.DeleteAllItems();
	m_MenuList.InsertColumn(1, _T("�޴�"), LVCFMT_RIGHT, 100, -1);
	m_MenuList.InsertColumn(0, _T("No"), LVCFMT_LEFT, 40, -1);
	SetMenuList();
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	return TRUE;
}


BEGIN_MESSAGE_MAP(MenuList, CDialog)
END_MESSAGE_MAP()

void MenuList::SetMenuList()
{
	char c_buf[255] = { 0, };
	int i_res;
	CString strPath = GetCurrentFilePath();
	CString strPrintFile, cs_buf, cs_step;
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	int i_chkmenu = Chkmenu_ea();
	strPrintFile.Format(_T("%s\\%s"), strPath, "init.ini");
	for (int i = 1; i <= i_chkmenu; i++)
	{
		cs_step.Format(_T("%d"), i);
		GetPrivateProfileString("������", cs_step, "-", c_buf, 255, strPrintFile);
		cs_buf = c_buf;
		m_MenuList.InsertItem(i, cs_step);
		m_MenuList.SetItemText(i-1, 1, cs_buf);
	}
}

CString MenuList::GetCurrentFilePath()//���������� �ּҸ� �ҷ��´�
{
	TCHAR szFileName[MAX_PATH];

	GetModuleFileName(NULL, szFileName, MAX_PATH);

	CString strFilePath;
	strFilePath.Format(_T("%s"), szFileName);

	strFilePath = strFilePath.Left(strFilePath.ReverseFind('\\'));

	return strFilePath;
}

int MenuList::Chkmenu_ea()//�޴������� ����� �˷��ִ� �Լ�
{
	char c_buf[255] = { 0, };
	int i_res;
	CString strPath = GetCurrentFilePath();
	CString strPrintFile;
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	strPrintFile.Format(_T("%s\\%s"), strPath, "init.ini");
	GetPrivateProfileString("�޴�����", "EA", "0", c_buf, 255, strPrintFile);
	i_res = atoi(c_buf);
	return i_res;
}

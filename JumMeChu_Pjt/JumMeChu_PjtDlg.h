
// JumMeChu_PjtDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include <iostream>
#include <string>
#include <math.h>
#include <time.h>
#include "MenuList.h"
#define default		_T("������")
// CJumMeChu_PjtDlg ��ȭ ����
class CJumMeChu_PjtDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CJumMeChu_PjtDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	void LogWriteToFile(CString szMsg);
	CString ExePathSearch();
	CString GetCurrentFilePath();
	int Chkmenu_ea();
	BOOL Menu_overlap(CString cs_buf);
	int i_menu = 0;
	MenuList *m_MenulistDlg;


// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_JUMMECHU_PJT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSave();
	CEdit m_AddMenu;
	afx_msg void OnBnClickedButtonJmc();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonMenu();
	afx_msg void OnDestroy();
};


// JumMeChu_PjtDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include <iostream>
#include <string>
#include <math.h>
#include <time.h>
#include "MenuList.h"
#define default		_T("점메추")
// CJumMeChu_PjtDlg 대화 상자
class CJumMeChu_PjtDlg : public CDialogEx
{
// 생성입니다.
public:
	CJumMeChu_PjtDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	void LogWriteToFile(CString szMsg);
	CString ExePathSearch();
	CString GetCurrentFilePath();
	int Chkmenu_ea();
	BOOL Menu_overlap(CString cs_buf);
	int i_menu = 0;
	MenuList *m_MenulistDlg;


// 대화 상자 데이터입니다.
	enum { IDD = IDD_JUMMECHU_PJT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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

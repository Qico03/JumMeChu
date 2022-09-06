#pragma once
#include "afxcmn.h"


// MenuList 대화 상자입니다.

class MenuList : public CDialog
{
	DECLARE_DYNAMIC(MenuList)

public:
	MenuList(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~MenuList();
	CString GetCurrentFilePath();//현재파일의 주소를 불러온다
	int Chkmenu_ea();//메뉴개수가 몇개인지 알려주는 함수
	
// 대화 상자 데이터입니다.
	enum { IDD = IDD_MENULIST };
private:
	CWnd		*m_pMomWnd;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();
public:

	DECLARE_MESSAGE_MAP()
	CListCtrl m_MenuList;
	void SetMenuList();
};


// JumMeChu_PjtDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "JumMeChu_Pjt.h"
#include "JumMeChu_PjtDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CJumMeChu_PjtDlg 대화 상자



CJumMeChu_PjtDlg::CJumMeChu_PjtDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CJumMeChu_PjtDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJumMeChu_PjtDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ADDMENU, m_AddMenu);
}

BEGIN_MESSAGE_MAP(CJumMeChu_PjtDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CJumMeChu_PjtDlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_JMC, &CJumMeChu_PjtDlg::OnBnClickedButtonJmc)
	ON_BN_CLICKED(IDC_BUTTON_MENU, &CJumMeChu_PjtDlg::OnBnClickedButtonMenu)
END_MESSAGE_MAP()


// CJumMeChu_PjtDlg 메시지 처리기

BOOL CJumMeChu_PjtDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	i_menu = Chkmenu_ea();
	// 	m_MenulistDlg = new MenuList;
	// 	m_MenulistDlg->Create(IDD_MENULIST);
	// 	m_MenulistDlg->ShowWindow(SW_SHOW);
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CJumMeChu_PjtDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CJumMeChu_PjtDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;	
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CJumMeChu_PjtDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
CString CJumMeChu_PjtDlg::ExePathSearch()
{
	TCHAR			folderPath[2048];
	CString			str;

	::GetModuleFileName(NULL, folderPath, 2048); // MFC 실행 파일이 있는 경로 구해옴
	PathRemoveFileSpec(folderPath);            //MFC 실행파일 이름 삭제후 경로만 구해옴
	str.Format((_T("%s")), folderPath);
	return str;
}
void CJumMeChu_PjtDlg::LogWriteToFile(CString szMsg)
{
	SYSTEMTIME _starttime;
	GetLocalTime(&_starttime);

	CString szTime;
	szTime.Format(_T("[%02d:%02d:%02d:%04d]")
		, _starttime.wHour
		, _starttime.wMinute
		, _starttime.wSecond
		, _starttime.wMilliseconds);

	CString szExePath = ExePathSearch();

	// 현재실행폴더/LOG/현재년월일/Luritech.log 에 저장
	CString szDir = szExePath + _T("\\") + _T("Log");
	CreateDirectory(szDir, NULL);

	CString szDate = _T("");
	szDate.Format(_T("%04d%02d%02d"), _starttime.wYear, _starttime.wMonth, _starttime.wDay);
	szDir = szDir + _T("\\") + szDate;
	CreateDirectory(szDir, NULL);

	CFile file;
	CFileFind filefind;
	CString szfile = szDir + _T("\\") + _T("LYM.log");

	if (!filefind.FindFile(szfile))
		file.Open(szfile, CFile::modeCreate | CFile::modeWrite);
	else
		file.Open(szfile, CFile::modeWrite);

	CString szTemp = _T("");

	szTemp.Format(_T("%s%s\r\n"), szTime, szMsg);

	file.SeekToEnd();
	file.Write(szTemp, szTemp.GetLength());
	file.Close();
}

CString CJumMeChu_PjtDlg::GetCurrentFilePath()//현재파일의 주소를 불러온다
{
	TCHAR szFileName[MAX_PATH];

	GetModuleFileName(NULL, szFileName, MAX_PATH);

	CString strFilePath;
	strFilePath.Format(_T("%s"), szFileName);

	strFilePath = strFilePath.Left(strFilePath.ReverseFind('\\'));

	return strFilePath;
}

void CJumMeChu_PjtDlg::OnBnClickedButtonSave()//메뉴추가를 하고싶을때 누르는함수
{
	CString strPath = GetCurrentFilePath();
	CString  cstr_Buf, cs_menu, szMsgBuf;
	CString strPrintFile;
	strPrintFile.Format(_T("%s\\%s"), strPath, "init.ini");
	CString str = "";
	m_AddMenu.GetWindowText(cstr_Buf);
	CFileFind find;
//------------------------------------------------------------------------------------------------------------------------------------------------------------
	if (find.FindFile(strPrintFile) == FALSE)
		return;
//------------------------------------------------------------------------------------------------------------------------------------------------------------
	if (cstr_Buf.IsEmpty() == TRUE)
	{
		m_AddMenu.SetWindowText("");
		return;
	}
	else if (!Menu_overlap(cstr_Buf))
	{
		AfxMessageBox("이미 있는 메뉴입니다.");
		m_AddMenu.SetWindowText("");
		return;
	}
	else
	{
		i_menu++;
		cs_menu.Format(_T("%d"), i_menu);//순서int->cstring
		WritePrivateProfileString("점메추", cs_menu, cstr_Buf, strPrintFile);
		szMsgBuf.Format(_T("[ADD]Menu:%s"), cstr_Buf);
		LogWriteToFile(szMsgBuf);
		WritePrivateProfileString("메뉴개수", "EA", cs_menu, strPrintFile);
		m_AddMenu.SetWindowText("");
	}
//------------------------------------------------------------------------------------------------------------------------------------------------------------
}

void CJumMeChu_PjtDlg::OnBnClickedButtonJmc()//이 앱을 구동시키는 메인 start함수(점심메뉴를 추천해준다.)
{
	int i_rand;
	char c_buf[255] = { 0, };
	int i_res;
	CString strPath = GetCurrentFilePath();
	CString strPrintFile, cs_res, cs_buf, cs_rand;
	srand(time(NULL));
	i_rand = rand()%(i_menu)+1;
	cs_rand.Format(_T("%d"), i_rand);
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	strPrintFile.Format(_T("%s\\%s"), strPath, "init.ini");
	GetPrivateProfileString("점메추", cs_rand, "0", c_buf, 255, strPrintFile);
	cs_buf = c_buf;
	cs_res.Format(_T("오늘의 점심은 %s를 추천합니다!"), cs_buf);
	AfxMessageBox(cs_res);

}

int CJumMeChu_PjtDlg::Chkmenu_ea()//메뉴개수가 몇개인지 알려주는 함수
{
	char c_buf[255] = { 0, };
	int i_res;
	CString strPath = GetCurrentFilePath();
	CString strPrintFile;
//------------------------------------------------------------------------------------------------------------------------------------------------------------
	strPrintFile.Format(_T("%s\\%s"), strPath, "init.ini");
	GetPrivateProfileString("메뉴개수", "EA", "0", c_buf, 255, strPrintFile);
	i_res = atoi(c_buf);
	return i_res;
}
BOOL CJumMeChu_PjtDlg::Menu_overlap(CString cs_buf)//중복되는 메뉴가 추가될시 예외처리시키는 함수
{
//--선언부----------------------------------------------------------------------------------------------------------------------------------------------------------
	bool bRes = TRUE;
	CString strPath = GetCurrentFilePath();
	CString  cstr_Buf, cs_menu, szMsgBuf, cs_comp;
	CString strPrintFile;
	char c_buf[255] = { 0, };
//------------------------------------------------------------------------------------------------------------------------------------------------------------
	strPrintFile.Format(_T("%s\\%s"), strPath, "init.ini");
	for (int i = 1; i <= i_menu; i++)
	{
		CString cs_step;
		cs_step.Format(_T("%d"), i);
		GetPrivateProfileString("점메추", cs_step, "Nothing",  c_buf, 255, strPrintFile);
		cs_comp = c_buf;
		if (cs_buf == cs_comp)
		{
			bRes = FALSE;
			szMsgBuf.Format(_T("[ERR]overlap:%s"), cs_buf);
			LogWriteToFile(szMsgBuf);
			return bRes;
		}
		else
			bRes = TRUE;
	}
	return bRes;
}
BOOL CJumMeChu_PjtDlg::PreTranslateMessage(MSG* pMsg)// esc또는 엔터키로 종료되지않는다
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_RETURN)
			return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CJumMeChu_PjtDlg::OnBnClickedButtonMenu()
{
	if (m_MenulistDlg == NULL)//창이 띄워진상태에선 더이상 창이 뜨지 않게 예외처리
	{
		m_MenulistDlg = new MenuList(this);
		m_MenulistDlg->Create(IDD_MENULIST, this);
		m_MenulistDlg->ShowWindow(SW_SHOW);
		m_MenulistDlg = NULL;
	}
}

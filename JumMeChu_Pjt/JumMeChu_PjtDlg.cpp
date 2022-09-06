
// JumMeChu_PjtDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "JumMeChu_Pjt.h"
#include "JumMeChu_PjtDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CJumMeChu_PjtDlg ��ȭ ����



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


// CJumMeChu_PjtDlg �޽��� ó����

BOOL CJumMeChu_PjtDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	i_menu = Chkmenu_ea();
	// 	m_MenulistDlg = new MenuList;
	// 	m_MenulistDlg->Create(IDD_MENULIST);
	// 	m_MenulistDlg->ShowWindow(SW_SHOW);
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CJumMeChu_PjtDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;	
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CJumMeChu_PjtDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
CString CJumMeChu_PjtDlg::ExePathSearch()
{
	TCHAR			folderPath[2048];
	CString			str;

	::GetModuleFileName(NULL, folderPath, 2048); // MFC ���� ������ �ִ� ��� ���ؿ�
	PathRemoveFileSpec(folderPath);            //MFC �������� �̸� ������ ��θ� ���ؿ�
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

	// �����������/LOG/��������/Luritech.log �� ����
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

CString CJumMeChu_PjtDlg::GetCurrentFilePath()//���������� �ּҸ� �ҷ��´�
{
	TCHAR szFileName[MAX_PATH];

	GetModuleFileName(NULL, szFileName, MAX_PATH);

	CString strFilePath;
	strFilePath.Format(_T("%s"), szFileName);

	strFilePath = strFilePath.Left(strFilePath.ReverseFind('\\'));

	return strFilePath;
}

void CJumMeChu_PjtDlg::OnBnClickedButtonSave()//�޴��߰��� �ϰ������ �������Լ�
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
		AfxMessageBox("�̹� �ִ� �޴��Դϴ�.");
		m_AddMenu.SetWindowText("");
		return;
	}
	else
	{
		i_menu++;
		cs_menu.Format(_T("%d"), i_menu);//����int->cstring
		WritePrivateProfileString("������", cs_menu, cstr_Buf, strPrintFile);
		szMsgBuf.Format(_T("[ADD]Menu:%s"), cstr_Buf);
		LogWriteToFile(szMsgBuf);
		WritePrivateProfileString("�޴�����", "EA", cs_menu, strPrintFile);
		m_AddMenu.SetWindowText("");
	}
//------------------------------------------------------------------------------------------------------------------------------------------------------------
}

void CJumMeChu_PjtDlg::OnBnClickedButtonJmc()//�� ���� ������Ű�� ���� start�Լ�(���ɸ޴��� ��õ���ش�.)
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
	GetPrivateProfileString("������", cs_rand, "0", c_buf, 255, strPrintFile);
	cs_buf = c_buf;
	cs_res.Format(_T("������ ������ %s�� ��õ�մϴ�!"), cs_buf);
	AfxMessageBox(cs_res);

}

int CJumMeChu_PjtDlg::Chkmenu_ea()//�޴������� ����� �˷��ִ� �Լ�
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
BOOL CJumMeChu_PjtDlg::Menu_overlap(CString cs_buf)//�ߺ��Ǵ� �޴��� �߰��ɽ� ����ó����Ű�� �Լ�
{
//--�����----------------------------------------------------------------------------------------------------------------------------------------------------------
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
		GetPrivateProfileString("������", cs_step, "Nothing",  c_buf, 255, strPrintFile);
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
BOOL CJumMeChu_PjtDlg::PreTranslateMessage(MSG* pMsg)// esc�Ǵ� ����Ű�� ��������ʴ´�
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
	if (m_MenulistDlg == NULL)//â�� ��������¿��� ���̻� â�� ���� �ʰ� ����ó��
	{
		m_MenulistDlg = new MenuList(this);
		m_MenulistDlg->Create(IDD_MENULIST, this);
		m_MenulistDlg->ShowWindow(SW_SHOW);
		m_MenulistDlg = NULL;
	}
}

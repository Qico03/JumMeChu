
// JumMeChu_Pjt.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CJumMeChu_PjtApp:
// �� Ŭ������ ������ ���ؼ��� JumMeChu_Pjt.cpp�� �����Ͻʽÿ�.
//

class CJumMeChu_PjtApp : public CWinApp
{
public:
	CJumMeChu_PjtApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CJumMeChu_PjtApp theApp;
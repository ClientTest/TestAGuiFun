
// TestAGuiFun.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestAGuiFunApp:
// �йش����ʵ�֣������ TestAGuiFun.cpp
//

class CTestAGuiFunApp : public CWinApp
{
public:
	CTestAGuiFunApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestAGuiFunApp theApp;
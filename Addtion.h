
// Addtion.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAddtionApp:
// �йش����ʵ�֣������ Addtion.cpp
//

class CAddtionApp : public CWinApp
{
public:
	CAddtionApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAddtionApp theApp;
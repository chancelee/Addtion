
// AddtionDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Addtion.h"
#include "AddtionDlg.h"
#include "afxdialogex.h"
#include "AddSheet.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CAddtionDlg 对话框




CAddtionDlg::CAddtionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddtionDlg::IDD, pParent)
{
	m_pTipDlg = NULL;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_editAddend = 0.0;
	m_editSum = 0.0;
	m_editSummand = 0.0;
}

void CAddtionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ADDEND_EDIT, m_editAddend);
	DDX_Text(pDX, IDC_SUM_EDIT, m_editSum);
	DDX_Text(pDX, IDC_SUMMAND_EDIT, m_editSummand);
}

BEGIN_MESSAGE_MAP(CAddtionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CAddtionDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddtionDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_INSTRUCT_BUTTON, &CAddtionDlg::OnBnClickedInstructButton)
END_MESSAGE_MAP()


// CAddtionDlg 消息处理程序

BOOL CAddtionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAddtionDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAddtionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAddtionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAddtionDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CAddtionDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//INT_PTR nRes;
	//CTipDlg tipDlg;
	//nRes = tipDlg.DoModal();
	//if(IDCANCEL==nRes)
	//	return ;
	if(NULL == m_pTipDlg)
	{
		//创建非模态对话框实例
		m_pTipDlg = new CTipDlg();
		m_pTipDlg->Create(IDD_TIP_DIALOG,this);
	}
	m_pTipDlg->ShowWindow(SW_SHOW);
	//将各控件中的数据保存到相应的变量
	UpdateData(TRUE);
	m_editSum = m_editSummand+m_editAddend;
	UpdateData(FALSE);
}

CAddtionDlg::~CAddtionDlg()
{
	if(NULL != m_pTipDlg)
	{
		delete m_pTipDlg;
	}
}

void CAddtionDlg::OnBnClickedInstructButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CAddSheet sheet(_T(""));
	sheet.SetWizardMode();
	sheet.DoModal();
}

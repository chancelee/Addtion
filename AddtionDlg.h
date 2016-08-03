
// AddtionDlg.h : 头文件
//

#pragma once
#include "TipDlg.h"

// CAddtionDlg 对话框
class CAddtionDlg : public CDialogEx
{
// 构造
public:
	CTipDlg *m_pTipDlg;
public:
	CAddtionDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CAddtionDlg();
// 对话框数据
	enum { IDD = IDD_ADDTION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	double m_editAddend;
	double m_editSum;
	double m_editSummand;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedInstructButton();
};

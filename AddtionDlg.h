
// AddtionDlg.h : ͷ�ļ�
//

#pragma once
#include "TipDlg.h"

// CAddtionDlg �Ի���
class CAddtionDlg : public CDialogEx
{
// ����
public:
	CTipDlg *m_pTipDlg;
public:
	CAddtionDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CAddtionDlg();
// �Ի�������
	enum { IDD = IDD_ADDTION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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

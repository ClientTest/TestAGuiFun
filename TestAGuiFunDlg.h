
// TestAGuiFunDlg.h : ͷ�ļ�
//

#pragma once
#include "AGuiLOG/IAGuiLOG.h"

// CTestAGuiFunDlg �Ի���
class CTestAGuiFunDlg : public CDialogEx
{
// ����
public:
	CTestAGuiFunDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TESTAGUIFUN_DIALOG };

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
	afx_msg void OnDestroy();
};

#pragma once
#include "afxcmn.h"


// Info �Ի���

class Info : public CDialog
{
	DECLARE_DYNAMIC(Info)

public:
	Info(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Info();

// �Ի�������
	enum { IDD = IDD_INFOMATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton2();
	
	CListCtrl m_list;
	afx_msg void OnBnClickedButton1();
};

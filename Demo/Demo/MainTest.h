#pragma once
#include "afxcmn.h"


// MainTest �Ի���

class MainTest : public CDialogEx
{
	DECLARE_DYNAMIC(MainTest)

public:
	MainTest(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MainTest();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CTabCtrl m_tab;
	HMENU m_hMenu1;
	int power;
	CString number;

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnIdrMenu2();
	afx_msg void OnIdrMenu1();
	afx_msg void Onyuangon();
	afx_msg void OnChaxun();
	afx_msg void OnHelp();
	afx_msg void OnExit();
	afx_msg void Onaboutme();
	afx_msg void OnGer();
};

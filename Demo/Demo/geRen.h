#pragma once


// geRen �Ի���

class geRen : public CDialog
{
	DECLARE_DYNAMIC(geRen)

public:
	geRen(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~geRen();

// �Ի�������
	enum { IDD = IDD_GEREN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString NUM;
	int ReplaceText(CString ,CString,CString);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

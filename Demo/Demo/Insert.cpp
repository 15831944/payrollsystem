// Insert.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Demo.h"
#include "Insert.h"
#include "afxdialogex.h"
#include "MainTest.h"

// Insert �Ի���

IMPLEMENT_DYNAMIC(Insert, CDialogEx)

Insert::Insert(CWnd* pParent /*=NULL*/)
	: CDialogEx(Insert::IDD, pParent)
{

}

Insert::~Insert()
{
}

void Insert::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Insert, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON5, &Insert::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON1, &Insert::OnBnClickedButton1)
END_MESSAGE_MAP()


// Insert ��Ϣ�������


BOOL Insert::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	return TRUE;  // return TRUE unless you set the focus to a control

}


void Insert::OnBnClickedButton5()
{
Insert:OnOK();
}


void Insert::OnBnClickedButton1()
{
	// �����ļ�
	CString number,name,age,work,salary,password;  
    
	((CEdit*)this->GetDlgItem(IDC_NUMBER))->GetWindowText(number);
	((CEdit*)this->GetDlgItem(IDC_NAME))->GetWindowText(name);
	((CEdit*)this->GetDlgItem(IDC_AGE))->GetWindowText(age);
	((CEdit*)this->GetDlgItem(IDC_WORK))->GetWindowText(work);
	((CEdit*)this->GetDlgItem(IDC_SALARY))->GetWindowText(salary);
	((CEdit*)this->GetDlgItem(IDC_Test))->GetWindowText(password);
	
	CString pszFileName=_T("res/file/info.txt");

CStdioFile myFile;

CFileException fileException;

if(myFile.Open(pszFileName,CFile::typeText|CFile::modeReadWrite))

	{
		myFile.SeekToEnd();
		myFile.WriteString(number+" "+name+" "+password+" "+age+" "+work+" "+salary+"\n");
	MessageBox(TEXT("����ɹ���"),NULL,MB_OK);
	GetDlgItem(IDC_NUMBER)->SetWindowText(_T(""));
	GetDlgItem(IDC_NAME)->SetWindowText(_T(""));
	GetDlgItem(IDC_AGE)->SetWindowText(_T(""));
	GetDlgItem(IDC_WORK)->SetWindowText(_T(""));
	GetDlgItem(IDC_SALARY)->SetWindowText(_T(""));

	}

else

{

TRACE("Can't open file %s,error=%u\n",pszFileName,fileException.m_cause);

}

myFile.Close();
	

	
}

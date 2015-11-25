// geRen.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Demo.h"
#include "geRen.h"
#include "afxdialogex.h"
#include "Search.h"

// geRen �Ի���

IMPLEMENT_DYNAMIC(geRen, CDialog)

geRen::geRen(CWnd* pParent /*=NULL*/)
	: CDialog(geRen::IDD, pParent)
{

}

geRen::~geRen()
{
}

void geRen::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(geRen, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &geRen::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &geRen::OnBnClickedButton2)
END_MESSAGE_MAP()


// geRen ��Ϣ�������


BOOL geRen::OnInitDialog()
{
	CDialog::OnInitDialog();

	CString number,name,age,work,salary,pass;   //����һ��CString�������ڱ����ı���ؼ��ڵ��ı�
    
	//��ȡ�ļ�����������Ӧ�û��������Ƿ�ƥ�䣬ƥ������������棬���򵯳�����
	
	CFileFind fileFind;//�����ļ��Ƿ����
	CString strFileName;
	if(NUM=="Admin")
	{
		strFileName = _T("res/file/Admin.txt");
	}
	else
	{
		strFileName = _T("res/file/info.txt");
	}

	if(!fileFind.FindFile(strFileName) )
	{
		::MessageBox(NULL,TEXT("��ȡ�û���Ϣ�ļ�ʧ��"),NULL,MB_OK);
	}

	CStdioFile file;
	file.Open(strFileName,CFile::modeRead);
	CString strText;
	CString strTemp;
	int k=0;
	while(file.ReadString(strTemp))
	{
		//���ж�ȡ���ú��������ַ���
		strText += strTemp;
		AfxExtractSubString ( number, strTemp, 0, ' ');
		AfxExtractSubString ( pass, strTemp, 2, ' ');
		AfxExtractSubString ( name, strTemp, 1, ' ');
		AfxExtractSubString ( age, strTemp, 3, ' ');
		AfxExtractSubString ( work, strTemp, 4, ' ');
		AfxExtractSubString ( salary, strTemp, 5, ' ');
		if(NUM==number)
		{
			GetDlgItem(IDC_EDIT1)->SetWindowText(number);
			GetDlgItem(IDC_EDIT2)->SetWindowText(name);
			GetDlgItem(IDC_EDIT3)->SetWindowText(age);
			GetDlgItem(IDC_EDIT4)->SetWindowText(work);
			GetDlgItem(IDC_EDIT5)->SetWindowText(salary);
			GetDlgItem(IDC_EDIT6)->SetWindowText(pass);
			
		}
		
	}
	file.Close();

	return TRUE;  // return TRUE unless you set the focus to a control
}

void geRen::OnBnClickedButton1()
{
	//��ȡ�ļ�
	CString number,name,age,work,salary,pass,newpass;   //����һ��CString�������ڱ����ı���ؼ��ڵ��ı�
    
	//��ȡ�ļ�����������Ӧ�û��������Ƿ�ƥ�䣬ƥ������������棬���򵯳�����
	
	CFileFind fileFind;//�����ļ��Ƿ����
	CString strFileName;
	strFileName = _T("res/file/info.txt");
	if(!fileFind.FindFile(strFileName) )
	{
		::MessageBox(NULL,TEXT("��ȡ�û���Ϣ�ļ�ʧ��"),NULL,MB_OK);
	}
	((CEdit*)this->GetDlgItem(IDC_EDIT7))->GetWindowText(newpass);
	CStdioFile file;
	file.Open(strFileName,CFile::modeReadWrite);
	CString strText;
	CString strTemp;
	

     while(file.ReadString(strTemp))
	{
		//���ж�ȡ���ú��������ַ���
		strText += strTemp;
		AfxExtractSubString ( number, strTemp, 0, ' ');
		AfxExtractSubString ( name, strTemp, 1, ' ');
		AfxExtractSubString ( age, strTemp, 3, ' ');
		AfxExtractSubString ( work, strTemp, 4, ' ');
		AfxExtractSubString ( salary, strTemp, 5, ' ');
		if(NUM==number)
		{
			file.SeekToEnd();
			file.WriteString(number+" "+name+" "+newpass+" "+age+" "+work+" "+salary+"\n");

			MessageBox(TEXT("�޸ĳɹ���"),NULL,MB_OK);
			break;
			
		}
		
	}
		GetDlgItem(IDC_EDIT6)->SetWindowText(_T(""));
		GetDlgItem(IDC_EDIT7)->SetWindowText(_T(""));
		
        file.Close();
  
	


	
}


void geRen::OnBnClickedButton2()
{
	geRen:OnOK();
}

// Search.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Demo.h"
#include "Search.h"
#include "afxdialogex.h"
#include "MainTest.h"

// Search �Ի���

IMPLEMENT_DYNAMIC(Search, CDialogEx)

Search::Search(CWnd* pParent /*=NULL*/)
	: CDialogEx(Search::IDD, pParent)
{

}

Search::~Search()
{
}

void Search::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
}


BEGIN_MESSAGE_MAP(Search, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON5, &Search::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON1, &Search::OnBnClickedButton1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &Search::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// Search ��Ϣ�������


BOOL Search::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	DWORD style = m_list1.GetExtendedStyle();
	m_list1.SetExtendedStyle(style | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	

	
	m_list1.InsertColumn(0,_T("����"),LVCFMT_LEFT,100,-1);
	m_list1.InsertColumn(1,_T("����"),LVCFMT_LEFT,100,-1);
	m_list1.InsertColumn(2,_T("����"),LVCFMT_LEFT,100,-1);
	m_list1.InsertColumn(3,_T("ְ��"),LVCFMT_LEFT,100,-1);
	m_list1.InsertColumn(4,_T("����"),LVCFMT_LEFT,100,-1);
	
	
	
	return TRUE;
	// �쳣: OCX ����ҳӦ���� FALSE
}


void Search::OnBnClickedButton5()
{
Search:OnOK();

}


void Search::OnBnClickedButton1()
{
	
	//��ȡ�ļ�
	CString number,name,age,work,salary,number1;   //����һ��CString�������ڱ����ı���ؼ��ڵ��ı�
    
	//��ȡ�ļ�����������Ӧ�û��������Ƿ�ƥ�䣬ƥ������������棬���򵯳�����
	
	CFileFind fileFind;//�����ļ��Ƿ����
	CString strFileName;
	strFileName = _T("res/file/info.txt");
	if(!fileFind.FindFile(strFileName) )
	{
		::MessageBox(NULL,TEXT("��ȡ�û���Ϣ�ļ�ʧ��"),NULL,MB_OK);
	}

	CStdioFile file;
	file.Open(strFileName,CFile::modeRead);
	CString strText,shuijin;
	CString strTemp;
	int state=0,k=0;
	m_list1.DeleteAllItems();
	((CEdit*)this->GetDlgItem(IDC_SNU))->GetWindowText(number1);
	while(file.ReadString(strTemp))
	{
		//���ж�ȡ���ú��������ַ���
		strText += strTemp;
		AfxExtractSubString ( number, strTemp, 0, ' ');
		AfxExtractSubString ( name, strTemp, 1, ' ');
		AfxExtractSubString ( age, strTemp, 3, ' ');
		AfxExtractSubString ( work, strTemp, 4, ' ');
		AfxExtractSubString ( salary, strTemp, 5, ' ');
		if(number1==number)
		{
			m_list1.InsertItem(k,number);
			m_list1.SetItemText(k,1,name);
			m_list1.SetItemText(k,2,age);
			m_list1.SetItemText(k,3,work);
			m_list1.SetItemText(k,4,salary);
			state=1;
		}
		
	}
	GetDlgItem(IDC_SNU)->SetWindowText(_T(""));
	if(state==0)
	{
		MessageBox(TEXT("���û������ڣ�"),NULL,MB_OK);
	}
	file.Close();


}


void Search::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	
}

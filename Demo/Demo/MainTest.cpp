// MainTest.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Demo.h"
#include "MainTest.h"
#include "afxdialogex.h"
#include "Info.h"
#include "Insert.h"
#include "Search.h"
#include "geRen.h"

// MainTest �Ի���

IMPLEMENT_DYNAMIC(MainTest, CDialogEx)

MainTest::MainTest(CWnd* pParent /*=NULL*/)
	: CDialogEx(MainTest::IDD, pParent)
{

}

MainTest::~MainTest()
{
}

void MainTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CONTROL, m_tab);
}


BEGIN_MESSAGE_MAP(MainTest, CDialogEx)
	
	
	ON_COMMAND(IDR_MENU1, &MainTest::OnIdrMenu1)
	ON_COMMAND(ID_yuangon, &MainTest::Onyuangon)
	ON_COMMAND(ID_Chaxun, &MainTest::OnChaxun)
	ON_COMMAND(ID_HELP, &MainTest::OnHelp)
	ON_COMMAND(ID_Exit, &MainTest::OnExit)
	ON_COMMAND(ID_aboutme, &MainTest::Onaboutme)
	ON_COMMAND(ID_GER, &MainTest::OnGer)
END_MESSAGE_MAP()


// MainTest ��Ϣ�������


BOOL MainTest::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	 m_hMenu1=LoadMenu(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MENU1));
 ::SetMenu(this->GetSafeHwnd(),m_hMenu1);//��ӵ��Ի���



return TRUE; // return TRUE unless you set the focus to a control
// �쳣: OCX ����ҳӦ���� FALSE
	
	
}






void MainTest::OnIdrMenu1()
{
	//����˵���Ĵ�����룬�������Ӧ����
	//���˵�
  CMenu   *pMenu;  
  pMenu=CMenu::FromHandle(m_hMenu1);//��ò˵�����ָ��
  
  //Ȩ������
  //pMenu->EnableMenuItem(1,MF_BYPOSITION |MF_GRAYED);//����
  ////MF_BYPOSITION��ʾ�����в飬��0��ʼ,��Ϊ���˵�Ϊpopup���ͣ�û��ID��ţ�ֻ�������з�ʽ
  //MF_DISABLED
  pMenu->EnableMenuItem(0,MF_ENABLED);
  pMenu->EnableMenuItem(1,MF_ENABLED);
  pMenu->EnableMenuItem(2,MF_ENABLED);
  pMenu->EnableMenuItem(3,MF_ENABLED);
  pMenu->EnableMenuItem(4,MF_ENABLED);
 

}

void MainTest::Onyuangon()
{
	// ���Ա�����ϲ˵�
	if(number=="Admin")
	{
		Info info;
		info.DoModal();;
	}else
	{
		MessageBox(TEXT("�Բ�������Ȩ��ʹ�ô���ܣ�����鿴������Ϣ���޸�����"),NULL,MB_OK);
	}
	
	
}


void MainTest::OnChaxun()
{
	
	if(number=="Admin")
	{
		Insert insert;
		insert.DoModal();
	}else
	{
		MessageBox(TEXT("�Բ�������Ȩ��ʹ�ô����"),NULL,MB_OK);
	}
	

}


void MainTest::OnHelp()
{
	// 
	if(number=="Admin")
	{
		Search search;
		search.DoModal();
	}
	else
	{
		MessageBox(TEXT("�Բ�������Ȩ��ʹ�ô����"),NULL,MB_OK);
	}

}


void MainTest::OnExit()
{
	MainTest::OnOK();
}


void MainTest::Onaboutme()
{
	MessageBox(TEXT("�ҵĴ���ҵ��"),NULL,MB_OK);
}


void MainTest::OnGer()
{
	//��ʾ������Ϣ
	geRen dlg;
	dlg.NUM=number;
	
	dlg.DoModal();
}

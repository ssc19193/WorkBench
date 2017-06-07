// SscPic.cpp : implementation file
//

#include "stdafx.h"
#include "qrs.h"
#include "SscPic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SscPic dialog


SscPic::SscPic(CWnd* pParent /*=NULL*/)
	: CDialog(SscPic::IDD, pParent)
{
	//{{AFX_DATA_INIT(SscPic)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	picArr[0]=IDB_BITMAP_START;
	picArr[1]=IDB_BITMAP_OUC;
	picArr[2]=IDB_BITMAP_OUCFLAG;
	cPic =0;
}


void SscPic::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SscPic)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP

	//nextPic();
}


BEGIN_MESSAGE_MAP(SscPic, CDialog)
	//{{AFX_MSG_MAP(SscPic)
	ON_BN_CLICKED(IDC_BUTTON_PIC_NEXT, OnButtonPicNext)
	ON_BN_CLICKED(IDC_BUTTON_PIC_CLOSE, OnButtonPicClose)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SscPic message handlers

void SscPic::OnButtonPicNext() 
{
	nextPic();
}

void SscPic::OnButtonPicClose() 
{
	CDialog:OnOK();	
}

void SscPic::nextPic()
{
	//����Դ�м���ͼƬ
	CBitmap bitmap;

	//����ָ��λͼ��Դ BmpͼƬID
	bitmap.LoadBitmap(picArr[cPic]);
	cPic++;
	cPic%=sizeof(picArr)/sizeof( int);
	//��ȡ�Ի����ϵľ�� ͼƬ�ؼ�ID
 	CStatic *p=(CStatic *)GetDlgItem(IDC_STATIC_pic);  
	//���þ�̬�ؼ����ڷ��Ϊλͼ������ʾ
	p->ModifyStyle(0xf,SS_BITMAP|SS_CENTERIMAGE); 
	//��ͼƬ���õ�Picture�ؼ���
	p->SetBitmap(bitmap); 
}

void SscPic::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	nextPic();	
	// Do not call CDialog::OnPaint() for painting messages
}

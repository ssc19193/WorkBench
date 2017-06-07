// qrsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "qrs.h"
#include "qrsDlg.h"
#include "SscPic.h"
#include "SscPinao.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQrsDlg dialog

CQrsDlg::CQrsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQrsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQrsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CQrsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQrsDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CQrsDlg, CDialog)
	//{{AFX_MSG_MAP(CQrsDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_PICDIALOG, OnButtonPicdialog)
	ON_BN_CLICKED(IDC_BUTTON_PINAO, OnButtonPinao)
	ON_BN_CLICKED(IDC_2048, On2048)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQrsDlg message handlers

BOOL CQrsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CQrsDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	//	showPic();
	}
	else
	{
		CDialog::OnPaint();

	}
	//从资源中加载图片
	CBitmap bitmap;
	//加载指定位图资源 Bmp图片ID
	bitmap.LoadBitmap(IDB_BITMAP_START);  
	//获取对话框上的句柄 图片控件ID
 	CStatic *p=(CStatic *)GetDlgItem(IDC_STATIC_pic);  
	//设置静态控件窗口风格为位图居中显示
	p->ModifyStyle(0xf,SS_BITMAP|SS_CENTERIMAGE); 
	//将图片设置到Picture控件上
	p->SetBitmap(bitmap); 
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CQrsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CQrsDlg::OnButtonPicdialog() 
{
	SscPic s;
	s.DoModal();
}

void CQrsDlg::OnButtonPinao() 
{
	// TODO: Add your control notification handler code here
	SscPinao sp;
	sp.DoModal();
}

void CQrsDlg::On2048()
{

}

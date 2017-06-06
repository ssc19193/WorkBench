// SscPinao.cpp : implementation file
//

#include "stdafx.h"
#include "qrs.h"
#include "SscPinao.h"
#include "conio.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int ind[6][4];

/////////////////////////////////////////////////////////////////////////////
// SscPinao dialog


SscPinao::SscPinao(CWnd* pParent /*=NULL*/)
	: CDialog(SscPinao::IDD, pParent)
{
	//{{AFX_DATA_INIT(SscPinao)
	//}}AFX_DATA_INIT

	
	AllocConsole();
	pThead = 0;
	for( int i=0; i<5; i++){
		for( int j=0; j<4; j++){
			ind[i][j]=-1;
		}
	}
	ind[5][1] = 10;
//	ind[4][0]= 10;
//	ind[3][2] = 10;
//	ind[2][3] = 10;
//	ind[1][0]=10;


}


void SscPinao::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SscPinao)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SscPinao, CDialog)
	//{{AFX_MSG_MAP(SscPinao)
	ON_BN_CLICKED(ID_CLOSE, OnClose)
	ON_BN_CLICKED(ID_START, OnStart)
	ON_BN_CLICKED(ID_PAUSE, OnPause)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SscPinao message handlers

void SscPinao::OnClose() 
{
	if( pThead !=0){
		::PostThreadMessage(pThead->m_nThreadID,0,0,0);
	}
	CDialog::OnCancel();
}


BOOL SscPinao::PreTranslateMessage(MSG* pMsg) 
{

	// TODO: Add your specialized code here and/or call the base class
if (pMsg->message == WM_KEYDOWN)  
    {  
	cprintf("%d\n", pMsg->wParam);
        switch(pMsg->wParam)  
        {  
			case 72:// h suspend
				pThead->SuspendThread();
				//::PostThreadMessage(pThead->m_nThreadID,0,0,0);
				return true;
			case 74:
				if( pThead !=0){
					::PostThreadMessage(pThead->m_nThreadID,0,0,0);
					pThead = 0;
				}
				return true;

            case VK_ESCAPE: //Esc按键事件  
				CDialog::OnCancel();
                return true;  
            case VK_RETURN: //Enter按键事件  
                return true; 

			case 65:// A
				pThead->ResumeThread();
				::PostThreadMessage(pThead->m_nThreadID,2,0,0);
				return true;
				 
			case 83:// s
				pThead->ResumeThread();
				::PostThreadMessage(pThead->m_nThreadID,3,0,0);
				return true;
				 
			case 68:// d
				pThead->ResumeThread();
				::PostThreadMessage(pThead->m_nThreadID,4,0,0);
				return true;
				 
			case 70:// f 
				pThead->ResumeThread();
				::PostThreadMessage(pThead->m_nThreadID,5,0,0);
				return true;

            default:  
                ;  
        }  
    } 
	return CDialog::PreTranslateMessage(pMsg);
}

UINT ThreadFunc( LPVOID lpParam)
{
	struct ThreadInfo{
		long nMSec;
		SscPinao *sp;
	};
	struct ThreadInfo* inf = (struct ThreadInfo*) lpParam;

	unsigned long delay =(inf)->nMSec+0;
	int i, j;
	delay = 1000+0;
	int cir=10;
	while( 1){
		MSG msg;
		while(PeekMessage(&msg,NULL,0,0,PM_REMOVE)){      //将消息队列里的消息逐个读入msg
//				cprintf("1--%d\n", msg.message);
			if( msg.message==0){     //如果收到终止消息则退出
				return 0;      //线程正常返回，会释放局部变量等内存资源
			}else{
				cprintf("--%d\n", msg.message);
				if( ind[1][msg.message-2] >= 0){
					ind[1][msg.message-2] = -1;
				}else{
					AfxMessageBox("PRESS ERROR AREA!\nGAME OVER!");
					return 0;
				}
			}
		}
		for( i=0; i<6; i++){
			for( j=0; j<4; j++){
				if( ind[i][j] >= 0){
					ind[i][j]+=10;
				}
			}
		}
		cir++;
		if( cir >= 10){
			cir = 0;
			for( i=0; i<6-1; i++){ // 搬移
				ind[i][0] = ind[i+1][0]-100;
				ind[i][1] = ind[i+1][1]-100;
				ind[i][2] = ind[i+1][2]-100;
				ind[i][3] = ind[i+1][3]-100;
			}
			// 建立新值
			ind[5][0]=-1;
			ind[5][1]=-1;
			ind[5][2]=-1;
			ind[5][3]=-1;
			ind[5][ rand()%4] = 0;

			// 判断遗漏
			if( ind[0][0] >=0 || ind[0][1] >=0 || ind[0][2] >=0 || ind[0][3] >=0 ){
				AfxMessageBox( "YOU MISS ONE!\nGAME OVER!");
				return 1;
			}
			for( i=5; i>=0; i--)
				cprintf("%2d--%5d,%5d,%5d,%5d\n", i, ind[i][0] ,ind[i][1],ind[i][2],ind[i][3]);
		}
//		cprintf("%x", inf->sp);

		inf->sp->flush();
		Sleep( 100);
		if( delay <=0 ){
			return 0;
		}
	}
	return 0;
}
void SscPinao::OnStart() 
{
	if( pThead != 0){
		unsigned long ec;
		GetExitCodeThread( *pThead, &ec);
		cprintf("%x-", ec);
		if( ec == STILL_ACTIVE){
			AfxMessageBox("线程在运行");		
			return;
		}
	}
	info.nMSec = 1000;
	info.sp = this;
	pThead = AfxBeginThread( ThreadFunc, &info);
}

BOOL SscPinao::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void SscPinao::OnPause() 
{
	ind[5][1]+=10;
	flush();
}

void SscPinao::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	CBrush nbw;
	CBrush nbb;
	CBrush nbr;
	CRect c(7, 7, 407, 407);
	int i, j;
	static x = 1;
	

	nbw.CreateSolidBrush( RGB(255,255,255));
	nbb.CreateSolidBrush( RGB(0,0,0));
	nbr.CreateSolidBrush( RGB(255,0,0));
	
	dc.FillRect( c, &nbw);
	
	dc.MoveTo( 107, 7);
	dc.LineTo( 107, 407);
	
	dc.MoveTo( 207, 7);
	dc.LineTo( 207, 407);
	
	dc.MoveTo( 307, 7);
	dc.LineTo( 307, 407);


	for( j=0; j<4; j++){
		if( ind[5][j] >= 0){
			c.left = 7+j*100;
			c.top = 7;
			c.right = 107+j*100;
			c.bottom = ind[5][j]+7;
			dc.FillRect( c, &nbb);

//			cprintf("5:%d-%d,%d,%d,%d\n", j, c.left, c.top, c.right, c.bottom);
		}
	}
	for( i=4; i>1; i--){
		for( j=0; j<4; j++){
			if( ind[i][j] >= 0){
//				cprintf("%d-%d,%d,%d,%d\n", i, c.left, c.top, c.right, c.bottom);
				c.left = 7+j*100;
				c.top = ind[i][j]+7+100*(4-i);
				c.right = 107+j*100;
				c.bottom = ind[i][j]+107+100*(4-i);
				dc.FillRect( c, &nbb);
			}
		}
	}
	for( j=0; j<4; j++){
		if( ind[1][j] >= 0){
			c.left = 7+j*100;
			c.top = 307+ind[1][j];
			c.right = 107+j*100;
			c.bottom = 407;
			dc.FillRect( c, &nbr);
//			cprintf("%d-%d,%d,%d,%d\n", j, c.left, c.top, c.right, c.bottom);
		}
	}
	nbb.DeleteObject();
	nbw.DeleteObject();
	nbr.DeleteObject();


    CDialog::OnPaint();
}

void SscPinao::drawBlock(CDC* memDc, int x, int y )
{
	CDC memDC;	
}

void SscPinao::flush()
{
	SendMessage( WM_PAINT, 0,0);
	Invalidate();
	//UpdateWindow();
	//ValidateRgn( CRgn
}

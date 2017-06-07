// Ssc2048.cpp : implementation file
//

#include "stdafx.h"
#include "qrs.h"
#include "Ssc2048.h"
#include "conio.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Ssc2048 dialog


int ins[4][4];
int change=0;
int unzero = 0;

	CBrush cbbg;
	CBrush cb0;
	CBrush cb2;
	CBrush cb4;
	CBrush cb8;
	CBrush cb16;
	CBrush cb32;
	CBrush cb64;
	CBrush cb128;
	CBrush cb256;
	CBrush cb512;
	CBrush cb1024;
	CBrush cb2048;
	CBrush cb4096;
	CBrush *cb;

	CFont fontGrade;
	CString cs;


Ssc2048::Ssc2048(CWnd* pParent /*=NULL*/)
	: CDialog(Ssc2048::IDD, pParent)
{
	//{{AFX_DATA_INIT(Ssc2048)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	for( int i=0; i<4; i++){
		for( int j=0; j<4; j++){
			ins[i][j]= 1<<(4*i+j);
		}
	}
/*	ins[0][0]=2;
	ins[0][1]=4;
	ins[0][2]=8;
	ins[0][3]=0;
	ins[0][0]=2;
	ins[1][1]=2;
	ins[2][2]=2;
	ins[3][3]=2;
*/	AllocConsole();
	Restart2048();

	cbbg.CreateSolidBrush( RGB(187,173,160));
	cb0.CreateSolidBrush( RGB(204,192,178));
	cb2.CreateSolidBrush( RGB(238,228,218));
	cb4.CreateSolidBrush( RGB(236,224,200));
	cb8.CreateSolidBrush( RGB(242,177,121));
	cb16.CreateSolidBrush( RGB(245,149,101));
	cb32.CreateSolidBrush( RGB(245,124,95));
	cb64.CreateSolidBrush( RGB(245,95,58));
	cb128.CreateSolidBrush( RGB(238,207,114));
	cb256.CreateSolidBrush( RGB(236,204,95));
	cb512.CreateSolidBrush( RGB(226,193,40));
	cb1024.CreateSolidBrush( RGB(237,204,97));
	cb2048.CreateSolidBrush( RGB(237,194,46));
	cb4096.CreateSolidBrush( RGB(37,187,98));

	fontGrade.CreatePointFont(250, _T("GungsuhChe"));

}


void Ssc2048::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Ssc2048)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Ssc2048, CDialog)
	//{{AFX_MSG_MAP(Ssc2048)
	ON_WM_PAINT()
	ON_BN_CLICKED(ID_2048_RESTART, On2048Restart)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Ssc2048 message handlers

void Ssc2048::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	POINT p;
	p.x = 5;
	p.y = 5;
	
	CRect c(7, 7, 407, 407);
	CRgn cr;
	int i, j;


	dc.FillRect( c, &cbbg);
/*
	for( i=0; i< 6; i++){
		dc.MoveTo( 7, 7+100*i);
		dc.LineTo( 407, 7+100*i);
	}
	for( j=0; j<6; j++){
		dc.MoveTo( 100*j+7, 7);
		dc.LineTo( 100*j+7, 407);
	}
*/
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(0,0,0));
	dc.SelectObject(&fontGrade);

	
	for( i=0; i<4; i++){
		for( j=0; j<4; j++){
				cr.CreateRoundRectRgn( 
					8+100*j+5,
					8+100*i+5,
					8+100*j+5+100-1-10,
					8+100*i+5+100-1-10,
					5, 5);
			c.left = 8+100*j+5;
			c.right = c.left+100-1-10;
			c.top = 8+100*i+5;
			c.bottom = c.top+100-1-10;

			switch( ins[i][j]){
			case 0:	cb = &cb0;	break;
			case 2:	cb = &cb2;	break;
			case 4:	cb = &cb4;	break;
			case 8:	cb = &cb8;	break;
			case 16:	cb = &cb16;	break;
			case 32:	cb = &cb32;	break;
			case 64:	cb = &cb64;	break;
			case 128:	cb = &cb128;	break;
			case 256:	cb = &cb256;	break;
			case 512:	cb = &cb512;	break;
			case 1024:	cb = &cb1024;	break;
			case 2048:	cb = &cb2048;	break;
			case 4096:	cb = &cb4096;	break;
			}
//			dc.FillRect( c, cb);
			dc.FillRgn( &cr, cb);
			cr.DeleteObject();

			if( ins[i][j] == 0) continue;
			dc.SetTextColor( RGB(255,255,255));
			if( ins[i][j] < 10){
				dc.SetTextColor(RGB(119,110,93));
				c.left +=15;
			}else if(ins[i][j] < 128){
				c.left += 25;
			}else if( ins[i][j] < 1024){
				c.left += 15;
			}else if( ins[i][j] < 16384){
				c.left += 10;
			}
			cs.Format("%2d", ins[i][j]);
			c.top +=25;
			dc.DrawText(_T(cs),  &c, DT_EDITCONTROL|DT_WORDBREAK|DT_LEFT|DT_NOPREFIX);

		}
	}
}

BOOL Ssc2048::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN && (pMsg->wParam > 36 && pMsg->wParam < 41))  
    {  
        switch(pMsg->wParam)  
        {  
            case VK_ESCAPE: //Esc按键事件  
				CDialog::OnCancel();
                return true;  
            case VK_RETURN: //Enter按键事件  
                return true; 

			case 37:// left
				doLeft();
				break;;
				 
			case 38:// up
				doUp();
				break;;
				 
			case 39:// rigth
				doRight();
				break;;
				 
			case 40:// down
				doDown();
				break;;
        }
		make2();
    } 
	return CDialog::PreTranslateMessage(pMsg);
}

void Ssc2048::doLeft()
{
	cprintf("left\n");
	int i, j, k;
	change = 0; unzero = 0;
	for( i=0; i<4; i++){
		for( j=0; j<3; j++){
			if( ins[i][j] != 0){
				for( k=j+1; k<4; k++){
					if( ins[i][k] != 0){
						if( ins[i][j] == ins[i][k]){
							change++;
							ins[i][j] += ins[i][k];
							ins[i][k] = 0;
							j = k;
						}else{
							j = k-1;
						}
						break;
					}
				}
			}
		}
		for( k = 0; k<4; k++){
			if( ins[i][k] != 0){
				unzero ++;
				for( j=0; j<k; j++){
					if( ins[i][j] == 0){
						change++;
						ins[i][j] = ins[i][k];
						ins[i][k]=0;
						break;
					}
				}
			}
		}
	}
	showArr();
}

void Ssc2048::doUp()
{
	cprintf("up");
	int i, j, k;
	change = 0; unzero = 0;
	showArr();
	for( j=0; j<4; j++){
		for( i=0; i<3; i++){
			if( ins[i][j] !=0){
				for( k=i+1; k<4; k++){
					if( ins[k][j] != 0){
						if( ins[k][j] == ins[i][j]){
							change++;
							ins[i][j] += ins[k][j];
							ins[k][j] = 0;
							i = k;
						}else{
							i=k-1;
						}
						break;
					}
				}
			}
		}
		for( k=0; k<4; k++){
			if( ins[k][j] !=0){
				unzero ++;
				for( i =0; i<k; i++){
					if( ins[i][j] == 0){
						change ++; 
						ins[i][j] = ins[k][j];
						ins[k][j]=0;
						break;
					}
				}
			}
		}
	}
	showArr();
}

void Ssc2048::doRight()
{
	int i, j, k;
	change = 0; unzero = 0;
	for( i=0; i<4; i++){
		for( j=3; j>0; j--){
			if( ins[i][j] !=0){
				for( k=j-1; k>=0; k--){
					if( ins[i][k] !=0){
						if( ins[i][k] == ins[i][j]){
							change++;
							ins[i][j] += ins[i][k];
							ins[i][k] = 0;
							j = k;
						}else{
							j = k+1;
						}
						break;
					}
				}
			}
			if( ins[i][j] == ins[i][j-1]){
				ins[i][j] += ins[i][j-1];
				ins[i][j-1] = 0;
			}
		}
		for( j=3; j>=0; j--){
			if( ins[i][j] !=0){
				unzero++;
				for( k=3; k>j; k--){
					if( ins[i][k] == 0){
						change ++; 
						ins[i][k] = ins[i][j];
						ins[i][j] = 0;
						break;
					}
				}
			}
		}
	}
	showArr();
}

void Ssc2048::doDown()
{
	int i, j, k;
	change = 0; unzero = 0;
	for( j=0; j<4; j++){
		for( i=3; i>0; i--){
			if( ins[i][j] !=0){
				for( k=i-1; k>=0; k--){
					if( ins[k][j] !=0){
						if( ins[k][j] == ins[i][j]){
							change++;
							ins[i][j] +=ins[k][j];
							ins[k][j] = 0;
							i = k;
						}else{
							i = k+1;
						}
						break;
					}
				}
			}
		}
		for( i=3; i>=0; i--){ // move
			if( ins[i][j] !=0){
				unzero ++;
				for( k=3; k>i; k--){
					if( ins[k][j] == 0){
						change++;
						ins[k][j] = ins[i][j];
						ins[i][j] = 0;
					}
				}
			}
		}
	}
}

void Ssc2048::showArr()
{
	return;
	for( int i=0; i<4; i++){
		for( int j=0; j<4; j++){
			cprintf("%3d", ins[i][j]);
		}
		cprintf("\n");
	}

}

void Ssc2048::make2()
{
	int p=0;


	if( change == 0){
		cprintf("unchange.\n");
		return;
	}
	while(1){
		p = rand()%16;
		cprintf("p--%d,%d,%d\n", p, p/4, p%4);
		if( ins[p/4][p%4] !=0) continue;
		ins[p/4][p%4] = 2;
		break;
	}

	Invalidate();

	if( !isAlive()){
		AfxMessageBox("Game Over!");
		return;
	}

	change = 0; unzero = 0;
}


int Ssc2048::isAlive()
{
	int i, j;
	for( i =0; i<3; i++){
		for( j=0; j<3; j++){
			if( ins[i][j] ==0){
				return 1;
			}
			if( ins[i][j] == ins[i][j+1] ||ins[i][j] == ins[i+1][j]){
				return 1;
			}
		}
	}
	for( i=0; i<3; i++){
		if( ins[i][3] == 0){
			return 1;
		}
		if( ins[i][3] == ins[i+1][3]){
			return 1;
		}
	}
	for( j=0; j<3; j++){
		if( ins[3][j] == 0){
			return 1;
		}
		if( ins[3][j] == ins[3][j+1]){
			return 1;
		}
	}
	if( ins[3][3] == 0) return 1;
	return 0;
}

void Ssc2048::On2048Restart() 
{
	Restart2048();
 	Invalidate();
}

void Ssc2048::Restart2048()
{
	int i, j;
	for( i=0; i<4; i++){
		for( j=0; j<4; j++){
			ins[i][j] = 0;
		}
	}
	i = 2;
	j=0;
	while( i!=0){
		j = rand()%16;
		if( ins[j/4][j%4] != 0) continue;
		ins[j/4][j%4] = 2;
		i--;
	}
}

void Ssc2048::OnClose() 
{

	cbbg.DeleteObject();
	cb0.DeleteObject();
	cb2.DeleteObject();
	cb4.DeleteObject();
	cb8.DeleteObject();
	cb16.DeleteObject();
	cb32.DeleteObject();
	cb64.DeleteObject();
	cb128.DeleteObject();
	cb256.DeleteObject();
	cb512.DeleteObject();
	cb1024.DeleteObject();
	cb2048.DeleteObject();
	cb4096.DeleteObject();
	cb = 0;
	fontGrade.DeleteObject();

	CDialog::OnClose();
}

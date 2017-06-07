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

Ssc2048::Ssc2048(CWnd* pParent /*=NULL*/)
	: CDialog(Ssc2048::IDD, pParent)
{
	//{{AFX_DATA_INIT(Ssc2048)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	for( int i=0; i<4; i++){
		for( int j=0; j<4; j++){
			ins[i][j]=0;
		}
	}
	ins[0][0]=2;
	ins[1][1]=2;
	ins[2][2]=2;
	ins[3][3]=2;
	AllocConsole();
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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Ssc2048 message handlers

void Ssc2048::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	
	CBrush cbbg;
	CBrush cb2;
	CBrush cb4;
	CBrush cb8;
	CBrush *cb;
	CRect c(7, 7, 407, 407);
	int i, j;


	cbbg.CreateSolidBrush( RGB(255,255,255));
	dc.FillRect( c, &cbbg);

	for( i=0; i< 6; i++){
		dc.MoveTo( 7, 7+100*i);
		dc.LineTo( 407, 7+100*i);
	}
	for( j=0; j<6; j++){
		dc.MoveTo( 100*j+7, 7);
		dc.LineTo( 100*j+7, 407);
	}

	dc.SetBkMode(TRANSPARENT);
	CFont fontGrade;
	dc.SetTextColor(RGB(0,0,0));
	fontGrade.CreatePointFont(500, _T("宋体"));
	dc.SelectObject(&fontGrade);
	CString cs;

	
	cb2.CreateSolidBrush( RGB(255,0,0));
	cb4.CreateSolidBrush( RGB(0,255,0));
	cb8.CreateSolidBrush( RGB(0,0,255));
	for( i=0; i<4; i++){
		for( j=0; j<4; j++){
			c.left = 8+100*j;
			c.right = c.left+100-1;
			c.top = 8+100*i;
			c.bottom = c.top+100-1;

			if( ins[i][j] ==0) continue;

			switch( ins[i][j]){
			case 2:
				cb = &cb2;
					break;
			case 4:
				cb = &cb4;
					break;
			case 8:
				cb = &cb8;
				break;
			default:
				cb = &cb8;
			}
			dc.FillRect( c, cb);


			cs.Format("%2d", ins[i][j]);
			dc.DrawText(_T(cs),  &c, DT_EDITCONTROL|DT_WORDBREAK|DT_LEFT|DT_NOPREFIX);

		}
	}

	cbbg.DeleteObject();
	cb2.DeleteObject();
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
	 	Invalidate();
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
 	Invalidate();
}

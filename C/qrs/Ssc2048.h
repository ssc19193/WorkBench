#if !defined(AFX_SSC2048_H__31DF9C09_90C2_4D99_8896_9BCF0B3BE5CB__INCLUDED_)
#define AFX_SSC2048_H__31DF9C09_90C2_4D99_8896_9BCF0B3BE5CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Ssc2048.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Ssc2048 dialog

class Ssc2048 : public CDialog
{
// Construction
public:
	void showArr();
	void doDown();
	void doRight();
	void doUp();
	Ssc2048(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Ssc2048)
	enum { IDD = IDD_DIALOG_2048 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Ssc2048)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Ssc2048)
	afx_msg void OnPaint();
	afx_msg void On2048Restart();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void Restart2048();
	int isAlive();
	void make2();
	void doLeft();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSC2048_H__31DF9C09_90C2_4D99_8896_9BCF0B3BE5CB__INCLUDED_)

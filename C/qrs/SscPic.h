#if !defined(AFX_SSCPIC_H__5DE527D2_3501_453E_99A3_9C1176B73087__INCLUDED_)
#define AFX_SSCPIC_H__5DE527D2_3501_453E_99A3_9C1176B73087__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SscPic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SscPic dialog

class SscPic : public CDialog
{
// Construction
public:
	void nextPic();
	SscPic(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SscPic)
	enum { IDD = IDD_DIALOG_SHOWPIC };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SscPic)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SscPic)
	afx_msg void OnButtonPicNext();
	afx_msg void OnButtonPicClose();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int picArr[3];
	int cPic;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSCPIC_H__5DE527D2_3501_453E_99A3_9C1176B73087__INCLUDED_)

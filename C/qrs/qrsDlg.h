// qrsDlg.h : header file
//

#if !defined(AFX_QRSDLG_H__A25AEA22_E283_41D3_812B_932D756F5627__INCLUDED_)
#define AFX_QRSDLG_H__A25AEA22_E283_41D3_812B_932D756F5627__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CQrsDlg dialog

class CQrsDlg : public CDialog
{
// Construction
public:
	void showPic();
	CQrsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CQrsDlg)
	enum { IDD = IDD_QRS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQrsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CQrsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButtonPicdialog();
	afx_msg void OnButtonPinao();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QRSDLG_H__A25AEA22_E283_41D3_812B_932D756F5627__INCLUDED_)

#if !defined(AFX_SSCPINAO_H__93A816A1_6EC8_4C81_B4BA_E5F2E93E6B0F__INCLUDED_)
#define AFX_SSCPINAO_H__93A816A1_6EC8_4C81_B4BA_E5F2E93E6B0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SscPinao.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SscPinao dialog

class SscPinao : public CDialog
{
// Construction
public:
	void flush();
	int threadStatue;
	SscPinao(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SscPinao)
	enum { IDD = IDD_DIALOG_PINAO };
	//}}AFX_DATA

	struct ThreadInfo{
		long nMSec;
		SscPinao *sp;
	}info;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SscPinao)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CWinThread* pThead;

	// Generated message map functions
	//{{AFX_MSG(SscPinao)
	afx_msg void OnClose();
	afx_msg void OnStart();
	virtual BOOL OnInitDialog();
	afx_msg void OnPause();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void drawBlock(CDC* memDc, int x, int y);
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSCPINAO_H__93A816A1_6EC8_4C81_B4BA_E5F2E93E6B0F__INCLUDED_)

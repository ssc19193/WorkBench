// qrs.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "qrs.h"
#include "qrsDlg.h"
#include "SscPinao.h"
#include "Ssc2048.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQrsApp

BEGIN_MESSAGE_MAP(CQrsApp, CWinApp)
	//{{AFX_MSG_MAP(CQrsApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQrsApp construction

CQrsApp::CQrsApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CQrsApp object

CQrsApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CQrsApp initialization

BOOL CQrsApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// 只能选择其中一项

	CQrsDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();

//	SscPinao s;
//	int nResponse = s.DoModal();

//	Ssc2048 s;
//	int nResponse = s.DoModal();

	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

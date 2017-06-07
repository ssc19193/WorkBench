; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CQrsDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "qrs.h"
LastPage=0

ClassCount=5
Class1=CQrsApp
Class2=CQrsDlg
Class3=SscPic
Class4=SscPinao

ResourceCount=4
Resource1=IDD_DIALOG_PINAO
Resource2=IDD_QRS_MAIN
Resource3=IDD_DIALOG_SHOWPIC
Class5=Ssc2048
Resource4=IDD_DIALOG_2048

[CLS:CQrsApp]
Type=0
BaseClass=CWinApp
HeaderFile=qrs.h
ImplementationFile=qrs.cpp
LastObject=CQrsApp

[CLS:CQrsDlg]
Type=0
BaseClass=CDialog
HeaderFile=qrsDlg.h
ImplementationFile=qrsDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CQrsDlg

[CLS:SscPic]
Type=0
BaseClass=CDialog
HeaderFile=SscPic.h
ImplementationFile=SscPic.cpp

[CLS:SscPinao]
Type=0
BaseClass=CDialog
HeaderFile=SscPinao.h
ImplementationFile=SscPinao.cpp
LastObject=SscPinao

[DLG:IDD_QRS_DIALOG]
Type=1
Class=CQrsDlg

[DLG:IDD_DIALOG_SHOWPIC]
Type=1
Class=SscPic
ControlCount=3
Control1=IDC_STATIC_pic,static,1342177287
Control2=IDC_BUTTON_PIC_NEXT,button,1342242816
Control3=IDC_BUTTON_PIC_CLOSE,button,1342242816

[DLG:IDD_DIALOG_PINAO]
Type=1
Class=SscPinao
ControlCount=8
Control1=ID_PINAO_START,button,1342242817
Control2=ID_PINAO_CLOSE,button,1342242816
Control3=ID_PINAO_PAUSE,button,1342242816
Control4=IDC_STATIC,static,1342308865
Control5=IDC_STATIC,static,1342308865
Control6=IDC_STATIC,static,1342308865
Control7=IDC_STATIC,static,1342308865
Control8=ID_PINAO_HELP,button,1342242816

[DLG:IDD_DIALOG_2048]
Type=1
Class=Ssc2048
ControlCount=2
Control1=ID_2048_RESTART,button,1342242817
Control2=IDCANCEL,button,1342242816

[DLG:IDD_QRS_MAIN]
Type=1
Class=CQrsDlg
ControlCount=5
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC_pic,static,1342177287
Control3=IDC_BUTTON_PICDIALOG,button,1342242816
Control4=IDC_PINAO,button,1342242816
Control5=IDC_2048,button,1342242816

[CLS:Ssc2048]
Type=0
HeaderFile=Ssc2048.h
ImplementationFile=Ssc2048.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_2048_RESTART
VirtualFilter=dWC


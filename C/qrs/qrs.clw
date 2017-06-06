; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=SscPinao
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "qrs.h"

ClassCount=4
Class1=CQrsApp
Class2=CQrsDlg

ResourceCount=4
Resource2=IDD_QRS_MAIN
Resource1=IDR_MAINFRAME
Class3=SscPic
Resource3=IDD_DIALOG_SHOWPIC
Class4=SscPinao
Resource4=IDD_DIALOG_PINAO

[CLS:CQrsApp]
Type=0
HeaderFile=qrs.h
ImplementationFile=qrs.cpp
Filter=N

[CLS:CQrsDlg]
Type=0
HeaderFile=qrsDlg.h
ImplementationFile=qrsDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CQrsDlg



[CLS:SscPic]
Type=0
HeaderFile=SscPic.h
ImplementationFile=SscPic.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON_PIC_CLOSE
VirtualFilter=dWC

[DLG:IDD_DIALOG_SHOWPIC]
Type=1
Class=SscPic
ControlCount=3
Control1=IDC_STATIC_pic,static,1342177287
Control2=IDC_BUTTON_PIC_NEXT,button,1342242816
Control3=IDC_BUTTON_PIC_CLOSE,button,1342242816

[DLG:IDD_QRS_MAIN]
Type=1
Class=CQrsDlg
ControlCount=4
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC_pic,static,1342177287
Control3=IDC_BUTTON_PICDIALOG,button,1342242816
Control4=IDC_BUTTON_PINAO,button,1342242816

[DLG:IDD_DIALOG_PINAO]
Type=1
Class=SscPinao
ControlCount=7
Control1=ID_START,button,1342242817
Control2=ID_CLOSE,button,1342242816
Control3=ID_PAUSE,button,1342242816
Control4=IDC_STATIC,static,1342308865
Control5=IDC_STATIC,static,1342308865
Control6=IDC_STATIC,static,1342308865
Control7=IDC_STATIC,static,1342308865

[CLS:SscPinao]
Type=0
HeaderFile=SscPinao.h
ImplementationFile=SscPinao.cpp
BaseClass=CDialog
Filter=D
LastObject=SscPinao
VirtualFilter=dWC


:: ����Ϊ�����������Ĭ�ϡ�������ӡ������û���������
@set "connectName=ouc"
@set "userId=14020023034"
@set "password=14020023034"

@echo off
Setlocal enabledelayedexpansion
::CODER BY Administrator POWERD BY iBAT
ipconfig /flushdns
rasdial %connectName% /disconnect 
set /a t=10
echo ÿ�γ���10������
:cir
echo ���ڳ��Ե�%t%��
rasdial %connectName% %userId% %password%
::0 ��ʾ���ӳɹ���������, �����ʾ����ʧ��
IF /I "%errorlevel%" EQU "0" ( goto end)
set /a t=t-1
if "%t%" neq "0" goto cir
CHOICE /C yn /T 10 /D n /M "(10sѡ��ʱ��)�Ƿ��ٴε���?"
if /i "%errorlevel%" equ "1" (  call ouc.bat)
CHOICE /T 2 /D n /M "---------����ʧ��--------2s���˳�"
::pause
exit
:end
start "" "C:\Program Files (x86)\Google\Chrome\Application\chrome.exe"
CHOICE /T 3 /D n /M "---------����--�ɹ�--------3s���˳�"
::pause
exit
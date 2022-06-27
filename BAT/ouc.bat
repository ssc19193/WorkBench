:: 依次为宽带连接名（默认“宽带连接”），用户名，密码
@set "connectName=ouc"
@set "userId="
@set "password="

@echo off
Setlocal enabledelayedexpansion
::CODER BY Administrator POWERD BY iBAT
ipconfig /flushdns
rasdial %connectName% /disconnect 
set /a t=10
echo 每次尝试10次连接
:cir
echo 正在尝试第%t%次
rasdial %connectName% %userId% %password%
::0 表示连接成功或已连接, 否则表示连接失败
IF /I "%errorlevel%" EQU "0" ( goto end)
set /a t=t-1
if "%t%" neq "0" goto cir
CHOICE /C yn /T 10 /D n /M "(10s选择时间)是否再次调用?"
if /i "%errorlevel%" equ "1" (  call ouc.bat)
CHOICE /T 2 /D n /M "---------连接失败--------2s后退出"
::pause
exit
:end
start "" "C:\Program Files (x86)\Google\Chrome\Application\chrome.exe"
CHOICE /T 3 /D n /M "---------连接--成功--------3s后退出"
::pause
exit

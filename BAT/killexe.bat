@echo off
Setlocal enabledelayedexpansion
::CODER BY Administrator POWERD BY iBAT

ECHO.
tasklist|findstr "360WangPan.exe"

if %errorlevel%==0 (taskkill /F /IM 360WangPan.exe) else (ECHO 该进程不存在或当前不在运行状态)

pause
@echo off & setlocal enabledelayedexpansion
set a=0
for /r c:\ %%i in (*.exe) do (echo %%i >> c.txt & set /a a+=1)
echo %a% >> c.txt
pause
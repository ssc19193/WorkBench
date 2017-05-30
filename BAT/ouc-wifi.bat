@echo off
Setlocal enabledelayedexpansion
::CODER BY Administrator POWERD BY iBAT
c:
netsh wlan add profile filename="D:\Program Files\Batch\无线网络连接.xml" interface="无线网络连接" user=current
netsh wlan connect name=OUC-WIFI ssid=OUC-WIFI
echo %errorlevel%
pause&exit
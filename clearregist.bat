@echo off
REG DELETE HKEY_CURRENT_USER\Software\Lenovo\App /f
cd /d c:
cd C:/ProgramData/Lenovo/
del app.dat

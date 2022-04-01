@echo off
REG DELETE HKEY_CURRENT_USER\Software\Lenovo\Sirius_Mult_ss /f
cd /d c:
cd C:/ProgramData/Lenovo/
del app.dat

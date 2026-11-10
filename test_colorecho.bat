@echo off

title test_colorecho.bat

for /L %%G IN (0,1,15) DO (
REM         od,step,do
colorecho %%G "toto je barva cislo %%G"
)

pause


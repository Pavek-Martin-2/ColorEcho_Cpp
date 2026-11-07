@echo off
title attrib_2.bat

REM uzivatelsky jmeno vlozi do promenne "u"
REM USERNAME je dynamicka systemova promenna ja mam hodnotu napr. "DELL" 
set u=%USERNAME%

echo tvoje uzivatelske jmeno je : %u%

REM colorecho 11 "attrib /S -r C:\tools\*.*"
REM attrib /S -r C:\tools\*.*

colorecho 11 "attrib /S -r C:\Users\DELL\Documents\*.*"
attrib /S -r C:\Users\%u%\Documents\*.*

colorecho 11 "attrib /S -r C:\Users\DELL\Pictures\*.*"
attrib /S -r C:\Users\%u%\Pictures\*.*

colorecho 11 "attrib /S -r C:\Users\DELL\Videos\*.*"
attrib /S -r C:\Users\%u%\Videos\*.*

colorecho 11 "attrib /S -r C:\Users\DELL\Music\*.*"
attrib /S -r C:\Users\%u%\Music\*.*

pause

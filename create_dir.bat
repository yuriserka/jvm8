@echo off
Setlocal EnableDelayedExpansion

set _dir=%1
set _dir=!_dir:/=\!

if not exist %_dir% md %_dir% 

endlocal
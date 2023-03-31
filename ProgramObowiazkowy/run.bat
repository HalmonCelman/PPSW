@echo off
cmake --build build
cd build/
cls
PPSW.exe
cd ../
pause
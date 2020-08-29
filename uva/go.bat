@echo off
@echo off
g++ %1 -g -o %1.exe -Wall -std=c++11
:echo %errorlevel%
if not errorlevel 1  %1.exe<in

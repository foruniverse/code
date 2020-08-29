@echo off

:back
a<in>o1.txt
b<in>o2.txt
fc o1.txt o2.txt
if not errorlevel 1 goto back


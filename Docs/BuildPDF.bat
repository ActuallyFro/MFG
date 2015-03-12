@echo off
doxygen Docs\Doxygen.cfg 
Docs\latex\make.bat 
start Docs\latex\refman.pdf 

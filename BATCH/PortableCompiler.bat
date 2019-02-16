@echo off
SETLOCAL EnableDelayedExpansion

COLOR 1
ECHO Bienvenido al compilador portable GACRUCIS
COLOR F
ECHO.

REM Parametros del programa, modificar a gusto
SET ExecuteAfterCompile=1
SET EnableDebug=1
SET AskDisk=1
SET SourceFolder=1

IF %AskDisk% == 1 (
    SET /p DiskName="Inserte la letra del disco removible(suele ser F o G): "
    SET DiskName=!DiskName!:
) else ( SET DiskName=%AskDisk%
ECHO Usando carpeta personalizada, detectando . . .
ECHO Trabajando en !DiskName! !
ECHO.
pause )

ECHO.

SET g++Path=%DiskName%\MinGW\bin

IF %SourceFolder% == 1 (
    SET SourcePath=%DiskName%\Programs
) else ( SET SourcePath=%SourceFolder%)

SET path=%path%%g++Path%

cls

:compilar

SET /p ProgramName="Inserte el codigo fuente a compilar(Debe estar en la carpeta programs): "
ECHO Compilando %ProgramName%.cpp en [%SourcePath%] . . .



IF %EnableDebug% == 1 (
    g++ -g -o "%SourcePath%\%ProgramName%.exe" "%SourcePath%\%ProgramName%.cpp"
) else ( g++ -o "%SourcePath%\%ProgramName%.exe" "%SourcePath%\%ProgramName%.cpp" )

IF %ExecuteAfterCompile% == 1 (
    start %SourcePath%\%ProgramName%.exe
)

cls
goto :compilar




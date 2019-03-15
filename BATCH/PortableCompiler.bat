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
SET SourceFile=1

IF "%~1"== not "" (

    SET /a pindex=1
    :parameterloop
    
    IF "%~1"=="-e" (
        SET ExecuteAfterCompile=0
    )

    IF "%~1"=="-d" (
        SET EnableDebug=0
    )

    IF "%~1"=="-r" (
        SET AskDisk="%~2"
        SHIFT
    )

    IF "%~1"=="-sf" (
        SET SourceFolder="%~2"
        SHIFT
    )

    IF "%~1"=="-file" (
        SET SourceFile="%~2"
        SHIFT
    )

    IF !pindex! LSS 5 (
        SET /a pindex=!pindex! + 1
        SHIFT
        goto :parameterloop
    )

) 

ECHO PARAMETROS ACTUALES:
ECHO.
ECHO Ejecutar tras compilar: %ExecuteAfterCompile%
ECHO Activar modo de debug: %EnableDebug%
ECHO Usar carpeta base Predeterminada: %AskDisk%
ECHO Usar carpeta de codigo Predeterminada: %SourceFolder%
ECHO.

SET AskDisk=%AskDisk:"=%
SET SourceFolder=%SourceFolder:"=%

IF !AskDisk! == 1 (
    SET /p DiskName="Inserte la letra del disco removible(suele ser F o G): "
    SET DiskName=!DiskName!:
) else ( SET DiskName=%AskDisk%
    ECHO Usando carpeta personalizada, detectando . . .
    ECHO Trabajando en !DiskName! !
    ECHO.
)

ECHO.

SET g++Path=%DiskName%\MinGW\bin

IF %SourceFolder% == 1 (
    SET SourcePath=%DiskName%\Programs
) else ( SET SourcePath=%SourceFolder%)

SET path=%path%%g++Path%

cls

:compilar

IF %SourceFile% == 1 (
    SET /p ProgramName="Inserte el codigo fuente a compilar(Debe estar en la carpeta programs): "
    ECHO Compilando %ProgramName%.cpp en [%SourcePath%] . . .
) else ( SET ProgramName=%SourceFile:"=% )

SET exepath="%SourcePath%\%ProgramName%.exe"
SET cpppath="%SourcePath%\%ProgramName%.cpp"

SET "cpppath=%cpppath: =%"
SET "exepath=%exepath: =%"

ECHO Compilando %cpppath% . . .

IF %EnableDebug% == 1 (
    g++ -g -o %exepath% %cpppath%
) else ( g++ -o %exepath% %cpppath% )

IF %ExecuteAfterCompile% == 1 (
    %exepath%
)

cls

IF %SourceFile% == not 1 (
    exit
)

goto :compilar




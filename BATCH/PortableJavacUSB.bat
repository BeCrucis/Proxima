@echo off
SETLOCAL EnableDelayedExpansion

COLOR 1
ECHO Bienvenido al compilador JAVA portable GACRUCIS

REM Parametros del programa, modificar a gusto

SET ExecuteAfterCompile=1
SET EnableDebug=1
REM SET NotPackaged=1
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

    REM IF "%~1"=="-p" (
    REM    SET NotPackaged=0
    REM    SET RootFolder=%cd%
    REM    ECHO !RootFolder!
    REM )

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

ECHO ECO
    IF !pindex! LSS 5 (
        SET /a pindex=!pindex! + 1
        SHIFT
        goto :parameterloop
    )
ECHO.
) 

ECHO PARAMETROS ACTUALES:
ECHO.
ECHO Ejecutar tras compilar: %ExecuteAfterCompile%
ECHO Activar modo de debug: %EnableDebug%
ECHO Usar carpeta base Predeterminada: %AskDisk%
ECHO Usar carpeta de codigo Predeterminada: %SourceFolder%
ECHO Usar carpeta fuente unica: %NotPackaged%
ECHO.

SET AskDisk=%AskDisk:"=%
SET AskDisk=%AskDisk:'=%

SET SourceFolder=%SourceFolder:"=%
SET SourceFolder=%SourceFolder:'=%

SET SourceFile=%SourceFile:"=%
SET SourceFile=%SourceFile:'=%

REM IF %NotPackaged% == 1 (
REM         CD %SourceFolder%
REM         CALL :NORMALIZEPATH ".."
REM         SET packageFolder=!NPATH!
REM     )

IF !AskDisk! == 1 (
    CALL :NORMALIZEPATH "..\..\Compilers\JavaDK\bin"
    SET DiskName=!NPATH!
    SET javacPath=!DiskName!
) ELSE ( SET DiskName=%AskDisk%
    ECHO Usando carpeta personalizada, detectando . . .
    ECHO Trabajando en !DiskName! !
    SET javacPath=!DiskName!/bin
    ECHO.
)

CD %javacPath%

ECHO.

IF %SourceFolder% == 1 (
    CALL :NORMALIZEPATH "../.."
    SET SourcePath=!NPATH!/Programs/JAVA
) ELSE ( SET SourcePath=%SourceFolder%)

:compilar

IF %SourceFile% == 1 (
    SET /p ProgramName="Inserte el archivo .java a compilar(Carpeta actual: [%SourcePath%]): "
    ECHO Compilando %ProgramName%.java en [%SourcePath%] . . .
) ELSE ( SET ProgramName=%SourceFile:"=% )

SET classpath="%SourcePath%\%ProgramName%.class"
SET javapath="%SourcePath%\%ProgramName%.java"

SET "javapath=%javapath: =%"
SET "classpath=%classpath: =%"

ECHO Compilando %javapath% . . .

IF %EnableDebug% == 1 (
   ECHO javac -g %javapath%
   javac -g -cp %SourcePath% %javapath%

) ELSE ( javac %javapath% )

IF %ExecuteAfterCompile% == 1 (
    CLS
    java -cp %SourcePath% %ProgramName%

    DEL %classpath% /q REM Borra el .class creado
)


IF %SourceFile% == not 1 (
    EXIT
)

GOTO :compilar



:NORMALIZEPATH
SET NPATH=%~dpfn1
EXIT /B
@echo off
setlocal EnableDelayedExpansion

:INTRO
    echo ***************************************************************
    echo       _______   ______    __    __    ______ 
    echo      /  _____^| ^|   _  \  ^|  ^|  ^|  ^|  /      ^|
    echo     ^|  ^|  __   ^|  ^|_^)  ^| ^|  ^|  ^|  ^| ^|   ----'
    echo     ^|  ^| ^|_ ^|  ^|      /  ^|  ^|  ^|  ^| ^|  ^|     
    echo     ^|  ^|__^| ^|  ^|  ^|\  \  ^|  `--'  ^| ^|  `----.
    echo      \______^|  ^| _^| \__^|  \______/   \______^| By: Gacrucis
    echo.
    echo ***************************************************************
    echo.

    goto :SETBASECONFIG

:HELPMESSAGE
    echo      This batch script gets as input the location of a folder
    echo      with:
    echo          * A "Compilers" folder with JDK, MinGW, and Python
    echo          * A file to compile
    echo          * Optionally the output file name
    echo.     and outputs a compiled file (.exe for c++, .class for java^)
    echo.     or interprets it (for python^)
    echo.
    echo usage: gruc [base folder] [source file] [-o ^<output^>] [--e] [--e*]
    echo.
    echo        if a file is in the [base folder], the script will extract
    echo        the folder the file is in
    echo.
    echo        the --e flag executes the program after compilation
    echo        the --e* flag executes the program after compilation and cleans the folder
    echo.
    pause
    exit

:SETBASECONFIG
    set "cppDefaultCompilerPath=Compilers/MinGW/bin"
    set "cppCompilerFlags=-g3" 
    set "cppLinkerFlags="

    set "javaDefaultCompilerPath=Compilers/JDK13/bin"
    set "javaCompilerFlags=-g"
    set "javaLinkerFlags=-cp "%~dp1""

    set "pyDefaultCompilerPath=Compilers/Python"
    set "pyCompilerFlags="
    set "pyLinkerFlags="

:GETARGUMENTCONFIG

    rem print instructions if arguments are invalid

    set "baseFolder=%~1"
    set "inputFilePath=%~dpnx2"
    set "inputFileName=%~n2"
    set "inputFileExtension=%~x2"
    set "inputFileDirectory=%~dp2"
    set "temp=%~dp1"

    if not defined baseFolder echo 1 && call :HELPMESSAGE
    if not defined inputFilePath echo 2 && call :HELPMESSAGE
    if not defined temp echo 3 && call :HELPMESSAGE

    if "%~x1" NEQ "" (
        set "baseFolder=%~dp1"
    )

    if "%~x2" EQU ".cpp" (
        set defaultCompilerPath="%cppDefaultCompilerPath%"
        set compilerFlags=%cppCompilerFlags%
        set linkerFlags="%cppLinkerFlags%"
        set programType=cpp
        shift
        goto :CHECKCOMPILEFLAGS
    )

    if "%~x2" EQU ".java" (
        set defaultCompilerPath="%javaDefaultCompilerPath%"
        set compilerFlags=%javaCompilerFlags%
        set linkerFlags=%javaLinkerFlags%
        set programType=java
        shift
        goto :CHECKCOMPILEFLAGS
    )

    if "%~x2" EQU ".py" (
        set defaultCompilerPath="%pyDefaultCompilerPath%"
        set compilerFlags=%pyCompilerFlags%
        set linkerFlags="%pyLinkerFlags%"
        set programType=python
        shift
        goto :INTERPRETPYTHON
    )

    call :ERRORMESSAGE "couldn't detect file type"

:CHECKCOMPILEFLAGS

    shift
    set "argument=%~1"

    if not defined argument (
        if not defined compiledFilePath (
            set compiledFilePath="!inputFileDirectory!!inputFileName!"
            set compiledFileDirectory=!inputFileDirectory!
            set compiledFileName=!inputFileName!
        )

        echo [INFO] Starting compilation
        echo [INFO] Input File directory: !inputFileDirectory!
        echo [INFO] Input File name: !inputFileName!!inputFileExtension!
        echo [INFO] Output File directory: !compiledFileDirectory! 
        echo [INFO] Output File name: !compiledFileName!
        echo [INFO] File type: !programType!

        if not defined executeAfterCompile (
            set executeAfterCompile="0"
            
        ) else (
            echo [INFO] File will execute after compilation
        )

        if not defined cleanupFiles (
            set cleanupFiles="0"
        ) else (
            echo [INFO] File will be deleted after execution
        )

        goto :COMPILE%programType%
    )

    if "%argument%" EQU "-o" (
        shift

        echo [INFO] Detected "-o" flag

        set "compiledFilePath=%~dpnx1"
        set "compiledFileDirectory=%~dp1"
        set "compiledFileName=%~n1"
        set "compiledFileExtension=%~x1"

        if not defined compiledFileName (
            call :ERRORMESSAGE "Expected output file"
        )

        echo [SUCCESS] Output file path changed!

    )
    
    if "%argument%" EQU "-e" (

        set executeAfterCompile="1"

    )

    if "%argument%" EQU "-e*" (

        set executeAfterCompile="1"
        set cleanupFiles="1"
 
    )

    goto :CHECKCOMPILEFLAGS

:COMPILECPP

    echo [PROCESS] Cleaning previous .exe files
    pushd "%compiledFileDirectory%"
    del %compiledFileName%.exe
    popd

    if %linkerFlags% EQU "" (
        set "linkerFlags="
    )

    pushd %defaultCompilerPath%
    set compilerFlags=%compilerFlags% -o "!compiledFileDirectory!%compiledFileName%.exe"
    echo [INFO] Current g++ version: | set /p temp="[INFO] Current g++ version: "
    call g++ --version
    echo [PROCESS] Issuing command: g++ "%inputFilePath%" %compilerFlags% %LinkerFlags%
    call g++ "%inputFilePath%" %compilerFlags% %LinkerFlags%
    
    if %executeAfterCompile% EQU "1" (

        popd
        pushd !compiledFileDirectory!

        echo [PROCESS] Issuing command: %compiledFileName%.exe
        cls
        call %compiledFileName%.exe || ( pause && exit )
        echo.
        echo.
        echo [SUCCESS] Program execution finished successfuly
    )

    if %cleanupFiles% EQU "1" (
        
        popd
        pushd "%compiledFileDirectory%"
        echo [PROCESS] Cleaning .exe file
        del %compiledFileName%.exe
        echo [SUCCESS] .exe file cleaned, GRUC will now exit
        exit
    )

    echo [INFO] GRUC will now exit
    exit

:COMPILEJAVA

    echo [PROCESS] Cleaning previous .class files
    pushd "%compiledFileDirectory%"
    del %compiledFileName%.class
    popd

    pushd %defaultCompilerPath%
    set compilerFlags=%compilerFlags% -d "!compiledFileDirectory!\"
    for /f "delims=" %%A in ('javac --version') do set "javacVersion=%%A"
    echo [INFO] Current javac version: %javacVersion%
    echo [PROCESS] Issuing command: javac "%inputFilePath%" %compilerFlags% %LinkerFlags%
    call javac "%inputFilePath%" %compilerFlags% %LinkerFlags% || ( pause && exit )

    if %executeAfterCompile% EQU "1" (

        echo [INFO] Current java version: | set /p temp="[INFO] Current java version: "
        call java --version
        echo [PROCESS] Issuing command: java -cp "%compiledFileDirectory%\" %compiledFileName%
        cls
        call java -cp "%compiledFileDirectory%\" %compiledFileName% || ( pause && exit )
        echo.
        echo.
        echo [SUCCESS] Program execution finished successfuly
    )

    if %cleanupFiles% EQU "1" (
        
        popd
        pushd "%compiledFileDirectory%"
        echo [PROCESS] Cleaning .class files
        del *.class
        echo [SUCCESS] .class files cleaned, GRUC will now exit
        exit
    )

    echo [INFO] GRUC will now exit
    exit

:INTERPRETPYTHON

    set compiledFilePath="!inputFileDirectory!!inputFileName!"
    set compiledFileDirectory=!inputFileDirectory!
    set compiledFileName=!inputFileName!

    echo [INFO] Starting interpretation
    echo [INFO] Input File directory: !inputFileDirectory!
    echo [INFO] Input File name: !inputFileName!!inputFileExtension!
    echo [INFO] File type: !programType!

    pushd %defaultCompilerPath%

    echo [INFO] Current python version: | set /p temp="[INFO] Current python version: "
    call python --version
    echo [PROCESS] Issuing command: python !compiledFileDirectory!%compiledFileName%.py %compilerFlags% %LinkerFlags%
    cls
    call python !compiledFileDirectory!%compiledFileName%.py %compilerFlags% %LinkerFlags% && set error="0" || set error="1"
    echo.
    echo.

    if %error% EQU "1" (
        echo [ERROR] Program interpretation failed
    ) else (
        echo [SUCCESS] Program interpretation finished successfuly
    )
    
    echo [INFO] GRUC will now exit
    exit

:NORMALIZEPATH
    set NPATH=%~dpfn1
    exit /B

:ERRORMESSAGE
    set errorMessage=%~1

    if not defined errorMessage (
        echo [ERROR] GRUC Has encountered an unspecified error
    ) else (
        echo [ERROR] GRUC Has encountered an error: %~1
    )

    echo.
    pause
    exit
    
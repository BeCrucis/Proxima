@echo off
setlocal EnableDelayedExpansion

REM GRand Unified Wrapper
REM The purpose of this is just calling the GRand Unified Compiler from anywhere
REM This file gets the same inputs as GRUC would

:SETVARIABLES

    REM Normally GRUC will be in the Scripts folder
    set "relativeGRUCPath=Scripts"
    set "arguments="

    if "%~x1" NEQ "" (
        set "baseFolder=%~dp1"
    ) else (
        set "baseFolder=%~1"
    )

:IMPORTARGUMENTS

    set "argument=%~1"

    if not defined argument (
        goto :CALLGRUC
    )

    set "arguments=!arguments! !argument!"
    shift
    goto :IMPORTARGUMENTS

    

:CALLGRUC

    pushd %baseFolder%%relativeGRUCPath%
    echo [PROCESS] Issuing command: GRUC!arguments!
    call GRUC!arguments! || pause
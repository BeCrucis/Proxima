@echo off

if "%~x1" NEQ "" (
        set "baseFolder=%~dp1"
    ) else (
        set "baseFolder=%~1"
    )

echo %baseFolder%
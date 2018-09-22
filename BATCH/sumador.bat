@echo off
setlocal enabledelayedexpansion

SET /P n="Inserte cuantos numeros va a escribir: "
SET /A n=%n%

:FORLOOP

SET /P x="Inserte su numero: "

SET /A total=0
SET /A di=1
SET /A d=0

:DIGIT
SET /A co=!x!/!di!
IF !co! NEQ 0 (
SET /A di=!di! * 10
SET /A d=!d! + 1
GOTO :DIGIT
)

SET /A dc=!d!-1
SET /A dm=1
FOR /L %%B IN (1,1,!dc!) DO (
SET /A dm*=10
)

FOR /L %%C IN (1,1,!d!) DO (
SET /A dn=!x!/!dm!
ECHO !dn!
SET /A total=!total!+!dn!
SET /A x=!x!-!dn!*!dm!
SET /A dm/=10
)
ECHO La suma de los !d! digitos es igual a !total! !!

SET /A counter+=1
IF !counter! NEQ %n% GOTO :FORLOOP

)
pause

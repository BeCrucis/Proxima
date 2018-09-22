@echo off
setlocal enabledelayedexpansion
REM ignorar lo de arriba

SET /P n="Inserte la cantidad de numeros de 3 digitos: "
SET /A n=%n%
REM esto pide la cantidad n de numeros de 3 digitos

FOR /L %%A IN (1,1,%n%) DO (
:LOOP
REM esto establece el repetidor, ejecutando lo de abajo n veces

SET /P x="Inserte su numero de 3 digitos: "
SET /A x=!x!
REM esto pide el numero de 3 digitos

SET /a exit=0
IF !x! LSS 100 ( 
SET /A exit=1
ECHO Numero no aceptado )
IF !x! GTR 999 ( 
SET /A exit=1
ECHO Numero no aceptado )
IF !exit!==1 goto :LOOP
REM esto verifica si es de 3 digitos, si no lo es, regresa al inicio del repetidor

SET /A d=100
REM el valor d sera usado mas tarde a la hora de sacar digitos
FOR /L %%B IN (1,1,2) DO (

SET /A di=!x!/!d!
REM se obtienen las cifras de dividiendo por enteros el numero de 3 digitos entre d
ECHO !di!
REM imprime el digito obtenido
SET /A x=!x!-!di!*!d!
REM se elimina el digito obtenido del numero para poder sacar el siguiente
SET /A d=!d!/10
REM y se cambia d para que pase de sacar centesimas a decimas
)
	
ECHO !x!
REM imprime la unidad sobrante de x
REM llegado a este punto, los 3 digitos han sido imprimidos, el repetidor volvera a ejecutar la accion
)

pause

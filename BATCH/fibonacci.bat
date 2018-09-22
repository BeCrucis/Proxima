@echo off
setlocal enabledelayedexpansion
REM ignorad esto, son variables usabas para el correcto funcionamiento del script

set /A a=0
set /A b=1
REM esto establece los 2 primeros valores de la sucesion

set /P n="Inserte que cantidad de numeros quiere: "
set /A n=%n%
REM esto pide un valor n de numeros de fibonacci

FOR /L %%M IN (1,1,%n%) DO (
REM esto es un repetidor, ejecuta la accion n veces

set /A x=!a!+!b!
REM esto crea una variable, siendo esta el resultado de la suma entre a y b, como dicta la sucesion

echo !x!
REM imprime la variable obtenida justo arriba

set /A c=!b!
REM guarda el valor b, se usara mas tarde

set /A b=!b!+!a!
REM establece un un nuevo valor b, ahora es el mismo b sumandole a

set /A a=!c!
REM establece un nuevo valor a, que es el antiguo valor b


)


pause

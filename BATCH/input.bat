@echo off

:SET

  set /P n="Escriba N: "
  set /P m="Escriba M: "
  rem esto pide el valor N y M
  set /A n=%n%
  set /A m=%m%
  rem esto convierte los datos a numeros enteros (el input recibido arriba se obtiene como cadena de caracteres mas no como numeros)

:PRINTER
  FOR /L %%A IN (%n%,1,%m%) DO (
  echo %%A
  )
  rem esto inicia un conjunto que enpieza en N y termina en M, y el valor A toma los valores intermedios, para luego escribirlos

pause

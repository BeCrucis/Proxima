'''
Created on 6/02/2018

@author: Parada
'''

inputn = int(input("Ingrese un numero: "))

n = 1

print(inputn)

"Esto cuenta la cantidad de digitos"

while inputn >= 10:

    inputn = inputn / 10
    n += 1

"Obtencion de inputn para usos futuros(es el inputn/input original)"

inputn = inputn * 10**(n-1)

"Se procede a obtener el ultimo digito en cada iteracion de while"
"Estos seran guardados en la lista digitn en orden de iteracion, la lista es creada antes del loop"

i = 0

digitn = []

while i < n:

    ld = inputn % 10

    inputn = (inputn - ld)/10

    digitn.insert(0, ld)

    i += 1

digitn = list(map(int, digitn))
int(inputn)

print("Digitos")
print(digitn)


print("Cantidad de digitos")
print(n)

import os
os.system("pause")

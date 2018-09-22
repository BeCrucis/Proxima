'''
Created on 12/02/2018

@author: Parada
'''
"Sucesion de Fibonacci"

n1 = 1
n2 = 0

inputn = int(input("Ingrese cantidad de numeros de Fibonacci deseados: "))


for x in range(inputn):

    "n1 es la suma de los 2 digitos anteriores a su sucesion, en su caso n1 y n2"
    print(">", n1)

    n1 = n1 + n2

    "el trabajo de esto es guardar el penultimo numero para poder continuar la sucesion"
    n2 = n1 - n2

import os
os.system ("pause")

'''
Created on 19/02/2018

@author: Parada
'''
import random
import os
m = 1

while m == 1:
    a = []
    print()
    print('''Generador de numeros aleatorios!

    Si quiere generar 20 numeros aleatorios (rango 20) presione enter
    Si quiere generar otra cantidad, inserte la cantidad de numeros y a continuacion el rango''')


    i = input("Inserte cantidad de numeros aleatorios: ")


    if i == "" :
        i = 20
        r = 20
    elif i != "" :
        i = i
        r = input("Inserte rango de numeros: ")

        if r == "":
            r = 20



    for x in range(int(i)):
        a.append(random.randint(1 , int(r)))

        a = [int(x) for x in a]
        'a.sort(key=int)'

    print(a)

    i2 = input("""Continuar?
    1 = Si
    Else = No
    """)

    if i2 == "1":
        os.system("cls")
        os.system("cls")
        continue
    else:
        os._exit(1)

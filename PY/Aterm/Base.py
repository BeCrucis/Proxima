'''
Created on 6/03/2018

@author: Parada
'''


import os
import sys

subirlinea = "\x1b[1A"
borrarlinea = "\x1b[2K"


def eraselast(k=1):
    for _ in range(k):
        sys.stdout.write(subirlinea)
        sys.stdout.write(borrarlinea)


def espacio(x=1):
    for x in range(x):
        print()


base = {}
while True:

    print(" Base de datos!")
    print()
    print(" 1 = Para Consultar")
    print(" 2 = Para Agregar")
    print(" 3 = Para ver el diccionario")
    print(" Else para salir")
    espacio(1)
    i = input(" ")
    if i == "1":

        i2 = input("Que objeto busca?: ")

        try:

            print("Su dato es: ", base[i2])
            os.system("pause")
            os.system("cls")
        except KeyError:

            espacio(1)
            print("El dato: ", i2, " no fue encontrado")
            os.system("pause")
            os.system("cls")
            continue

    elif i == "2":

        i2 = input("Que busca cambiar?: ")
        espacio(1)
        base[i2] = input("Inserte el nuevo dato: ")
        print("el nuevo dato es: ", base[i2],
              " , Es correcto? (1 = Si, Else = No)")
        exitv = input()

        if exitv == "1":

            os.system("cls")
            continue
        else:

            del base[i2]
            os.system("cls")
            continue

    elif i == "3":
        os.system("cls")
        espacio(1)
        n1 = len(base)
        print("Los datos en el diccionario son: ")
        baselist = list(base.items())
        espacio(1)
        for x in range(n1):

            print(baselist[x])

        espacio(1)
        print("En total hay ", n1, " datos")
        espacio(1)
        os.system("pause")
        os.system("cls")
        continue
    else:
        break

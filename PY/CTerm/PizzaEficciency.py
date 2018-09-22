import math
import os
import sys


def espacio(x=1):
    for _ in range(x):
        print()


def main():
    print("Bienvenido al calculador de eficiencia de pizza!")

    while True:
        try:
            p = int(input("Inserte el precio: "))
            r = int(input("Inserte el radio: "))
            break
        except:
            os.system("cls")
            main()
            continue

    a = math.pi * r**2
    e = a / p

    print("El area de la pizza sera ----->   {} cm2".format(int(a)))
    print("La eficiencia es de ------> {} $/cm2".format(e))
    print(" o {} cada 1000 pesos".format(1000 * e))


main()

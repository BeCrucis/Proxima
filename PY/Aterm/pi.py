import os
import sys
import math

def espacio(x = 1):
    for _ in range(x):
        print()

def main():
    total = 0
    x = int(input("Inserte cantidad de iteraciones: "))
    espacio(1)

    for n in range(1,x+1):
        temp = 1 / n**2
        total += temp

    pi = (total * 6) ** .5

    print("pi calculado es igual a: {:.15f} ".format(pi))
    print("pi real es: {:.15f}".format(math.pi))
    print("La diferencia es de ", pi - math.pi)

main()

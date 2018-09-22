import os
import sys
import decimal
import math

def main():
    p = 1
    x = int(input("Inserte un numero: "))
    n = int(input("Inserte la potencia: "))
    for _ in range(n):
        p = p * x

    print("Potencia {} de {} es {}".format(n,x,p))
    os.system("pause")
    os.system("cls")

    x = int(input("Ahora otro numero: "))

    fact = 1
    for f in range(1,x+1):
        fact = fact * f
    print("Factorial de {} es {}".format(x,fact))


main()

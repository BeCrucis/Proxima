import os
import sys

def isprime(n):

    isprime = True
    meter = 0

    for x in range(1,n+1):
        if n % x == 0:
            meter += 1

    if meter != 2:
        isprime = False

    return isprime

def main():
    a = []

    print("Bienvenido a su medidor de numeros primos!")
    i = int(input("inserte su numero: "))
    for n in range(i):

        if isprime(n) == True:
            print("{} es primo!".format(n))
            a.append(n)
        else:
            print("{} no es primo!".format(n))

    print("La lista de primos es {}".format(a))

main()

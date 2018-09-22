import os
import sys
import math

x = float(input("Inserte un numero cualquiera! : "))
correct = 10E-100

while x != (1+5**(1/2))/2:
    if x == 0:
        x += correct
        print("X corregido en {}, division por 0 no es valida".format(correct))
    x = 1 + (1/x)

    print("{0:f}".format(x))

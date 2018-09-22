import os
import sys


x = int(input("Inserte un numero x: "))

loop = 0

for n in range(1,x):
    loop = 0
    b = n
    if round(b,10) == round(n/b,10):
        print(b)
        loop+= 1
    while round(b,10) != round(n/b,10):
        b = (1/2) * ((n / b) + b)
        print("{0:.10f}".format(b))
        loop += 1
    print("La cantidad total de iteraciones fue de {}".format(loop))

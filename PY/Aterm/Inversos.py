import os
import sys

n = float(input("Decida la cantidad de iteraciones(mas alta, mas precisa): "))
total = 0

for x in range(int(n)):
    temp = 1/2**x
    total += temp

print("{:.14f}".format(total))

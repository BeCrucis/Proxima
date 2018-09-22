import os
import sys
import decimal
import time

def prec(b,r):

    p = 0

    rl = list(str(r**(1/2)))
    bl = list(str(b))


    for n in range(len(bl)):
        if rl[n] == bl[n]:
            p +=1
        else:
            break

    return p

def main():
    p = 0
    x = 0
    iteraciones = 0
    while True:
        try:
            x = int(input("Escriba su valor x: "))
            b = x
            break
        except:
            continue

    while True:

        if p <= 10:
            p = 0
            iteraciones += 1
            b = (.5)*((x/b)+b)
        elif p > 10:
            print(b)
            break

        p = prec(b, x)

    return iteraciones




main()

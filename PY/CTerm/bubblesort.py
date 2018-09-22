import os
import sys
import random

def icreator(largo,min=0,max=99):
    conjunto = []
    for _ in range(largo):
        conjunto.append(random.randint(min,max))
    return conjunto

def sort(input):
    print(input)
    pasos = 0

    ilength = len(input)
    for x in range(ilength):

        for x in range(ilength):
            
            if x+1 != ilength:
                if input[x] > input[x+1]:
                    input[x], input[x+1] = input[x+1], input[x]
                    print (input)

        else:
            continue
        print (input)

def main():
    print("Comprobador de algoritmos de programacion, este es BUBBLE")
    input = icreator(20)
    sort(input)


main()

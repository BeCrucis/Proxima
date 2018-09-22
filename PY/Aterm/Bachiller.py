'''
Created on 14/02/2018

@author: Parada
'''
import os
p = 0

while True:

    print("Formula del bachiller!")
    print()


    try:

        a = int(input("inserte valor de x^2: "))
        b = int(input("inserte valor de x: "))
        c = int(input("inserte valor del entero (puede ser 0): "))


    except ValueError:

        print()
        print("Insert valid number")
        os.system("pause")
        os.system("cls")
        continue

    if a == 0:
        print("Error, x^2 can't be 0")
        os.system("pause")
        os.system("cls")
        continue

    b1 = b * -1
    sqrt1 = (b ** 2) - (4 * a * c )

    if sqrt1 < 0:
        print("Error, imaginary numbers not supported")
        os.system("pause")
        os.system("cls")
        continue

    b2 = sqrt1 ** .5

    x1 = (b1 + b2) / (a * 2)
    x2 = (b1 - b2) / (a * 2)


    print()
    print()
    print("Respuestas!")
    print()

    if x1 < 0:

        print("x1 = ", x1)

    else:
        print("x1 =  ", x1)

    if x2 < 0:

        print("x2 = ", x2)

    else:
        print("x2 =  ", x2)

    print()
    print("Continue? 1 = Y  else = N")

    comp = input("  ")

    if comp == "1":
        os.system("cls")
        continue

    break

import os
import sys


def main():
    total = 0

    while True:
        print("Bienvenido al adicionador de porodo!")
        try:
            i = int(input("Inserte su numero: "))
            total += i
            os.system("cls")

        except:
            print("Esta seguro de salir?  Y/N")
            i = input("")
            if i == "Y" or i == "y":
                break
            else:
                continue

    os.system("cls")
    print()
    print("El gran total es de:  {}".format(total))
    os.system("pause")


main()

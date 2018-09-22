import os
import sys
import shutil
import collections


def espacio(n = 1):
    print()

def inputer():
    grupos = {}


    i = input("Inserte un nombre: ")


    os.system("cls")

    while True:
        print("Para cancelar el input de materias presione ENTER")

        m = input("Inserte la materia: ")

        if m == "":
            break
        else:
            grupos[m] = i
        os.system("cls")

    return grupos

def main():
    x = ""
    grupom = {}

    print("Bienvenido a su archivador de materias comunes!")

    while True:

        if bool(grupom) == False:
            grupom = inputer()
            for x in grupom.keys():
                grupom[x] = [grupom[x]]


        else:
            newdict = inputer()
            for key in grupom.keys():
                for key2 in newdict.keys():
                    if key == key2:
                        grupom[key].append(newdict[key2])

                    try:
                        list(grupom.keys()).index(key2)
                        pass
                    except ValueError:
                        x = grupom.copy()
                        x[key2] = [newdict[key2]]
                    except:
                        print("ERROR")

                grupom = x

        exitv = input("Continuar? Y/N -> ")
        if exitv == 'y' or exitv == 'Y' :
            os.system("cls")
            continue
        else:
            os.system("cls")
            break

    return grupom

result = main()

print(result)

with open("result.txt","w") as r:

    for key in result.keys():
        r.write(key + ":" + str(result[key]) + "\n")

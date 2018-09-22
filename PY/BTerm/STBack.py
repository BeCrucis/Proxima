import os
import sys
import shutil
import time

pjs = { 1 : "IRONCLAD", 2 : "THE_SILENT"}

for pj in pjs:
    if os.path.exists(os.getcwd() + "\\saves\\{}.autosave".format(pjs[pj])):
        break

save = os.getcwd() + "\\saves\\{}.autosave".format(pjs[pj])

def espacio(x = 1):
    for _ in range(x) :
        print()

def copy(origen, destino):
    print("Copiando . . .")
    shutil.copy2(origen, destino)
    print("\033[1;31;40m", origen.replace(os.getcwd(), ""), "\033[1;37;40m",  " Copiado a: ", "\033[1;35;40m", destino.replace(os.getcwd(), ""), "\033[0;0m")
    espacio(1)

def main():

    print("Bienvenido al copiasaves de Porodo!")
    espacio()
    print("Detectando la cantidad de saves copiados . . .")

    n = 0

    if os.path.exists(save):
        while os.path.exists(save.replace(".autosave", "{}.autosave".format(str(n)))):
            n += 1

        if n == 0:
            print("Ninguna copia encontrada")
        elif n == 1:
            print("1 copia encontrada")
        else:
            print( n, "copias encontradas . . .")

        copy(save, save.replace(".autosave", "{}.autosave".format(n)))

    else:
        print("Save original no encontrado, saliendo . . .")
        time.sleep(3)
        sys.exit(0)

main()

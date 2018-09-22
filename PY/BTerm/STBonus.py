'By Porodo 20 / 4 / 18'

import os
import sys
import shutil

playersave = (os.getcwd() + "\\Backups\\Player\\STSPlayer")
playergame = (os.getcwd() + "\\preferences\\STSPlayer")

def espacio(x):
    for _ in range(x):
        print()

def copy(origen, destino):
    print("Copiando . . .")
    shutil.copy2(origen, destino)
    print(origen, "Copiado exitosamente A: ", destino)
    espacio(1)

def move(origen, destino):
    print("Moviendo . . .")
    shutil.move(origen, destino)
    print(origen, "Movido exitosamente A: ", destino)
    espacio(1)

def main():

    print("Bienvenido al bonus de Slay the spire! (No deberias ver esto)")

    try:
        print("Importando bonus desde {}".format(playersave))
        copy (playersave,playergame)

    except:
        print("Error")
        os.system("pause")

main()

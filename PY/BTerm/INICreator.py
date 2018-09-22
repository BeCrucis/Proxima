'''
Created on 10/04/2018

@author: Parada
'''

import os
import shutil
import sys

"Mover a carpeta de honeycomb"
move_to_rainmeter = 1
'Solo funciona si la variable de arriba es 0'
check_rainmeter = 0
honeycomb = "E:\Rainmeter\Skins\Honeycomb"

def espacio(x=1):
    for _ in range(x):
        print()

def copy(origen, destino):
    print("Copiando . . .")
    shutil.copy2(origen, destino)
    print(origen, "Copiado exitosamente A: ", destino)
    espacio(1)

def move(origen, destino):
    print("Moviendo . . .")
    try:
        shutil.move(origen, destino)
        print(origen, "Movido exitosamente A: ", destino)
        espacio(1)
    except:
        print("Movimiento de {} a {} fallido".format(origen, destino))
        espacio(1)

def crear(archivo, texto=""):
    archivo.write(texto + "\n")

def main():
    espacio()
    print("Bienvenido al creador de archivos ini!")
    if move_to_rainmeter != 1:
        print("ATENCION: Los archivos creados no seran movidos a la carpeta rainmeter")
        if check_rainmeter != 1:
            print("          Tampoco se hara la comprobacion de archivos .ini en esta")

    espacio(1)
    print("Que nombre tendra su archivo .ini?:", end=" ")
    name = input()

    normalpaths = [os.getcwd() + "\\{}.ini".format(name), os.getcwd() + "\\{0}\\{0}.ini".format(name)]
    rainmeterpaths = ["E:/Rainmeter/Skins/Honeycomb/{0}/{0}.ini".format(name)]

    possiblepaths = []

    for path in normalpaths:
        possiblepaths.append(path)

    if move_to_rainmeter == 1 or check_rainmeter == 1:

        for path in rainmeterpaths:
            possiblepaths.append(path)

    for path in possiblepaths:

        if os.path.exists(path):
            espacio(1)
            print("Archivo encontrado en {}".format(path))
            print("Leyendo . . .")
            espacio(1)
            with open(path) as f:
                print(f.read())
                espacio(1)
                os.system("pause")
                sys.exit(0)

    newfolder = str(os.getcwd() + "\\{0}".format(name))

    archivopos = input("Indique la posicion del ejecutable: ")


    with open("{}.ini".format(name), "w") as f:
        crear(f, "[Background]")
        crear(f, "Meter=Image")
        crear(f, "ImageName=#@#Images\{}.png".format(name))
        crear(f, "H=90")
        crear(f, 'LeftMouseUpAction=[{}]'.format(archivopos))
        crear(f)
        crear(f, "[Rainmeter]")
        crear(f, "Update=1000")
        crear(f)
        crear(f, "[Metadata]")
        crear(f, "Name={}".format(name))
        crear(f, "Author=Porodo")
        crear(f, "Information=MadebyPython")
        crear(f, 'License=N/A')
        crear(f, 'Version=1.0')
        print("Creacion de .ini exitosa, moviendo a carpeta . . .")
    try:
        os.makedirs(newfolder)
        move('{}.ini'.format(name), newfolder + "\\{}.ini".format(name))

    except:
        print("Creacion de carpeta fallida, creando .ini en carpeta actual . . .")

    if move_to_rainmeter == 1:

        print("Pasando .ini a carpeta rainmeter")
        move ("{}".format(name), honeycomb)

main()
os.system("pause")
sys.exit(0)

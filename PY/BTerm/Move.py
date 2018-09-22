'''
Created on 24/03/2018

@author: Parada
'''
import shutil
import os

global new

def move (origen, destino):
    shutil.move(origen, destino)
    print(origen," movido exitosamente a", destino)
    espacio(1)

def espacio(x = 1):
    for _ in range(x):
        print()


def main():
    new = True
    while True:
        espacio(1)
        if new == True:
            print("Bienvenido al muevearchivos de porodo!")
            espacio(2)
            print("A continuacion se movera su archivo")
        try:
            print("Moviendo . . . ")
            move('C:\\Users\\user\\Downloads\\Carpetas\\2k17\\A\\wea.txt', 'C:/Users/user/Downloads/Carpetas/2k17/B/wea.txt')

            break

        except OSError:

            print("Al parecer su archivo no se encontraba, buscando . . .")
            espacio(1)
            print("Encontrado!, se procedera a mover")
            espacio(1)
            move('C:\\Users\\user\\Downloads\\Carpetas\\2k17\\B\\wea.txt','C:\\Users\\user\\Downloads\\Carpetas\\2k17\\A\\wea.txt')
            new = False
            continue
        except:
            os.system("cls")
            espacio(1)
            print("Archivo no valido o no encontrado")
            espacio(1)
            os.system("pause")
            os.system("cls")
            continue


main()
os.system("pause")

" By Porodo 25 / 4 / 18"

import os
import sys
import shutil
import time, datetime

now = datetime.datetime.now()
scantime = 5
pjs = { 1 : "IRONCLAD", 2 : "THE_SILENT"}
savedir = os.getcwd() + "\\saves"

def crear(archivo, texto=""):
    archivo.write(texto + "\n")

def espacio(x = 1):
    for _ in range(x) :
        print()

def copycustom(origen, destino):
    print("Copiando save . . .")
    shutil.copy2(origen, destino)
    print("\033[1;31;40m", origen.replace(os.getcwd(), ""), "\033[1;37;40m",  " Copiado a: ", "\033[1;35;40m", destino.replace(os.getcwd(), ""), "\033[0;0m")

def main():

    print("Bienvenido al checker de Porodo! \nEsta ventana estara abierta por un rato")
    print("Este script se encargara de reemplazar saves eliminados cada {} segundos! \n".format(scantime) + "Escaneando . . .")

    backn = 0
    backlist = []

    if os.listdir(savedir) != []:

        for file in os.listdir(savedir):

            for pjvalue in pjs.values():

                if str(file.split(".")[0])[:-1] == pjvalue:
                    print("{} Encontrado".format(str(file.split(".")[0])))
                    backlist.append(str(file.split(".")[0]))

        print("{} backs encontrados!".format(len(backlist)))

    else:
        print("Ningun archivo en saves encontrado, saliendo . . .")
        os.system("pause")
        sys.exit(0)

    if backlist == []:
        print("Ningun back encontrado, saliendo . . .")
        os.system("pause")
        sys.exit(0)


    for savecheck in os.listdir(savedir):
        for pjvalue in pjs.values():
            if savecheck == pjvalue + ".autosave":
                print("Error, save original encontrado, saliendo . . .")
                os.system("pause")
                sys.exit(0)

    espacio()
    lastback = backlist[-1]

    while os.listdir(savedir) != []:

        time.sleep(scantime)

        savegame = savedir + "\\{}.autosave".format(lastback[:-1])
        saveback = savedir + "\\{}.autosave".format(lastback)

        if not os.path.exists(savedir + "\\{}.autosave".format(lastback[:-1])):
            copycustom(savedir + "\\{}.autosave".format(lastback), savedir + "\\{}.autosave".format(lastback[:-1]))
            now = datetime.datetime.now()

            if not os.path.exists(os.getcwd() + "\\backuplog.txt"):
                with open("backuplog.txt", "w") as file:
                    file.write("[{0}] El archivo {1} fue copiado a {2}\n".format(now, savegame, saveback))
            else:
                with open("backuplog.txt", "a") as file:
                    file.write("[{0}] El archivo {1} fue copiado a {2}\n".format(now, savegame, saveback))

main()

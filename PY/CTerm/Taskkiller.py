import os
import sys
import time

returnexplorer = 1

def espacio(x = 1):
    for _ in range(x):
        print()

def main():
    listan = "kills.txt"
    print("Bienvenido al matatasks de porodo, esto intentara destruir los procesos en la lista {}".format(listan))
    with open(listan) as l:
        tasks = l.read().splitlines()
    espacio()
    print("Se eliminaran los siguientes procesos: ", tasks)

    for task in tasks:
        os.system("TASKKILL /F /IM {}".format(task))

    os.system("pause")

    if returnexplorer == 1:

        time.sleep(2)
        os.system("explorer.exe")


main()

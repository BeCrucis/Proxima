'''
Created on 24/03/2018

@author: Parada
'''
import sys
import os
import shutil

silentsave ="E:/My Games/Slay.the.Spire.Patch.16/Backups/THE_SILENT.autosave"
ironcladsave="E:/My Games/Slay.the.Spire.Patch.16/Backups/THE_IRONCLAD.autosave"
silentgame="E:/My Games/Slay.the.Spire.Patch.16/saves/THE_SILENT.autosave"
ironcladgame="E:/My Games/Slay.the.Spire.Patch.16/saves/THE_IRONCLAD.autosave"
silentback="E:/My Games/Slay.the.Spire.Patch.16/Backups/Silent/THE_SILENT.autosave"
ironcladback="E:/My Games/Slay.the.Spire.Patch.16/Backups/Ironclad/THE_IRONCLAD.autosave"
playersave = "E:/My Games/Slay.the.Spire.Patch.16/Backups/Player/STSPlayer"
playergame = "E:/My Games/Slay.the.Spire.Patch.16/preferences/STSPlayer"

global pj

def espacio(x):
    for _ in range(x):
        print()

def copy(origen, destino):
    print("Copiando . . .")    
    shutil.copy2(origen, destino)
    print(origen.replace("E:/My Games/Slay.the.Spire.Patch.16/","E:/%gamedir%/"), "Copiado exitosamente A: ", destino.replace("E:/My Games/Slay.the.Spire.Patch.16/","E:/%gamedir%/"))    
    espacio(1)  
           
def move(origen, destino):
    print("Moviendo . . .")    
    shutil.move(origen, destino)
    print(origen, "Movido exitosamente A: ", destino)    
    espacio(1)

def main():
    
    while True:
        print("Bienvenido al muevesaves de porodo!")
        espacio(2)
        print("Creando copia de seguridad...")
        try:
            copy(silentgame, silentback)
        except:
            print("Carpeta silent no encontrada, continuando . . .")
        try:
            copy(ironcladgame, ironcladback)
        except:
            print("Carpeta ironclad no encontrada, continuando . . .")
        espacio(1)
        print("Fase 1 completada, pasando a traspaso de save")
        
        while True:
            print("Silent = 0, Ironclad = 1, Enter = Bonus:", end = " ")
            pj = input()
            print(end = "\n")
        
            if pj == "0":
                print("Usted ha seleccionado Silent, continuando con el traspaso de save. . .")
                try:
                    copy(silentsave, silentgame)
                    os.system("pause")
                    sys.exit(0)
                except OSError:
                    print("Save Silent no encontrado, importando saves", end="\n")
                    break
            
            elif pj == "1":
                print("Usted ha seleccionado Ironclad, continuando con el traspaso de save. . .")
                try:
                    copy(ironcladsave, ironcladgame)
                    os.system("pause")
                    sys.exit(0)
                except OSError:
                    print("Save Ironclad no encontrado, importando saves", end="\n")
                    break
                
            elif pj == "":
                print("Usted ha seleccionado el bonus, exportando STSPlayer")
                try:
                    copy(playersave, playergame)
                    os.system("pause")
                    sys.exit(0)
                except OSError:
                    print("STSPlayer no encontrado, saliendo . . .")
                    os.system("pause")
                    sys.exit(0)
                
        espacio(1)
        print("Fase 2 saltada, procediendo a importacion de saves")
        
        if pj == "0":
            
            try:
                copy(silentgame, silentsave)
                print("Importacion completa :D")
                break
            except OSError:
                print("Archivo no encontrado, saliendo . . .")
                os.system("pause")
                sys.exit(0)
                
        elif pj == "1":
            
            try:
                copy(ironcladgame, ironcladsave)
                print("Importacion completa :D")
                break
            except OSError:
                print("Archivo no encontrado, saliendo . . .")
                os.system("pause")
                sys.exit(0)
                
                
        
try:
    main()
except SystemExit:
    print("Saliendo . . .")
except:
    print("Error desconocido")
    os.system("pause")

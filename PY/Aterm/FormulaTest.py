'''
Created on 11/03/2018

@author: Parada
'''

import os
while True:
    
    try:
        
        i = float(input("Ponga su numero: "))
        
    except ValueError:
    
        print("Error, ponga un numero")
        os.system("pause")
        os.system("cls")
        continue
    
    numerador = (i ** 2) - (i * 2) - 3
    denominador = (i**2) - 1
    
    try:
        result = numerador / denominador
        
    except ValueError:
        
        print("Error, no divida por 0 we")
        os.system("pause")
        os.system("cls")
        continue
    
    print("El valor de y es: ", result)
    
    try:
        
        verifier = float(input("Escriba un numero para salir, letra o enter para continuar: "))
        break
        
    except:
        continue
        
import random
import os
import sys

a = random.randint(1,2)
failed = 0
failedtotal = 0
success = 0
recordh = 0
recordl = 100

while True:
    b = random.randint(1,2)

    if success == 10000:
        print("Experimento terminado, cantidad de aciertos designados: ", success)
        print("Total de fallas: ", failedtotal)
        print("Promedio de total de fallas: ", failedtotal / success)
        print("La mayor cantidad de fallas fue {}, y la menor fue {}".format(recordh,recordl))
        break

    if b == a:
        print("Numero encontrado, el numero es: {}".format(a))
        print("En total hubieron {} intentos fallidos".format(failed))
        a = random.randint(1, 2)
        success +=1
        failedtotal += failed
        if failed > recordh:
            recordh = failed
        if failed < recordl:
            recordl = failed
        failed = 0
    else :
        failed += 1
        continue

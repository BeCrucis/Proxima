import os
import sys
import random

dados = 3


def generador(dados=2):
    result = []
    for _ in range(dados):
        result.append(random.randint(1, 6))

    return result


def main(intentos = 100000):
    print("Calculador de probabilidades con dados!")
    success = 0
    for _ in range(intentos):

        try:
            generador(dados).index(random.randint(1, 6))
            success += 1
        except:
            pass

    print("De {} intentos, {} fueron exitosos".format(intentos, success))
    print("Eso es un {:%} de exito".format((success/intentos)))

main()

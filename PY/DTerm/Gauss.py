import os
import sys
import fractions as fs


def espacio(x=1):
    for _ in range(x):
        print()


def mostrar(x, fx, cx, prompt):
    print(prompt)
    espacio(1)

    for f in range(fx):
        for c in range(cx):
            s = str(x[f][c])
            print("|{:^9}|".format(s), end="")
        print()
        
        for c in range(cx + 1):
            print("".rjust(8, "-"), end="")
        print()

    espacio(1)


def main():

    fx = int(input("Inserte el numero de filas de la matriz: "))
    cx = int(input("Inserte el numero de columnas de la matriz: "))

    x = [[fs.Fraction(int(input("Inserte la coordenada [{}][{}]: ".format(
        y + 1, x + 1))), 1) for x in range(cx)] for y in range(fx)]

    t = [fs.Fraction(int(input(
        "Inserte la solucion de la fila [{}]: ".format(y + 1))), 1) for y in range(fx)]

    for i in range(fx):
        x[i].append(t[i])

    cx = cx + 1

    mostrar(x, fx, cx, "Su matriz es :")


    if fx + 1 < cx:
        print("Filas menores que columnas detectadas")
        print("La matriz tiene infinitas soluciones")
        mostrar(x, fx, cx, "Matriz resultado: ")
        return 0


    cc = 0

    for f in range(fx):  # Va por cada fila de la matriz

        if x[f][cc] == 0 and cc == f:
            found = False

            if f != fx - 1:  # No puedo verificar por filas para intercambiar si ya estoy en la ultima
                for s in range(f, fx):
                    if x[s][cc] != 0:
                        t = x[f]
                        x[f] = x[s]
                        x[s] = t
                        found = True

            if found == False:
                print("La matriz o no tiene soluciones o tiene infinitas soluciones, detectando . . .\n")

                if x[f][cx-1] == 0:
                    print("La matriz tiene infinitos resultados")
                else:
                    print("La matriz no tiene resultados")
                mostrar(x, fx, cx, "Matriz resultante:")
                return 0

        if x[f][cc] != 1 and cc == f:  # Verifica la coordenada que deberia ser 1, sino, la convierte en 1

            di = fs.Fraction(1, x[f][cc])

            for c in range(cx):

                x[f][c] = fs.Fraction(x[f][c] * di, 1)

        for f2 in range(fx):

            if f2 != cc:

                mu = fs.Fraction(-1 * x[f2][cc], 1)

                for c2 in range(cx):
                    x[f2][c2] = fs.Fraction(
                        x[f][c2] * mu, 1) + fs.Fraction(x[f2][c2], 1)

        cc = cc + 1


    mostrar(x, fx, cx, "Resultado:")

    for c in range(cc):
        print("X{} = {}".format(c + 1, x[c][cx - 1]))

    return 0

main()
os.system("pause")

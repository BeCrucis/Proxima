from Asignatura import Asignatura

codigos = [20253, 20254, 20255]

for codigo in codigos:

    asig = Asignatura(codigo)
    asig.sortGroups()

    with open(F"{asig.nombre}.txt", "w") as f:

        for grupo in asig.grupos:
            f.write(str(grupo) + "\n")
def MCD(a, b):

    c = a % b
    print(f"{a} mod {b} = {c}")

    if c == 0:
        return
    else:
        MCD(b, c)

def notas():

    pesoFisica = 4
    pesoMD = 4
    pesoIngles = 4
    pesoEstructuras = 4
    pesoCredito = 1

    pesoTotal = pesoFisica+pesoMD+pesoIngles+pesoEstructuras+pesoCredito

    notaFisica = 4.1
    notaMD = 4.5
    notaIngles = 4.9
    notaEstructuras = 4.9
    notaCredito = 5 

    notaTotal = notaFisica*pesoFisica+notaMD*pesoFisica+notaIngles*pesoFisica+notaEstructuras*pesoFisica+notaCredito*pesoCredito
    notaPonderada = notaTotal/pesoTotal

    print(notaPonderada)

notas()
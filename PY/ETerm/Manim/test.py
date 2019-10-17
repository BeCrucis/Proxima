import random


holo = {}

for n in range(10):
    holo[n] = n+1
x = sorted(list(holo))
print(x)

def a():

    def coso(x):
        return x**2

    return coso
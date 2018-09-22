import os, sys
import random
import string

def rdom(n = 5):
    return "".join(str(random.choice(string.ascii_uppercase + "1234567890")) for x in range(n))

try:
    with open("r.txt") as r:
        linenum = len(r.readlines())
except:
    linenum = 0
finally:
    if linenum >= 25:
        with open("r.txt","w") as c:
            c.write("")

with open("r.txt", "a") as c:
    for _ in range(5):
        c.write(rdom() + '\n')

print("El archivo tiene {} lineas".format(linenum))

if linenum >= 25:
    print("El archivo llevo al limite de lineas, eliminando datos . . .")

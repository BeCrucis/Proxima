import os, sys
import shutil

n=0

with open('Test.txt', 'w') as f:
    f.write('hola, soy bugs buny\n')
    f.write("Chao")

with open('Test.txt', "r") as f:
    data = f.read()

data = data.replace("hola", "Ahorasddoypior")

with open('Test.txt', "w") as f:
    f.write(data)

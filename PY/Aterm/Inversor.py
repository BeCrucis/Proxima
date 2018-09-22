'''
Created on 3/03/2018

@author: Parada
'''
import os

a = int(input("Meta el valor de a "))
b = int(input("Meta el valor de b "))
c = []

c.append(a)
c.append(b)

print(c)

a = c.pop()
b = c.pop()

print(a)
print(b)
os.system("pause")

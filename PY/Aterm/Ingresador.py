'''
Created on 21/02/2018

@author: Parada
'''
import os
import sys


def digitador (i):
   
    _n = 0
    i2 = i
    i3 = i
    a2 = []

    while i2 >= 1 :     
        
        i2 = i2 / 10
        _n += 1


      
    for _ in range(_n): 
            
        _l = i3 % 10
        i3 = (i3 - _l) /10
        
        _l = int(_l)
        a2.append(_l)
        
    a2.reverse()
    a.extend(a2)


CURSOR_UP_ONE = '\x1b[1A'
ERASE_LINE = '\x1b[2K'

def eraselast (k=1):
    
    for _ in range(k):
        
        sys.stdout.write(CURSOR_UP_ONE)
        sys.stdout.write(ERASE_LINE)
    
a = []
l = []
n = 0
k = 0
l1 = 0
extran = 0

while True:
    
    i = input("Inserte el siguiente digito: ")
    
    eraselast(k)
    
    
    
    if i == "":
        
        break
    
    try:
       
        i = int(i)
        i2 = i
        
        while i2 > 9:
            i2 = i2 / 10
            extran += 1
            
        digitador(i)
       
    except ValueError:
        print("Solo numeros >:v")
        os.system("pause")
        eraselast(k=3)
        continue 
        
        
    
    
    
    
    
    print(a)
    
    n += 1 + extran
    
   
while True:    
    try:
            
        for x in range(n):
            
            l1 = a.pop()
            
            l.append(l1)
            
            a = list(map(lambda x: x*10, a))
            
            
    except:
        
        break

try:
    os.system("cls")
    
    print("Aca esta tu numero :D")
    print()
    rsult = sum(l)     
    print ("------------>   ", rsult, "   <-------------")
    
    
except ValueError:
    
    print("Input invalido")
    
print()
os.system("pause")



















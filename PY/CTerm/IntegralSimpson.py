import os
import math

def integral(a, b, n):
    
    if n % 2 == 1:
        n += 1
        print(n)

    h = (b - a) / n

    suma = f(a) + f(b)

    for i in range(1,n,2):
        suma += 4 * f(a + (i * h))

    for i in range(2,n,2):
        suma += 2 * f(a + (i * h))  

    return suma * (h/3)

def f(x): #Esta sera la funcion a integrar

    y = x**3; #En este ejemplo se tiene la funcion y = cos(x)

    return y


print(integral(1,10,4))
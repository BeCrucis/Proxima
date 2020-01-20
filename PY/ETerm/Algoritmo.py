import os
import sys

n = input("Inserte n: ")

n = int(n)

print("---------------------------------------")
print("|  i  |  j  |  k  |  n  | suma | #rep |")
print("---------------------------------------")

suma = 0
i = 1
j,k = 0, 0

print(f"|{str(i).center(5)}|{str(j).center(5)}|{str(k).center(5)}|{str(n).center(5)}|{str(suma).center(6)}|{str(suma).center(6)}|")

while i <= n:

    print(f"|{str(i).center(5)}|{str(j).center(5)}|{str(k).center(5)}|{str(n).center(5)}|{str(suma).center(6)}|{str(suma).center(6)}|")

    for j in range(1, n+1):

        print(f"|{str(i).center(5)}|{str(j).center(5)}|{str(k).center(5)}|{str(n).center(5)}|{str(suma).center(6)}|{str(suma).center(6)}|")

        for k in range(1, n+1):

            suma = suma+1
            print(f"|{str(i).center(5)}|{str(j).center(5)}|{str(k).center(5)}|{str(n).center(5)}|{str(suma).center(6)}|{str(suma).center(6)}|")
    
    i *= 2

print(f"|{str(i).center(5)}|{str(j).center(5)}|{str(k).center(5)}|{str(n).center(5)}|{str(suma).center(6)}|{str(suma).center(6)}|")
print("---------------------------------------")

print(f"La suma es {suma}")
os.system("pause")
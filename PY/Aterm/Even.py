import os
import sys

def evenchk(n):
    iseven = True

    if n % 2 != 0:
        iseven = False

    return iseven

def main():
    i = int(input("Inserte su numero: "))
    print (evenchk(i))

main()

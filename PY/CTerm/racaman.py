import os
import sys

def racaman(largo):
    n = 0
    n2 = n
    c = [0]
    for _ in range(largo):
        c.append(n)
        delta = abs(n - n2)
        n2 = n

        if n - delta - 1 not in c and n - delta - 1 > 0:
            n = n - delta - 1

        else:
            n = n + delta + 1

    del c[0]
    return c

def main():
    print(racaman(100))

main()

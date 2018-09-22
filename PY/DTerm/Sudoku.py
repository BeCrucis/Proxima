import os
import sys
import random
import shutil
import deque
import turtle

info = {}
linelenght = 9
columnlenght = 9



def espacio(x = 1):
    for _ in range(x):
        print()

def linecord():
    x = {}
    for n in range (linelenght):
        x[n] = lineinfo[n]

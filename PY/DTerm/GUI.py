import os
import sys
import tkinter as tk
from tkinter import ttk
import moment
from pygame import mixer

WBNAME = "EJEMPLO.xlsx"
VER = "0.1"
VERDATE = moment.now().format("YYYY/MM/DD")

def main():
    root = tk.Tk()
    root.title("REGISTRADORA <{}>  [Versión {} ({})]\n".format(WBNAME, VER, VERDATE))
    root.minsize(900, 600)

    def sound():asds

        mixer.init()
        mixer.music.load('sound.mp3')
        mixer.music.play()
        label.config(text = "LO TOCASTE")

    button = ttk.Button(root, text = "Tocadme", command = sound)
    button.grid(column = 1, row = 1)

    for n in range(2, 30):

        label = ttk.Label(root, text = "Linea #{}".format(n))
        label.grid(column = 1, row = n)

        label = ttk.Label(root, text = "Columna #{}".format(int(n/2)))
        label.grid(column = int(n/2) + 1, row = 1)

    tk.mainloop()




main()

import winsound
import tkinter as tk
from tkinter import ttk
from tkinter import scrolledtext
from pygame import mixer 


win = tk.Tk()
win.title("Hola Mundo!")
alabel = ttk.Label(win, text = "Hey!")
alabel.grid(column = 0, row = 1)

tlabelnumber = 1
tlabel = ttk.Label(win, text = str(tlabelnumber))
tlabel.grid(column = 1, row = 1)

def clickevent():

    global strname, tlabelnumber

    strname = name.get()

    if not strname:
        return
    
    tlabelnumber += 1
    action.configure(text = "ME TOCASTE")
    mixer.init()
    mixer.music.load(r'sound.mp3')
    mixer.music.play()
    alabel.configure(foreground = 'red')
    alabel.configure(text = "Su nombre es {}".format(name.get()))
    tlabel.configure(text = str(int(tlabelnumber)))

name = tk.StringVar()
inputname = ttk.Entry(win, width = 12, textvariable = name)
inputname.grid(column = 0, row = 0)

action = ttk.Button(win, text = "Tocadme!", command = clickevent)
action.grid(column = 1, row = 0)

W = 30
H = 10
scroll = scrolledtext.ScrolledText(win, width = W, height = H)
scroll.grid(column = 0, columnspan = 2)


win.mainloop()
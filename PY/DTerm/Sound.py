from pygame import mixer # Load the required library
import os, sys



for n in range(1000):
    mixer.init()
    mixer.music.load(r'sound.mp3')
    mixer.music.play(-1)

os.system("pauses")


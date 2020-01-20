import os
import sys

files = [f for f in os.listdir('.') if os.path.isfile(f) and f[-4] != "."]

for file in files:

    new_name = file + ".mp3"

    os.rename(file, new_name)
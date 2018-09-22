'''
Created on 19/02/2018

@author: Parada
'''
import os
import time
counter = 0

while True:
    time.sleep(1/3.3)
    if counter == 3:
        os.system("cls")
        counter = 0
    counter += 1
    print(counter)

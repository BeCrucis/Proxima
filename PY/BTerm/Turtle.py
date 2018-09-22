'''
Created on 12/03/2018

@author: Parada
'''

import turtle
import random

n = 0
wn = 0
jerry = 0

def rectangulo(forma):
    
    forma.forward(35)
    forma.left(90)
    forma.forward(200)
    forma.left(90)
    forma.forward(70)
    forma.left(90)
    forma.forward(300)
    forma.left(90)
    forma.forward(70)
    forma.left(90)
    forma.forward(100)
    
def circulor(forma):
    
    for _ in range(360):
        forma.right(1)
        forma.forward(1)
    
def circulol(forma):
    
    for _ in range(360):
        forma.left(1)
        forma.forward(1)
        
def caos(forma, i = 100):
    
    for _ in range(i):
        forma.left(random.randint(1,90))
        forma.forward(random.randint(1,15))
        forma.right(random.randint(1,90))
        forma.forward(random.randint(1,15))
        if abs(forma.pos()) > 50:
            forma.left(180)
            forma.forward(15)
            continue
    
def cuadrado(forma):
    
    for _ in range(4):
        
        forma.fd(100)
        forma.left(90)
        
def corazon(forma):
    
    forma.left(45)
    forma.forward(100)
    forma.left(90)
    forma.forward(50)
    forma.left(90)
    forma.forward(50)
    forma.right(90)
    forma.forward(50)
    forma.left(90)
    forma.forward(50)
    forma.left(90)
    forma.forward(100)

def estrellaA(forma):
    
    forma.begin_fill()
    while True:
        forma.forward(200)
        forma.left(170)
        if abs(forma.position()) < 1:
            break
        
    forma.end_fill()
    
def main():
    n = 0
    screen = turtle.Screen()
    screen.bgcolor("white")
    
    jerry = turtle.Turtle()
    "jerry.color("#20C20E")
    jerry.color("green", "black")
    jerry.pensize(3)
    jerry.speed("fastest")
    jerry.begin_fill()
    
    for _ in range(1):
        
        cuadrado(jerry)
    
    jerry.end_fill()
    
    
    bob = turtle.Turtle()
    
    bob.forward(50)
    bob.color("pink", "pink")
    bob.speed("fastest")
    
    bob.begin_fill()
    for _ in range(6):
        bob.write(n, False, "center", ("Arial", 40, "normal"))
        bob.fd(50)
        n += 1
    
    bob.end_fill()
    
    jake = turtle.Turtle()
    jake.speed("fastest")
    jake.color("blue","blue")
    
    jake.right(180)
    jake.forward(500)
    jake.begin_fill()
    circulor(jake)
    jake.end_fill()
    
    
    screen.exitonclick() 
    

if __name__ == "__main__":
    main()
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

    

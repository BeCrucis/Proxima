import os, sys
import turtle
import math

ask = 1
screen = turtle.Screen()
bob =turtle.Turtle()

def pizzator(forma, d):
    forma.seth(90)
    forma.setpos(0,0)
    forma.penup()
    forma.fd(d*3)
    forma.lt(90)
    forma.pendown()
    forma.circle(d*3)
    forma.rt(90)
    forma.speed("fast")


def write(forma, texto):
    forma.write(texto, align="right",font=("Consolas", 12, "normal") )


def main():

    if ask == 1:
        d = screen.numinput("Pizza", "Diameter")
        p = screen.numinput("Pizza", "Precio(En miles de pesos)")

    else:
        d = 41
        p = 35

    a = math.pi * (d/2) ** 2
    e = a / p

    pizzator(bob, d)
    bob.ht()

    bob.penup()
    bob.setx(turtle.screensize()[0]/1.2)
    bob.sety(turtle.screensize()[1]/1.2)
    write(bob, "Eficiencia: {} cm2/1k".format(e))



    screen.exitonclick()



main()

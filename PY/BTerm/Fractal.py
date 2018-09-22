#By porodo 1/05/18

import turtle

kocher = turtle.Turtle()
screen = turtle.Screen()
screen.screensize(400,300)

def koch(forma,tamaño,iteraciones = 1):
    if iteraciones > 0:
        for angle in [60,-120,60,0]:
            koch(forma,tamaño/3,iteraciones - 1)
            forma.lt(angle)
    else:
        forma.fd(tamaño)

kocher.speed("fastest")
kocher.hideturtle()
kocher.penup()
kocher.sety(screen.screensize()[0]/1.74)
kocher.backward(screen.screensize()[1]/1.74)
turtle.delay(0)
turtle.tracer(0,0)
kocher.pendown()
iteraciones = screen.numinput("Iteraciones", "Grado de fractal:", 5, minval=0, maxval=20)


for _ in range(3):
    koch(kocher,500,iteraciones)
    kocher.rt(120)
    turtle.update()

screen.exitonclick()

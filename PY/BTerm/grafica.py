import numpy as np
import matplotlib.pyplot as plt
def arsech(x):
    return np.arccosh(1/x)
def tractriz(x, a):
    return a*arsech(x/a) - np.sqrt(a**2 - x**2)
def derivada_tractriz(x, a, h):
    y1 = tractriz(x, a)
    y2 = tractriz(x+h, a)
    return (y2-y1)/h

a  = 16.0  # Posición inicial
h  =  1e-3 # Delta x para aproximar derivada
x0 =  4.0  # Pocición inicial para graficar línea tangente (pendiente)
y0 = tractriz(x0, a)
m = derivada_tractriz(x0, a, h)  # Pendiente de línea tangente a tractriz en punto (x0, y0)
x1 =  0.0  # Posición final para graficar línea tangente (pendiente)
y1 =  m * (x1-x0) + y0
x = np.linspace(1,a,1000)
plt.plot(x,tractriz(x, a), '--', lw=1, label='Trayectoria tractriz')
plt.plot([x0, x1], [y0, y1], 'o-k', label='Recta tangente a la tractriz')
plt.xlabel(r'$x$ $[m]$')
plt.ylabel(r'$y$ $[m]$')
plt.legend()
plt.show()

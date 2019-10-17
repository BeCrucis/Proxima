from manimlib.imports import *
import os
import numpy as np
import sys
import openpyxl

sys.path.insert(1, "F:/Downloads/Carpetas/Programs/Programming/PY/ETerm/Manim")
from ManimUtils import ScreenGrid
import MountingData

#pylint: disable=undefined-variable
#pylint: disable=no-member

COLOR_GRADIENT_RAW = list(Color("red").range_to(Color("blue"),9))
COLOR_GRADIENT = []
print(COLOR_GRADIENT_RAW[0].get_hex())

for color in COLOR_GRADIENT_RAW:
    COLOR_GRADIENT.append(color.get_hex())

COLOR_GRADIENT_2 = []
N = 9

for i in range(N):
    colorTemp = Color(red = (255/(255*(N-1)))*i, green = 60/255, blue = (255/(255*(N-1)))*(N-1-i))
    colorTemp = colorTemp.get_hex()
    COLOR_GRADIENT_2.append(colorTemp)

COLOR_GRADIENT_2.reverse()

class RectangleRectangle(GraphScene):

    def construct(self):

        grid = NumberPlane()
        self.add(grid)

        dots = {}

        mounting = MountingData.RR()

        #Dibujar los electrodos
        leftCorners = mounting.electrodes[0]
        leftVertices = []

        for x,y in leftCorners:
            leftVertices.append((x,y,0))
        
        leftElectrode = Polygon(*leftVertices, color = BLUE).set_fill(BLUE,0.4)
        self.play(ShowCreation(leftElectrode))

        rightCorners = mounting.electrodes[1]
        rightVertices = []

        for x,y in rightCorners:
            rightVertices.append((x,y,0))
        
        rightElectrode = Polygon(*rightVertices, color = RED).set_fill(RED,0.4)
        self.play(ShowCreation(rightElectrode))

        #Hacer las lineas equipotenciales

        equipotentialLines = {}
        sortedVoltages = sorted(list(mounting.equiLines))
        print(sortedVoltages)
        
        equipotentialLines = {v: mounting.equiLines[v] for v in sortedVoltages}


        for voltage in equipotentialLines:
            dotPos = equipotentialLines[voltage]
            voltageColor = COLOR_GRADIENT_2[voltage + 4]
            dotIndex = 0
            for x,y in dotPos:
                dots[dotIndex] = self.createDot(x,y, voltageColor)
                dotIndex += 1
            
            dotList = [dots[n] for n in dots]

            dotList.sort(key=lambda x: x.get_center()[1])
            
            for dot1, dot2 in zip(dotList[:-1], dotList[1:]):
                self.connectDots(dot1, dot2, voltageColor)

        self.wait(4)
        
    def createDot(self, x, y, color = WHITE):
        dot = Dot(np.array([x, y, 0]), color = color)
        self.play(GrowFromCenter(dot), run_time = .2)
        return dot
    
    def connectDots(self, dot1, dot2, color = WHITE):
        line = Line(dot1.get_center(), dot2.get_center(), color = color)
        self.play(GrowFromPoint(line, dot1.get_center()), run_time = .3)
        return line

class CircleRectangle(GraphScene):

    def construct(self):

        grid = NumberPlane()
        self.add(grid)

        dots = {}

        mounting = MountingData.CR()

        #Dibujar los electrodos

        leftCenter = (mounting.electrodes[0][0][0], mounting.electrodes[0][0][1], 0)
        leftRadius = mounting.electrodes[0][1]
        
        leftElectrode = Circle(radius = leftRadius, color = BLUE).set_fill(BLUE,0.4)
        leftElectrode.move_to(leftCenter)
        self.play(ShowCreation(leftElectrode))

        rightCorners = mounting.electrodes[1]
        rightVertices = []

        for x,y in rightCorners:
            rightVertices.append((x,y,0))
        
        rightElectrode = Polygon(*rightVertices, color = RED).set_fill(RED,0.4)
        self.play(ShowCreation(rightElectrode))

        #Hacer las lineas equipotenciales

        equipotentialLines = {}
        sortedVoltages = sorted(list(mounting.equiLines))
        
        equipotentialLines = {v: mounting.equiLines[v] for v in sortedVoltages}


        for voltage in equipotentialLines:
            dotPos = equipotentialLines[voltage]
            voltageColor = COLOR_GRADIENT_2[voltage + 4]
            dotIndex = 0
            for x,y in dotPos:
                dots[dotIndex] = self.createDot(x,y, voltageColor)
                dotIndex += 1
            
            dotList = [dots[n] for n in dots]

            dotList.sort(key=lambda x: x.get_center()[1])
            
            for dot1, dot2 in zip(dotList[:-1], dotList[1:]):
                self.connectDots(dot1, dot2, voltageColor)
        
        self.wait(4)
        
    def createDot(self, x, y, color = WHITE):
        dot = Dot(np.array([x, y, 0]), color = color)
        self.play(GrowFromCenter(dot), run_time = .2)
        return dot
    
    def connectDots(self, dot1, dot2, color = WHITE):
        line = Line(dot1.get_center(), dot2.get_center(), color = color)
        self.play(GrowFromPoint(line, dot1.get_center()), run_time = .3)
        return line

def main():
    
    os.system("manim Manim.py RectangleRectangle -pl")

if __name__ == "__main__":
    main()    
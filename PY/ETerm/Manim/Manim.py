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

class DoSomething(GraphScene):

    def construct(self):

        grid = NumberPlane()
        self.add(grid)

        dots = {}

        mounting = MountingData.CC()

        for voltage in mounting.equiLines:
            dotPos = mounting.equiLines[voltage]
            dotIndex = 0
            for x,y in dotPos:
                dots[dotIndex] = self.createDot(x,y)
                dotIndex += 1
            
            dotList = [dots[n] for n in dots]

            dotList.sort(key=lambda x: x.get_center()[1])
            
            for dot1, dot2 in zip(dotList[:-1], dotList[1:]):
                self.connectDots(dot1, dot2)
        
    def createDot(self, x, y):
        dot = Dot(np.array([x, y, 0]))
        self.play(GrowFromCenter(dot), run_time = .2)
        return dot
    
    def connectDots(self, dot1, dot2):
        line = Line(dot1.get_center(), dot2.get_center())
        self.play(GrowFromPoint(line, dot1.get_center()))
        return line

def main():
    
    os.system("manim Manim.py DoSomething -pl")

if __name__ == "__main__":
    main()    
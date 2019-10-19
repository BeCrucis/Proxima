from manimlib.imports import *
import os
import numpy as np
import sys
import openpyxl
import math

sys.path.insert(1, "F:/Downloads/Carpetas/Programs/Programming/PY/ETerm/Manim")
from ManimUtils import *
import MountingData

#pylint: disable=undefined-variable
#pylint: disable=no-member

COLOR_GRADIENT_RAW = list(Color("red").range_to(Color("blue"),9))
COLOR_GRADIENT = []

for color in COLOR_GRADIENT_RAW:
    COLOR_GRADIENT.append(color.get_hex())

COLOR_GRADIENT_2 = []
N = 9

for i in range(N):
    colorTemp = Color(red = (255/(255*(N-1)))*i, green = 60/255, blue = (255/(255*(N-1)))*(N-1-i))
    colorTemp = colorTemp.get_hex()
    COLOR_GRADIENT_2.append(colorTemp)

COLOR_GRADIENT_2

class RectangleRectangle(GraphScene):

    def construct(self):

        grid = createGrid(self,-10, 11, -5, 6)

        mounting = MountingData.RR()

        #Dibujar los electrodos
        leftCorners = mounting.electrodes[0]
        leftVertices = []

        for x,y in leftCorners:
            leftVertices.append((x,y,0))
        
        leftElectrode = Polygon(*leftVertices, color = RED).set_fill(RED,0.4)
        self.play(DrawBorderThenFill(leftElectrode))

        rightCorners = mounting.electrodes[1]
        rightVertices = []

        for x,y in rightCorners:
            rightVertices.append((x,y,0))
        
        rightElectrode = Polygon(*rightVertices, color = BLUE).set_fill(BLUE,0.4)
        self.play(DrawBorderThenFill(rightElectrode))

        #Hacer las lineas equipotenciales

        self.createEquiLines(mounting.equiLines)
        self.createField()

        self.wait(4)
        
    def createDot(self, x, y, color = WHITE):
        return createDot(self, x, y, color)
    
    def connectDots(self, dot1, dot2, color = WHITE):
        return connectDots(self, dot1, dot2, color)
    
    def createEquiLines(self, equiLinesData):

        dots = {}
        equipotentialLines = {}
        sortedVoltages = sorted(list(equiLinesData))
        
        equipotentialLines = {v: equiLinesData[v] for v in sortedVoltages}

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
            
            tempX = dotList[2].get_center()[0]
            
            voltLine = Rectangle(height = FRAME_HEIGHT+1, width = (11+tempX)*2).set_fill(voltageColor,0.1).set_stroke(color = voltageColor, width = 10)
            voltLine.move_to((-11,0,0))
            self.play(DrawBorderThenFill(voltLine))
    
    def createField(self):

        graph1 = Line((-6,4,0), (6,4,0))
        self.play(ShowCreation(graph1))

        graph2 = Line((-6,0,0), (6,0,0))
        self.play(ShowCreation(graph2))

        graph3 = Line((-6,-4,0), (6,-4,0))
        self.play(ShowCreation(graph3))
  
        alpha = ValueTracker(0)
        
        vector1 = get_tangent_vector(alpha.get_value(),graph1,scale=1)
        dot1 = Dot()
        dot1.add_updater(lambda m: m.move_to(vector1.get_start()))

        vector2 = get_tangent_vector(alpha.get_value(),graph2,scale=1)
        dot2 = Dot()
        dot2.add_updater(lambda m: m.move_to(vector2.get_start()))

        vector3 = get_tangent_vector(alpha.get_value(),graph3,scale=1)
        dot3 = Dot()
        dot3.add_updater(lambda m: m.move_to(vector3.get_start()))

        self.play(
            GrowFromCenter(dot1),
            GrowArrow(vector1),
            GrowFromCenter(dot2),
            GrowArrow(vector2),
            GrowFromCenter(dot3),
            GrowArrow(vector3)
            )

        text = TexMobject(r"\vec{E}")
        text.next_to(dot1, UL, buff=SMALL_BUFF)
        self.play(ShowCreation(text))

        def updateFunc(text):
            text.next_to(dot1, UL, buff=SMALL_BUFF)
        
        text.add_updater(updateFunc)

        vector1.add_updater(
            lambda m: m.become(
                    get_tangent_vector(alpha.get_value()%1,graph1,scale=1)        
                )
                
            )
        
        vector2.add_updater(
            lambda m: m.become(
                    get_tangent_vector(alpha.get_value()%1,graph2,scale=1)        
                )
            )
        
        vector3.add_updater(
            lambda m: m.become(
                    get_tangent_vector(alpha.get_value()%1,graph3,scale=1)        
                )
            )
        
        self.add(vector1,dot1,vector2,dot2,vector3,dot3)
        self.play(alpha.increment_value, 0.99, run_time=5, rate_func=smooth)

        text.remove_updater(updateFunc)

        self.wait(5)

        self.play(
            Uncreate(dot1),
            Uncreate(vector1),
            Uncreate(dot2),
            Uncreate(vector2),
            Uncreate(dot3),
            Uncreate(vector3)
            )
        self.wait()


class CircleRectangle(GraphScene):

    CONFIG = {
        "y_axis_height": 11,
        "x_axis_width": 11,
        "graph_origin" : np.array((0,0,0)),
        "x_axis_label": None,
        "y_axis_label": None,
        "axes_color": BLUE,
    }

    def construct(self):

        grid = createGrid(self,-10, 11, -5, 6)
        self.setup_axes()

        mounting = MountingData.CR()

        #Dibujar los electrodos

        leftCenter = (mounting.electrodes[0][0][0], mounting.electrodes[0][0][1], 0)
        leftRadius = mounting.electrodes[0][1]
        
        leftElectrode = Circle(radius = leftRadius, color = RED).set_fill(RED,0.4)
        leftElectrode.move_to(leftCenter)

        self.play(DrawBorderThenFill(leftElectrode))
        
        rightCorners = mounting.electrodes[1]
        rightVertices = []

        for x,y in rightCorners:
            rightVertices.append((x,y,0))

        rightElectrode = Polygon(*rightVertices, color = BLUE).set_fill(BLUE,0.4)
        self.play(DrawBorderThenFill(rightElectrode))

        #Hacer las lineas equipotenciales

        self.createEquiLines(mounting.equiLines)
        self.createField()

        self.wait(4)
        
    def createDot(self, x, y, color = WHITE):
        return createDot(self, x, y, color)
    
    def connectDots(self, dot1, dot2, color = WHITE):
        return connectDots(self, dot1, dot2, color)
    
    def createEquiLines(self, equiLinesData):

        dots = {}
        equipotentialLines = {}
        sortedVoltages = sorted(list(equiLinesData))
        
        equipotentialLines = {v: equiLinesData[v] for v in sortedVoltages}

        for voltage in equipotentialLines:
            dotPos = equipotentialLines[voltage]
            voltageColor = COLOR_GRADIENT_2[voltage + 4]
            dotIndex = 0
            for x,y in dotPos:
                dots[dotIndex] = self.createDot(x,y, voltageColor)
                dotIndex += 1
            
            dotList = [dots[n] for n in dots]

            dotList.sort(key=lambda x: x.get_center()[1])

            tempX = dotList[2].get_center()[0]
            
            for dot1, dot2 in zip(dotList[:-1], dotList[1:]):
                self.connectDots(dot1, dot2, voltageColor)

            h = (5*54/9)+tempX*5
            
            voltCircle = Circle(radius = 1.2*h).set_fill(voltageColor,0.1).set_stroke(color = voltageColor, width = 10)
            voltCircle.move_to((-6-h,0,0))
            self.play(DrawBorderThenFill(voltCircle))
    
    def createField(self):

        graph1 = self.get_graph(lambda x: math.log(x + 8) + 1, WHITE, -6.586, 6)
        self.play(ShowCreation(graph1))

        graph2 = Line((-6,0,0), (6,0,0))
        self.play(ShowCreation(graph2))

        graph3 = self.get_graph(lambda x: (math.log(x + 8) + 1)*-1, WHITE, -6.586, 6)
        self.play(ShowCreation(graph3))
  
        alpha = ValueTracker(0)
        
        vector1 = get_tangent_vector(alpha.get_value(),graph1,scale=1)
        dot1 = Dot()
        dot1.add_updater(lambda m: m.move_to(vector1.get_start()))

        vector2 = get_tangent_vector(alpha.get_value(),graph2,scale=1)
        dot2 = Dot()
        dot2.add_updater(lambda m: m.move_to(vector2.get_start()))

        vector3 = get_tangent_vector(alpha.get_value(),graph3,scale=1)
        dot3 = Dot()
        dot3.add_updater(lambda m: m.move_to(vector3.get_start()))

        self.play(
            GrowFromCenter(dot1),
            GrowArrow(vector1),
            GrowFromCenter(dot2),
            GrowArrow(vector2),
            GrowFromCenter(dot3),
            GrowArrow(vector3)
            )

        text = TexMobject(r"\vec{E}")
        text.next_to(dot1, UL, buff=SMALL_BUFF)
        self.play(ShowCreation(text))

        def updateFunc(text):
            text.next_to(dot1, UL, buff=SMALL_BUFF)
        
        text.add_updater(updateFunc)

        vector1.add_updater(
            lambda m: m.become(
                    get_tangent_vector(alpha.get_value()%1,graph1,scale=1)        
                )
                
            )
        
        vector2.add_updater(
            lambda m: m.become(
                    get_tangent_vector(alpha.get_value()%1,graph2,scale=1)        
                )
            )
        
        vector3.add_updater(
            lambda m: m.become(
                    get_tangent_vector(alpha.get_value()%1,graph3,scale=1)        
                )
            )
        
        self.add(vector1,dot1,vector2,dot2,vector3,dot3)
        self.play(alpha.increment_value, 0.99, run_time=5, rate_func=smooth)

        text.remove_updater(updateFunc)

        self.wait(1)

        self.play(
            Uncreate(dot1),
            Uncreate(vector1),
            Uncreate(dot2),
            Uncreate(vector2),
            Uncreate(dot3),
            Uncreate(vector3)
            )
        self.wait()

class CircleCircle(GraphScene):

    CONFIG = {
        "y_axis_height": 11,
        "x_axis_width": 11,
        "graph_origin" : np.array((0,0,0)),
        "x_axis_label": None,
        "y_axis_label": None,
        "axes_color": BLUE,
    }

    def construct(self):

        grid = createGrid(self,-10, 11, -5, 6)
        self.setup_axes()

        mounting = MountingData.CC()

        #Dibujar los electrodos

        leftCenter = (mounting.electrodes[0][0][0], mounting.electrodes[0][0][1], 0)
        leftRadius = mounting.electrodes[0][1]
        
        leftElectrode = Circle(radius = leftRadius, color = RED).set_fill(RED,0.4)
        leftElectrode.move_to(leftCenter)

        self.play(DrawBorderThenFill(leftElectrode))
        
        rightCenter = (mounting.electrodes[1][0][0], mounting.electrodes[1][0][1], 0)
        rightRadius = mounting.electrodes[1][1]

        rightElectrode = Circle(radius = rightRadius, color = BLUE).set_fill(BLUE,0.4)
        rightElectrode.move_to(rightCenter)
        self.play(DrawBorderThenFill(rightElectrode))

        #Hacer las lineas equipotenciales

        self.createEquiLines(mounting.equiLines)
        self.createField()

        self.wait(4)
        
    def createDot(self, x, y, color = WHITE):
        return createDot(self, x, y, color)
    
    def connectDots(self, dot1, dot2, color = WHITE):
        return connectDots(self, dot1, dot2, color)
    
    def createEquiLines(self, equiLinesData):

        dots = {}
        equipotentialLines = {}
        sortedVoltages = sorted(list(equiLinesData))
        
        equipotentialLines = {v: equiLinesData[v] for v in sortedVoltages}

        for voltage in equipotentialLines:
            dotPos = equipotentialLines[voltage]
            voltageColor = COLOR_GRADIENT_2[voltage + 4]
            dotIndex = 0
            for x,y in dotPos:
                dots[dotIndex] = self.createDot(x,y, voltageColor)
                dotIndex += 1
            
            dotList = [dots[n] for n in dots]

            dotList.sort(key=lambda x: x.get_center()[1])

            tempX = dotList[2].get_center()[0]
            
            for dot1, dot2 in zip(dotList[:-1], dotList[1:]):
                self.connectDots(dot1, dot2, voltageColor)

            if tempX < -0.2:
                h = 12 + 2*tempX
                voltCircle = Circle(radius = 2.5*h).set_fill(voltageColor,0.1).set_stroke(color = voltageColor, width = 10)
                voltCircle.move_to((-6-2*h,0,0))
            
            elif tempX > 0.2:
                h = 12 - 2*tempX
                voltCircle = Circle(radius = 2.5*h).set_fill(voltageColor,0.1).set_stroke(color = voltageColor, width = 10)
                voltCircle.move_to((6+2*h,0,0))
            
            else:
                voltCircle = Rectangle(height = FRAME_HEIGHT+1, width = (11+tempX)*2).set_fill(voltageColor,0.1).set_stroke(color = voltageColor, width = 10)
                voltCircle.move_to((-11,0,0))

            self.play(DrawBorderThenFill(voltCircle))
    
    def createField(self):

        graph1 = self.get_graph(lambda x: -0.066*x**2 + 4.2, WHITE, -6.545, 6.545)
        self.play(ShowCreation(graph1))

        graph2 = Line((-6,0,0), (6,0,0))
        self.play(ShowCreation(graph2))

        graph3 = self.get_graph(lambda x: 0.066*x**2 - 4.2, WHITE, -6.545, 6.545)
        self.play(ShowCreation(graph3))
  
        alpha = ValueTracker(0)
        
        vector1 = get_tangent_vector(alpha.get_value(),graph1,scale=1)
        dot1 = Dot()
        dot1.add_updater(lambda m: m.move_to(vector1.get_start()))

        vector2 = get_tangent_vector(alpha.get_value(),graph2,scale=1)
        dot2 = Dot()
        dot2.add_updater(lambda m: m.move_to(vector2.get_start()))

        vector3 = get_tangent_vector(alpha.get_value(),graph3,scale=1)
        dot3 = Dot()
        dot3.add_updater(lambda m: m.move_to(vector3.get_start()))

        self.play(
            GrowFromCenter(dot1),
            GrowArrow(vector1),
            GrowFromCenter(dot2),
            GrowArrow(vector2),
            GrowFromCenter(dot3),
            GrowArrow(vector3)
            )

        text = TexMobject(r"\vec{E}")
        text.next_to(dot1, UL, buff=SMALL_BUFF)
        self.play(ShowCreation(text))

        def updateFunc(text):
            text.next_to(dot1, UL, buff=SMALL_BUFF)
        
        text.add_updater(updateFunc)

        vector1.add_updater(
            lambda m: m.become(
                    get_tangent_vector(alpha.get_value()%1,graph1,scale=1)        
                )
                
            )
        
        vector2.add_updater(
            lambda m: m.become(
                    get_tangent_vector(alpha.get_value()%1,graph2,scale=1)        
                )
            )
        
        vector3.add_updater(
            lambda m: m.become(
                    get_tangent_vector(alpha.get_value()%1,graph3,scale=1)        
                )
            )
        
        self.add(vector1,dot1,vector2,dot2,vector3,dot3)
        self.play(alpha.increment_value, 0.99, run_time=5, rate_func=smooth)

        text.remove_updater(updateFunc)

        self.wait(1)

        self.play(
            Uncreate(dot1),
            Uncreate(vector1),
            Uncreate(dot2),
            Uncreate(vector2),
            Uncreate(dot3),
            Uncreate(vector3)
            )
        self.wait()

# class Test():
#     def construct():
#         pass

def get_tangent_vector(proportion, curve, dx=0.001, scale=1, color = WHITE):
        coord_i = curve.point_from_proportion(proportion)
        coord_f = curve.point_from_proportion(proportion + dx)
        reference_line = Line(coord_i,coord_f)
        unit_vector = reference_line.get_unit_vector() * scale
        vector = Arrow(coord_i, coord_i + unit_vector, buff=0, color = color)
        return vector

def main():
    
    os.system("manim Manim.py CircleCircle -p")

if __name__ == "__main__":
    main()    
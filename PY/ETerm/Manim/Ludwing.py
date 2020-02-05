from manimlib.imports import *
import os
import numpy as np
import sys
import openpyxl
import math

sys.path.insert(1, "F:/Downloads/Carpetas/Programs/Programming/PY/ETerm/Manim")
from ManimUtils import *

#pylint: disable=undefined-variable

class L(GraphScene):

    CONFIG = {
        "y_axis_height": 11,
        "x_axis_width": 11,
        "graph_origin" : np.array((0,0,0)),
        "x_axis_label": None,
        "y_axis_label": None,
        "axes_color": BLUE,
    }

    def construct(self):

        text = TextMobject(r"Hola L, hoy le enseñare como no perder calculo I")
        self.play(Write(text))
        self.wait(3)
        self.play(Uncreate(text))

        



        # grid = createGrid(self,-10, 11, -5, 6)
        # self.setup_axes()
        # self.createField()
    
    def createField(self):

        graph1 = self.get_graph(lambda x: x*(4-x**2)**(1/2), WHITE, -2, 2)
        self.play(ShowCreation(graph1))

        graph2 = self.get_graph(lambda x: x*(4-x**2)**(1/2), RED, -2, -(2)**(1/2))
        self.play(ShowCreation(graph2))

        graph3 = self.get_graph(lambda x: x*(4-x**2)**(1/2), BLUE, -(2)**(1/2), (2)**(1/2))
        self.play(ShowCreation(graph3))

        graph4 = self.get_graph(lambda x: x*(4-x**2)**(1/2), RED, (2)**(1/2), 2)
        self.play(ShowCreation(graph4))

        init_dot = createDot(self, -2, 0, GRAY)
        crit1_dot = createDot(self, -(2)**(1/2), -2, GRAY)
        crit1_dot = createDot(self, (2)**(1/2), 2, GRAY)
        final_dot = createDot(self, 2, 0, GRAY)

        alpha = ValueTracker(0)
        
        vector1 = get_tangent_vector(alpha.get_value(),graph1,scale=1)
        dot1 = Dot()
        dot1.add_updater(lambda m: m.move_to(vector1.get_start()))

        self.play(
            GrowFromCenter(dot1),
            GrowArrow(vector1),
            )

        text = TexMobject(r"\vec{P}")
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
        
        self.add(vector1,dot1)
        self.play(alpha.increment_value, 0.999, run_time=5, rate_func=linear)

        text.remove_updater(updateFunc)

        self.wait(1)

        self.play(
            Uncreate(dot1),
            Uncreate(vector1),
            )
        self.wait()
        
class FieldWithAxes(Scene):
    CONFIG = {
    "plane_kwargs" : {
    "color" : RED_B
    },
    "point_charge_loc" : 0.5*RIGHT-1.5*UP,
    }

    plane_kwargs = {"color" : RED_B}

    def construct(self):
        plane = NumberPlane(**self.plane_kwargs)
        plane.add(plane.get_axis_labels())
        self.add(plane)
        
        field = VGroup(*[self.calc_field(x*RIGHT+y*UP)
        for x in np.arange(-9,9,1)
        for y in np.arange(-5,5,1)
        ])
        
        self.play(ShowCreation(field))
    
    def calc_field(self,point):
        x,y = point[:2]
        temp = 0.5*RIGHT-1.5*UP
        Rx,Ry = temp[:2]
        r = math.sqrt((x-Rx)**2 + (y-Ry)**2)
        efield = (point - temp)/r**3


def get_tangent_vector(proportion, curve, dx=0.001, scale=1, color = WHITE):
    coord_i = curve.point_from_proportion(proportion)
    coord_f = curve.point_from_proportion(proportion + dx)
    reference_line = Line(coord_i,coord_f)
    unit_vector = reference_line.get_unit_vector() * scale
    vector = Arrow(coord_i, coord_i + unit_vector, buff=0, color = color)
    return vector

def main():
    os.system("manim Ludwing.py FieldWithAxes -pl")

if __name__ == "__main__":
    main()    
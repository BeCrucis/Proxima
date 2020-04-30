from manimlib.mobject.types.vectorized_mobject import VMobject
from manimlib.mobject.geometry import Dot, Line, Arrow
from manimlib.animation.growing import *
from manimlib.constants import *

import numpy as np

def get_tangent_vector(proportion, curve: VMobject, dx=0.001, scale=1, color = COLOR_MAP['WHITE']):
    coord_i = curve.point_from_proportion(proportion)
    coord_f = curve.point_from_proportion(proportion + dx)
    reference_line = Line(coord_i,coord_f)
    unit_vector = reference_line.get_unit_vector() * scale
    vector = Arrow(coord_i, coord_i + unit_vector, buff=0, color = color)
    return vector

def connectDots(scene, dot1, dot2, color = COLOR_MAP['WHITE']):
    line = Line(dot1.get_center(), dot2.get_center(), color = color)
    scene.play(GrowFromPoint(line, dot1.get_center()), run_time = .3)
    return line
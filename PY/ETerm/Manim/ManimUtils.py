from manimlib.imports import *
import numpy as np

# pragma pylint: disable=no-member
#pylint: disable=undefined-variable

class Grid(VMobject):
    CONFIG = {
        "height": 6.0,
        "width": 6.0,
    }

    def __init__(self, rows, columns, **kwargs):
        digest_config(self, kwargs, locals())
        VMobject.__init__(self, **kwargs)

    def generate_points(self):
        x_step = self.width / self.columns
        y_step = self.height / self.rows

        for x in np.arange(0, self.width + x_step, x_step):
            self.add(Line(
                [x - self.width / 2., -self.height / 2., 0],# pylint: disable=maybe-no-member
                [x - self.width / 2., self.height / 2., 0],
            ))
        for y in np.arange(0, self.height + y_step, y_step):
            self.add(Line(
                [-self.width / 2., y - self.height / 2., 0],
                [self.width / 2., y - self.height / 2., 0]
            ))


class ScreenGrid(VGroup):
    CONFIG = {
        "rows": 8,
        "columns": 14,
        "height": FRAME_Y_RADIUS * 2,
        "width": 14,
        "grid_stroke": 0.5,
        "grid_color": WHITE,
        "axis_color": RED, #pylint: disable=undefined-variable
        "axis_stroke": 2,
        "show_points": False,
        "point_radius": 0,
        "labels_scale": 0.5,
        "labels_buff": 0,
        "number_decimals": 2
    }

    def __init__(self, **kwargs):
        VGroup.__init__(self, **kwargs)
        rows = self.rows
        columns = self.columns
        grilla = Grid(width=self.width, height=self.height, rows=rows, columns=columns)
        grilla.set_stroke(self.grid_color, self.grid_stroke)

        vector_ii = ORIGIN + np.array((- self.width / 2, - self.height / 2, 0))
        vector_si = ORIGIN + np.array((- self.width / 2, self.height / 2, 0))
        vector_sd = ORIGIN + np.array((self.width / 2, self.height / 2, 0))

        ejes_x = Line(LEFT * self.width / 2, RIGHT * self.width / 2)
        ejes_y = Line(DOWN * self.height / 2, UP * self.height / 2)

        ejes = VGroup(ejes_x, ejes_y).set_stroke(self.axis_color, self.axis_stroke)

        divisiones_x = self.width / columns
        divisiones_y = self.height / rows

        direcciones_buff_x = [UP, DOWN]
        direcciones_buff_y = [RIGHT, LEFT]
        dd_buff = [direcciones_buff_x, direcciones_buff_y]
        vectores_inicio_x = [vector_ii, vector_si]
        vectores_inicio_y = [vector_si, vector_sd]
        vectores_inicio = [vectores_inicio_x, vectores_inicio_y]
        divisiones = [divisiones_x, divisiones_y]
        orientaciones = [RIGHT, DOWN]
        puntos = VGroup()
        leyendas = VGroup()
        set_changes = zip([columns, rows], divisiones, orientaciones, [0, 1], vectores_inicio, dd_buff)
        for tipo, division, orientacion, coordenada, vi_c, d_buff in set_changes:
            for i in range(1, tipo):
                for v_i, direcciones_buff in zip(vi_c, d_buff):
                    ubicacion = v_i + orientacion * division * i
                    punto = Dot(ubicacion, radius=self.point_radius)
                    coord = round(punto.get_center()[coordenada], self.number_decimals)
                    leyenda = TextMobject("%s" % coord).scale(self.labels_scale)
                    leyenda.next_to(punto, direcciones_buff, buff=self.labels_buff)
                    puntos.add(punto)
                    leyendas.add(leyenda)

        self.add(grilla, ejes, leyendas)
        if self.show_points:
            self.add(puntos)

def createDot(obj, x, y, color = WHITE):
    dot = Dot(np.array([x, y, 0]), color = color)
    obj.play(GrowFromCenter(dot), run_time = .2)
    return dot

def connectDots(obj, dot1, dot2, color = WHITE):
    line = Line(dot1.get_center(), dot2.get_center(), color = color)
    obj.play(GrowFromPoint(line, dot1.get_center()), run_time = .3)
    return line

def createGrid(obj, x_min = 0, x_max = 0, y_min = 0, y_max = 0):
    grid = NumberPlane().add_coordinates(list(range(x_min,x_max)), list(range(y_min,y_max)))
    obj.play(ShowIncreasingSubsets(grid))
    return grid

class TangentVector(Scene):
    def construct(self):
        figure = Ellipse(color=RED).scale(2)
        dot = Dot()
        alpha = ValueTracker(0)
        vector = self.get_tangent_vector(alpha.get_value(),figure,scale=2)
        dot.add_updater(lambda m: m.move_to(vector.get_start()))
        self.play(
            ShowCreation(figure),
            GrowFromCenter(dot),
            GrowArrow(vector)
            )
        vector.add_updater(
            lambda m: m.become(
                    self.get_tangent_vector(alpha.get_value()%1,figure,scale=2)
                )
            )
        self.add(vector,dot)
        self.play(alpha.increment_value, 2, run_time=8, rate_func=linear)
        self.wait()

    def get_tangent_vector(self, proportion, curve, dx=0.001, scale=1):
        coord_i = curve.point_from_proportion(proportion)
        coord_f = curve.point_from_proportion(proportion + dx)
        reference_line = Line(coord_i,coord_f)
        unit_vector = reference_line.get_unit_vector() * scale
        vector = Arrow(coord_i, coord_i + unit_vector, buff=0)
        return vector
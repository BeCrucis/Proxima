from manimlib.imports import *
from manimlib.utils.vmobject_manip import *
import manimlib

class Example(ThreeDScene):
    def construct(self):
        axes=ThreeDAxes()
        vector=Vector(direction=0.5*(UP+RIGHT+OUT), shape_in_3d=True)
        self.add(axes)
        self.add(vector)
        self.move_camera(phi=60*DEGREES,theta=-45*DEGREES,run_time=6)
        self.begin_ambient_camera_rotation(rate=0.2)
        self.wait(5)
        self.stop_ambient_camera_rotation()

class Example2(GraphScene):

    def construct(self):
        graph = Axes()

        vec = Vector(direction=np.array([5,6,0]))

        self.play(ShowCreation(graph), run_time = 2)
        self.play(ShowCreation(vec), run_time = 1)

        self.wait(1)

        dot1 = self.createDot2(0, 0, False)
        dot2 = self.createDot2(5, 5)

        line = connectDots(self, dot1, dot2, animate=False)

        self.wait(5)

    def createDot2(self, x, y, animation=True):
        return createDot(self, x, y, animate=animation)
    
   


def main():
    os.system(r"manim 3DVec.py Example Example2 -pm")

if __name__ == "__main__":
    main()    
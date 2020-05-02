from manimlib.imports import *
from manimlib.utils.vmobject_manip import *

# Metodos manimlib vmobject_manip

class Example(GraphScene):

    def construct(self):
        graph = Axes()

        vec = Vector(direction=np.array([4,1,0]))

        self.play(ShowCreation(graph), run_time = 2)
        self.play(ShowCreation(vec), run_time = 1)

        self.wait(1)

        dot1 = createDot(self, 0, 0, animate=False)
        dot2 = createDot(self, 3, 2, animate=True)

        line = connectDots(self, dot1, dot2, animate=True)

        self.wait(5)
    

def main():
    os.system(r"manim Util_Examples.py Example -pl")

if __name__ == "__main__":
    main()    
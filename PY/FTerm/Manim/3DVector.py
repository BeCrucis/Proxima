from manimlib.imports import *

# Vector en 3D

class Example(ThreeDScene):

    def construct(self):
        axes=ThreeDAxes()
        vector=Vector(direction=1*(UP+RIGHT+OUT), shape_in_3d=True, color=COLOR_MAP['RED_C'])

        self.add(axes)
        self.add(vector)
        
        self.move_camera(phi=60*DEGREES,theta=-45*DEGREES,run_time=6)
        self.begin_ambient_camera_rotation(rate=0.2)
        self.wait(5)
        self.stop_ambient_camera_rotation()

class Example2(SpecialThreeDScene):

    CONFIG = {
        "add_axes_labels": True,
        "camera_config":{
            "phi" : 0*DEGREES,
            "theta" : -90*DEGREES,
        },
        "three_d_axes_config": {
            "num_axis_pieces": 200,
            "shape_in_3d": True,
        },
    }
    
    def construct(self):
        axes = self.get_axes() #return [axes, labels]
        axes[1][2].set_opacity(0)
        f = SolidTrace("x", x_min = 0, x_max = 3)
        solid = f.get_solid()


        self.add(axes)
        self.wait()
        self.play(ShowCreation(f), run_time = 3)
        self.play(Write(f.label))
        self.wait()
        self.move_camera(phi = 70*DEGREES, theta = -50*DEGREES,added_anims= [FadeOut(f.label)], run_time = 3)
        self.wait()
        self.add(solid)
        self.play(f.tracker.increment_value, TAU, run_time = 5) #this allows draw the solid
        self.wait()

def main():
    os.system(r"manim 3DVector.py Example -pl")

if __name__ == "__main__":
    main()    
from manimlib.imports import *
import os
import numpy as np
import sys
import openpyxl

#pylint: disable=undefined-variable
#pylint: disable=no-member

class Plot2(GraphScene):
    CONFIG = {
        "y_max" : 5,
        "y_min" : -5,
        "x_max" : 7,
        "x_min" : -7,
        "y_tick_frequency" : 1,
        "axes_color" : BLUE,
        "x_axis_label" : "$t$",
        "y_axis_label" : "$f(t)$",
        "graph_origin" : np.array((0,0,0)),
        "x_axis_width": 14,
        "y_axis_height" : 8
    }
    def construct(self):
        self.setup_axes()
        graph = self.get_graph(lambda x : x**2, color = GREEN)
        self.play(
        	ShowCreation(graph),
            run_time = 2
        )
        self.wait()
        
    def setup_axes(self):
        # Add this line
        GraphScene.setup_axes(self) 
        # Parametters of labels
        #   For x
        init_label_x = -7
        end_label_x = 7
        step_x = 1
        #   For y
        init_label_y = -5
        end_label_y = 5
        step_y = 1
        # Position of labels
        #   For x
        self.x_axis.label_direction = DOWN #DOWN is default
        #   For y
        self.y_axis.label_direction = LEFT
        # Add labels to graph
        #   For x
        self.x_axis.add_numbers(*range(
                                        init_label_x,
                                        end_label_x+step_x,
                                        step_x
                                    ))
        #   For y
        self.y_axis.add_numbers(*range(
                                        init_label_y,
                                        end_label_y+step_y,
                                        step_y
                                    ))
        #   Add Animation
        self.play(
            ShowCreation(self.x_axis),
            ShowCreation(self.y_axis)
        )

        """for n in range(-5, 0):
            dots[n] = self.createDot(-1, n)
            center = dots[n].get_center()
            print (F"{center}")
            print (center[1])"""
import os
import math

maxArea = 0

for x in range(13):

    for angle in range(91):

        rad = math.radians(angle)

        area = (x * math.sin(rad)) * (24 - 2*x + x*math.cos(rad))

        if area > maxArea:
            print(F"Area {area} maxima obtenida con x = {x} y angulo = {angle} grados")
            maxArea = area




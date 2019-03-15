import os
from imutils import contours
from skimage import measure
import numpy as np
import argparse
import imutils
import cv2

print("Bienvenido al reconocedor de imagenes GACRUCIS", end="\n\n")

img = cv2.imread("EJ1.png")

output = img.copy()

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# detect circles in the image
circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, 1, 10, minRadius=15, maxRadius=30)
 
# ensure at least some circles were found
if circles is not None:
    
	# convert the (x, y) coordinates and radius of the circles to integers
    circles = np.round(circles[0, :]).astype("int")
    coords = []

	# loop over the (x, y) coordinates and radius of the circles
    for (x, y, r) in circles:
		# draw the circle in the output image, then draw a rectangle
		# corresponding to the center of the circle
        cv2.circle(output, (x, y), r, (0, 0, 255), 4)
        coords.append((x,y))
        cv2.rectangle(output, (x - 5, y - 5), (x + 5, y + 5), (0, 128, 255), -1)
	# show the output image

    print(circles[0, :])
    cv2.imshow("output", np.hstack([img, output]))
    cv2.waitKey(0)

    print("Como segunda parte, alineare la imagen . . .")

    coords = np.array(coords)
    x,y,w,h = cv2.boundingRect(coords)
    cv2.rectangle(output,(x,y),(x+w,y+h),(0,255,0),2)

    cv2.imshow("output2", np.hstack([img, output]))
    cv2.waitKey(0)
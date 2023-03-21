#!/usr/bin/env python3

import cv2
import numpy as np

img = cv2.imread("images/lena.jpg")
b, g, r = cv2.split(img)

cv2.imshow("B", b)
cv2.imshow("G", g)
cv2.imshow("R", r)
cv2.waitKey()
cv2.destroyAllWindows()

bgr = cv2.merge([b, g, r])
rgb = cv2.merge([r, g, b])
cv2.imshow("lena", img)
cv2.imshow("bgr", bgr)
cv2.imshow("rgb", rgb)
cv2.waitKey()
cv2.destroyAllWindows()

#!/usr/bin/env python3

import cv2
import numpy as np

lena = cv2.imread("images/lena.jpg", cv2.IMREAD_UNCHANGED)
dollar = cv2.imread("images/dollar.jpeg", cv2.IMREAD_UNCHANGED)
print(lena.shape)
print(dollar.shape)

cv2.imshow("lena", lena)
cv2.imshow("dollar", dollar)

face = lena[130:240, 140:220]
dollar[40:150, 80:160] = face

cv2.imshow("result", dollar)
cv2.waitKey()
cv2.destroyAllWindows()

#!/usr/bin/env python3

import cv2
import numpy as np

a = cv2.imread('images/1.jpg')
b = cv2.imread('images/2.jpg')

res = cv2.addWeighted(a, 0.5, b, 0.5, 0)
cv2.imshow('a', a)
cv2.imshow('b', b)
cv2.imshow('res', res)
cv2.waitKey(0)
cv2.destroyAllWindows()

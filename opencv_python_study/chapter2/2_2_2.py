#!/usr/bin/env python3

import cv2
import numpy as np

img = cv2.imread('images/lena.jpg', 0)
print(img)

cv2.imshow('image', img)
cv2.waitKey(0)

for i in range(10, 100):
  for j in range(80,100):
    img[i, j]=255

cv2.imshow('changed', img)
cv2.waitKey(0)
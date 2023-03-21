#!/usr/bin/env python3

import cv2
import numpy as np

img = np.zeros((512, 512, 3), dtype = np.uint8)
for i in range(50, 100):
    for j in range(50, 100):
        img.itemset((i, j, 0), 255)

cv2.imshow('1', img)
cv2.waitKey(0)

roi = img[50: 100, 50:100]
img[400: 450, 400:450] = roi
cv2.imshow('2', img)
cv2.waitKey(0)

cv2.destroyAllWindows()
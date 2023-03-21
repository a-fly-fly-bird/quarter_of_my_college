#!/usr/bin/env python3

import cv2
import numpy as np

img = np.random.randint(0, 255, (1000, 800), np.uint8)
print('像素点(3,2)的值是：', img.item(3,2))
img.itemset((3,2), 255)
print('像素点(3,2)的值是：', img.item(3,2))

cv2.imshow("window name", img)
cv2.waitKey(0)
cv2.destroyWindow("window name")


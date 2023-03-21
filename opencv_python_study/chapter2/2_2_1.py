#!/usr/bin/env python3

import cv2
import numpy as np

img = np.zeros((500, 500), dtype=np.uint8)
print(img)

cv2.namedWindow('img')
cv2.imshow('img', img)
cv2.waitKey(0)
cv2.destroyAllWindows

img[10:20, 10:20] = 255
print('修改后的img：', img)

cv2.namedWindow('img-again')
cv2.imshow('img-again', img)
cv2.waitKey(0)
cv2.destroyAllWindows

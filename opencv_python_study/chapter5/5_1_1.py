#!/usr/bin/env python3

import cv2
import numpy as np

# 注意，缩放不是裁切crop(), interpolation代表插值方式，有双线性插值，三次样条插值等。

img = cv2.imread("images/3.jpg")

rows, cols = img.shape[:2]

size = (int(cols*0.9), int(rows*0.5))

rst = cv2.resize(img, size)
print("img.shape=", img.shape)
print("rst.shape=", rst.shape)

cv2.imshow('win1', rst)
cv2.waitKey(0)

bigger = cv2.resize(img, (int(cols*2), int(rows*2)), interpolation=cv2.INTER_CUBIC)
cv2.imwrite('images/3_bigger.jpg', bigger)
cv2.imshow('win2', bigger)

cv2.waitKey(0)
cv2.destroyAllWindows()

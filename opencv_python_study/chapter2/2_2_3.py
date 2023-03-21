import cv2
import numpy as np

img = np.zeros((300, 300, 3), dtype=np.uint8)
img[:,0:100,0]=255
img[:,100:200,1]=255
img[:,200:300,2]=255
cv2.namedWindow('stripe')
cv2.imshow('stripe', img)
cv2.waitKey(0)
cv2.destroyAllWindows()

print(img[1][1])
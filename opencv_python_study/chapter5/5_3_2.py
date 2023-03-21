import cv2
img = cv2.imread("images/1.jpg")
height, width = img.shape[:2]

# 利用函数cv2.getRotationMatrix2D()可以直接生成要使用的转换矩阵M。例如，想要以图像中心为圆点，逆时针旋转45°，并将目标图像缩小为原始图像的0.6倍。
M = cv2.getRotationMatrix2D((width/2, height/2), 45, 0.6)
rotate = cv2.warpAffine(img, M, (width, height))
cv2.imshow("original", img)
cv2.imshow("rotation", rotate)
cv2.waitKey()
cv2.destroyAllWindows()

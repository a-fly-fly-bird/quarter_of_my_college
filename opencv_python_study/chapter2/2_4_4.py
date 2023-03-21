import cv2

# 这一部分很简单，就是 numpy 的内容
gray = cv2.imread("images/lena.jpg", 0)
color = cv2.imread("images/dollar.jpeg")
print("图像gray属性：")
print("gray.shape=", gray.shape)
print("gray.size=", gray.size)
print("gray.dtype=", gray.dtype)
print("图像color属性：")
print("color.shape=", color.shape)
print("color.size=", color.size)
print("color.dtype=", color.dtype)

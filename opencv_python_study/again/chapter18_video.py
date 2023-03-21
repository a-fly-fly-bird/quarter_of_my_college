import numpy as np
import cv2
cap = cv2.VideoCapture('/Users/tanyong/Movies/The Friends/Season 8/老友记 - S08E13 - 钱德勒的泡泡浴.mkv')
while(cap.isOpened()):
    ret, frame = cap.read()
    cv2.imshow('frame', frame)
    c = cv2.waitKey(25)
    if c==27:   #ESC键
      break
cap.release()
cv2.destroyAllWindows()

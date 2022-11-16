import numpy as np
import cv2

# Load an color image in grayscale
def main():
  img = cv2.imread('./iron/iron1.png',0)
  cv2.imshow('image',img)
  cv2.waitKey(0)
  cv2.destroyAllWindows()

main()

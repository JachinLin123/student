import cv2
 
# 第一种
# image_path = r"E:\Python\sensitiveword\1.jpg"
# image_read = cv2.imread(image_path)
# image_gray = cv2.cvtColor(image_read, cv2.COLOR_RGB2GRAY)
# image_gray = cv2.medianBlur(image_gray,5)
# image_edge = cv2.adaptiveThreshold(image_gray, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, blockSize=3, C=2)
# cv2.imwrite("3.jpg",image_edge)
 
# 第二种
image_path = r"C:/Users/admin/Pictures/my.jpg"
image_read = cv2.imread(image_path)
image_gray = cv2.cvtColor(image_read, cv2.COLOR_RGB2GRAY)
image_blur = cv2.GaussianBlur(image_gray, ksize=(21, 21), sigmaX=0, sigmaY=0)
image = cv2.divide(image_gray, image_blur, scale=255)
cv2.imwrite("8.jpg", image)
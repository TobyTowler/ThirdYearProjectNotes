import cv2
from matplotlib import pyplot as plt
import turtle
import numpy as np

# bgr = cv2.imread("map1.png")
# gray = cv2.cvtColor(bgr, cv2.COLOR_BGR2GRAY)
# _, roi = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY)
# cv2.imwrite("/home/dhanushka/stack/roi.png", roi)
# cont = cv2.findContours(roi, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
# output = np.zeros(gray.shape, dtype=np.uint8)
# cv2.drawContours(output, cont[0], -1, (255, 255, 255))
#
# # removing boundary
# boundary = 255 * np.ones(gray.shape, dtype=np.uint8)
# boundary[1: boundary.shape[0] - 1, 1: boundary.shape[1] - 1] = 0
#
# toremove = output & boundary
# output = output ^ toremove


import cv2
import matplotlib.pyplot as plt

# Load the image in grayscale
image = cv2.imread("map1.png", 0)

# Apply Gaussian Blur to reduce noise
blurred = cv2.GaussianBlur(image, (5, 5), 0)

# Apply Canny Edge Detection
edges = cv2.Canny(blurred, threshold1=50, threshold2=150)

# Display the result
plt.imshow(edges, cmap="gray")
plt.axis("off")
plt.show()


# Load the image in grayscale
image = cv2.imread("map1.png", 0)

# Apply Gaussian Blur
blurred = cv2.GaussianBlur(image, (7, 7), 0)

# Apply Adaptive Thresholding
outline = cv2.adaptiveThreshold(
    blurred,
    maxValue=255,
    adaptiveMethod=cv2.ADAPTIVE_THRESH_GAUSSIAN_C,
    thresholdType=cv2.THRESH_BINARY,
    blockSize=11,
    C=2,
)

# Display the result
plt.imshow(outline, cmap="gray")
plt.axis("off")
plt.show()


# Load the image in grayscale
image = cv2.imread("map1.png", 0)

# Apply Gaussian Blur
blurred = cv2.GaussianBlur(image, (5, 5), 0)

# Apply Binary Thresholding
_, binary = cv2.threshold(blurred, 127, 255, cv2.THRESH_BINARY)

# Find contours
contours, _ = cv2.findContours(
    binary, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

# Draw contours on a blank canvas
contour_image = cv2.cvtColor(image, cv2.COLOR_GRAY2BGR)
cv2.drawContours(contour_image, contours, -1, (0, 255, 0), 2)  # Green contours

# Display the result
plt.imshow(cv2.cvtColor(contour_image, cv2.COLOR_BGR2RGB))
plt.axis("off")
plt.show()


# Load the image in grayscale
image = cv2.imread("map1.png", 0)

# Apply Gaussian Blur
blurred = cv2.GaussianBlur(image, (5, 5), 0)

# Detect edges using Canny
edges = cv2.Canny(blurred, 50, 150)

# Find contours from edges
contours, _ = cv2.findContours(
    edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

# Draw contours on a blank canvas
contour_image = cv2.cvtColor(image, cv2.COLOR_GRAY2BGR)
cv2.drawContours(contour_image, contours, -1, (0, 255, 0), 2)  # Green contours

# Display the result
plt.imshow(cv2.cvtColor(contour_image, cv2.COLOR_BGR2RGB))
plt.axis("off")
plt.show()

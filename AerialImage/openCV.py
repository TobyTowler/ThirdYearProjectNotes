import cv2
import numpy as np

# Load the image
image = cv2.imread("./imgs/overheadGolfGreen.jpg")

# Convert to grayscale
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Apply Gaussian blur
blurred = cv2.GaussianBlur(gray, (5, 5), 0)

# Apply Canny edge detection
edges = cv2.Canny(blurred, 100, 200)

# Find contours
contours, _ = cv2.findContours(
    edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

# If you want to simplify the contour, use polygon approximation (optional)
simplified_contour = cv2.approxPolyDP(contours[0], 5, True)

# Extract points
points = simplified_contour.reshape(-1, 2)

# Show the result (Optional)
cv2.drawContours(image, [simplified_contour], -1, (0, 255, 0), 3)
cv2.imshow("Field Outline", image)
cv2.waitKey(0)
cv2.destroyAllWindows()

# Output points
print(points)

import numpy as np
import matplotlib.pyplot as plt
from skimage import io, color, feature, measure

# Load and preprocess the image
image = color.rgb2gray(io.imread("./imgs/AdobeGold.jpg")
                       )  # Convert to grayscale

# Apply Canny Edge Detection
edges = feature.canny(image, sigma=1.0)

# Find all contours
contours = measure.find_contours(edges, level=0.5)
contours1 = np.array(contours)

# Find the largest contour by length
largest_contour = max(contours, key=len)

# Plot results
plt.imshow(image, cmap="gray")
# if largest_contour is not None:
plt.plot(contours1[:, 1], contours1[:, 0], linewidth=2, color="red")
plt.title("Largest Outline")
plt.show()

# Output the largest contour points
# if largest_contour is not None:
print(f"Largest Outline has {largest_contour.shape[0]} points")
print(largest_contour[:5])  # Print first 5 points as a sample
# else:
#     print("No contours found.")

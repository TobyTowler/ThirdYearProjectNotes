import numpy as np
from skimage import io, color, feature
import matplotlib.pyplot as plt


def extract_edge_points(image_path, sigma=1, low_threshold=0.1, high_threshold=0.2):
    # Load the image
    image = io.imread(image_path)
    gray_image = color.rgb2gray(image)  # Convert to grayscale

    # Apply Canny edge detection
    edges = feature.canny(
        gray_image,
        sigma=sigma,
        low_threshold=low_threshold,
        high_threshold=high_threshold,
    )

    # Extract coordinates of the edge points
    edge_points = np.argwhere(edges)  # This returns an array of [row, col] points

    return edge_points


def display_edge_points(image_path, sigma=1, low_threshold=0.1, high_threshold=0.2):
    # Extract edge points
    edge_points = extract_edge_points(image_path, sigma, low_threshold, high_threshold)

    # Load the original image
    image = io.imread(image_path)

    # Plot the original image with the edge points overlaid
    plt.imshow(image)
    plt.scatter(
        edge_points[:, 1], edge_points[:, 0], color="red", s=1
    )  # Use scatter to plot points
    plt.title("Edge Points Overlayed on Original Image")
    plt.axis("off")
    plt.show()

    return edge_points


# Example usage
image_path = "./imgs/AdobeGold.jpg"  # Replace with your image path
sigma = 1
low_threshold = 0.1
high_threshold = 0.4

# Get and display the edge points
edge_points = display_edge_points(image_path, sigma, low_threshold, high_threshold)

# Print the extracted points (if needed)
print("Extracted Edge Points:")
np.set_printoptions(threshold=np.inf)
print(edge_points)

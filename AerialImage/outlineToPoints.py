# import numpy as np
# from skimage import io, color, feature, measure
# import matplotlib.pyplot as plt
#
#
# def extract_edge_points(image_path, sigma=1, low_threshold=0.1, high_threshold=0.4):
#     # Load the image
#     image = io.imread(image_path)
#     gray_image = color.rgb2gray(image)  # Convert to grayscale
#
#     edges = feature.canny(
#         gray_image,
#         sigma=sigma,
#         low_threshold=low_threshold,
#         high_threshold=high_threshold,
#     )
#
#     edge_points = np.argwhere(edges)
#
#     return edge_points
#     # return np.argwhere(longContours)
#
#
# def display_edge_points(image_path, sigma, low_threshold, high_threshold):
#     # Extract edge points
#     edge_points = extract_edge_points(
#         image_path, sigma, low_threshold, high_threshold)
#
#     # Load the original image
#     image = io.imread(image_path)
#
#     # Plot the original image with the edge points overlaid
#     plt.imshow(image)
#     plt.scatter(
#         edge_points[:, 1], edge_points[:, 0], color="red", s=1
#     )  # Use scatter to plot points
#     plt.title("Edge Points Overlayed on Original Image")
#     plt.axis("off")
#     plt.show()
#
#     return edge_points
#
#
# # Example usage
# image_path = "./imgs/AdobeGold.jpg"  # Replace with your image path
# sigma = 1
# low_threshold = 0.1
# high_threshold = 0.4
#
# # Get and display the edge points
# edge_points = display_edge_points(
#     image_path, sigma, low_threshold, high_threshold)
#
# # Print the extracted points (if needed)
# print("Extracted Edge Points:")
# # np.set_printoptions(threshold=np.inf)
# for i in range(0, len(edge_points)):
#     print(edge_points[i])
# print(edge_points)


import numpy as np
from skimage import io, color, feature
import matplotlib.pyplot as plt
from scipy.ndimage import label


def extract_edge_outlines(image_path, sigma=1, low_threshold=0.1, high_threshold=0.4):
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

    # Label connected edge regions
    labeled_edges, num_features = label(edges)

    # Extract edge points for each outline
    outlines = []
    for i in range(1, num_features + 1):  # Labels start from 1 (0 is background)
        outline_points = np.argwhere(labeled_edges == i)
        outlines.append(outline_points)

    newOuts = []
    for i in range(0, len(outlines)):
        if len(outlines[i]) > 25:
            newOuts.append(outlines[i])
    return outlines  # List of arrays, each representing an outline


def display_edge_outlines(image_path, sigma, low_threshold, high_threshold):
    # Extract the outlines
    outlines = extract_edge_outlines(
        image_path, sigma, low_threshold, high_threshold)

    # Load the original image
    image = io.imread(image_path)

    # Plot the original image with the outlines overlaid
    plt.imshow(image)

    # Define colors for outlines
    colors = ["red", "blue", "green", "yellow", "cyan", "magenta"]

    for i, outline in enumerate(outlines):
        plt.scatter(
            outline[:, 1],
            outline[:, 0],
            color=colors[i % len(colors)],
            s=1,
            label=f"Outline {i + 1}",
        )

    plt.title("Detected Outlines")
    plt.legend()
    plt.axis("off")
    plt.show()

    return outlines


# Example usage
image_path = "./imgs/AdobeGold.jpg"  # Replace with your image path
sigma = 1
low_threshold = 0.1
high_threshold = 0.4

# Get and display the outlines
outlines = display_edge_outlines(
    image_path, sigma, low_threshold, high_threshold)

# Print the extracted outlines
for i, outline in enumerate(outlines):
    print(f"\nOutline {i + 1} ({len(outline)} points):")
    print(outline)  # Print all points for this outline

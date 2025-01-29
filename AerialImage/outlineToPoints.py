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

#
# import numpy as np
# from skimage import io, color, feature
# import matplotlib.pyplot as plt
# from scipy.ndimage import label
#
#
# def extract_edge_outlines(image_path, sigma=1, low_threshold=0.1, high_threshold=0.4):
#     # Load the image
#     image = io.imread(image_path)
#     gray_image = color.rgb2gray(image)  # Convert to grayscale
#
#     # Apply Canny edge detection
#     edges = feature.canny(
#         gray_image,
#         sigma=sigma,
#         low_threshold=low_threshold,
#         high_threshold=high_threshold,
#     )
#
#     # Label connected edge regions
#     labeled_edges, num_features = label(edges)
#
#     # Extract edge points for each outline
#     outlines = []
#     for i in range(1, num_features + 1):  # Labels start from 1 (0 is background)
#         outline_points = np.argwhere(labeled_edges == i)
#         outlines.append(outline_points)
#
#     newOuts = []
#     # for i in range(0, len(outlines)):
#     #     if len(outlines[i]) > 25:
#     #         newOuts.append(outlines[i])
#     return newOuts  # List of arrays, each representing an outline
#
#
# def display_edge_outlines(image_path, sigma, low_threshold, high_threshold):
#     # Extract the outlines
#     outlines = extract_edge_outlines(
#         image_path, sigma, low_threshold, high_threshold)
#
#     # Load the original image
#     image = io.imread(image_path)
#
#     # Plot the original image with the outlines overlaid
#     plt.imshow(image)
#
#     # Define colors for outlines
#     colors = ["red", "blue", "green", "yellow", "cyan", "magenta"]
#
#     for i, outline in enumerate(outlines):
#         plt.scatter(
#             outline[:, 1],
#             outline[:, 0],
#             color=colors[i % len(colors)],
#             s=1,
#             label=f"Outline {i + 1}",
#         )
#
#     plt.title("Detected Outlines")
#     plt.legend()
#     plt.axis("off")
#     plt.show()
#
#     return outlines
#
#
# # Example usage
# image_path = "./imgs/AdobeGold.jpg"  # Replace with your image path
# sigma = 1
# low_threshold = 0.1
# high_threshold = 0.4
#
# # Get and display the outlines
# outlines = display_edge_outlines(
#     image_path, sigma, low_threshold, high_threshold)
#
# # Print the extracted outlines
# for i, outline in enumerate(outlines):
#     print(f"\nOutline {i + 1} ({len(outline)} points):")
#     print(outline)  # Print all points for this outline


import numpy as np
from skimage import io, color, feature
import matplotlib.pyplot as plt
from scipy.ndimage import label, binary_dilation, generate_binary_structure


def extract_merged_outlines(image_path, sigma=1, low_threshold=0.1, high_threshold=0.4):
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

    # Label initial edge regions
    labeled_edges, num_features = label(edges)

    # Define a structuring element for merging nearby edges
    struct_element = generate_binary_structure(
        2, 2
    )  # 8-connectivity (merges touching regions)

    # Expand edges slightly to merge touching components
    merged_edges = binary_dilation(labeled_edges > 0, structure=struct_element)

    # Relabel the merged components
    merged_labels, merged_count = label(merged_edges)

    # Extract points for each merged outline
    merged_outlines = []
    for i in range(1, merged_count + 1):
        outline_points = np.argwhere(merged_labels == i)
        merged_outlines.append(outline_points)

    # # merged_outlines.sort()
    # # np.sort(merged_outlines)
    # topMerged = merged_outlines[0:3]

    topMerged = [[], [], []]
    for i in range(len(merged_outlines)):
        for j in range(len(topMerged)):
            if len(merged_outlines[i]) > len(topMerged[j]):
                topMerged[j] = merged_outlines[i]
                continue

    return topMerged
    # return topMerged  # List of arrays, each representing a merged outline


def display_merged_outlines(image_path, sigma, low_threshold, high_threshold):
    # Extract merged outlines
    merged_outlines = extract_merged_outlines(
        image_path, sigma, low_threshold, high_threshold
    )

    # Load the original image
    image = io.imread(image_path)

    # Plot the original image with merged outlines overlaid
    plt.imshow(image)

    # Define colors for outlines
    colors = ["red", "blue", "green", "yellow", "cyan", "magenta"]

    for i, outline in enumerate(merged_outlines):
        plt.scatter(
            outline[:, 1],
            outline[:, 0],
            color=colors[i % len(colors)],
            s=1,
            label=f"Group {i + 1}",
        )

    plt.title("Grouped Outlines (Touching Outlines Merged)")
    plt.legend()
    plt.axis("off")
    plt.show()

    return merged_outlines


# Example usage
image_path = "./imgs/overheadGolfGreen.jpg"  # Replace with your image path
sigma = 1
low_threshold = 0.1
high_threshold = 0.4

# Get and display the merged outlines
merged_outlines = display_merged_outlines(
    image_path, sigma, low_threshold, high_threshold
)

# Print the extracted outlines
for i, outline in enumerate(merged_outlines):
    print(f"\nMerged Outline {i + 1} ({len(outline)} points):")
    print(outline[:5])  # Print first 5 points as a sample

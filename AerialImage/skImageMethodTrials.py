import matplotlib.pyplot as plt
from skimage import io, color, filters, feature
import numpy as np


def test_edge_detection_methods(image_path):
    # Load the image
    image = io.imread(image_path)
    gray_image = color.rgb2gray(image)  # Convert to grayscale

    # Apply edge detection methods
    edge_detection_methods = {
        "Canny": feature.canny(gray_image, sigma=2),
        "Sobel": filters.sobel(gray_image),
        "Prewitt": filters.prewitt(gray_image),
        "Roberts": filters.roberts(gray_image),
        "Scharr": filters.scharr(gray_image),
        "Laplace": filters.laplace(gray_image, ksize=3),  # Laplacian of Gaussian
    }

    # Set up subplots
    num_methods = len(edge_detection_methods)
    fig, axes = plt.subplots(1, num_methods + 1, figsize=(20, 5))

    # Show the original image in the first subplot
    axes[0].imshow(gray_image, cmap="gray")
    axes[0].set_title("Original Image")
    axes[0].axis("off")

    # Show edge detection results with red outlines
    for idx, (method_name, edges) in enumerate(edge_detection_methods.items(), start=1):
        # Convert edges to a boolean array (thresholding for float outputs)
        if edges.dtype != bool:
            edges = edges > 0.1  # Threshold value, can be adjusted

        # Create an RGB image by stacking the grayscale image
        rgb_image = np.dstack([gray_image, gray_image, gray_image])

        # Overlay edges in red (set red channel where edges are true)
        rgb_image[edges, 0] = 1  # Red channel
        rgb_image[edges, 1] = 0  # Green channel
        rgb_image[edges, 2] = 0  # Blue channel

        axes[idx].imshow(rgb_image)
        axes[idx].set_title(method_name)
        axes[idx].axis("off")

    plt.tight_layout()
    plt.show()


# Path to your image
image_path = "./HalesworthCloseUp.png"  # Replace with your image path

# Run the program
test_edge_detection_methods(image_path)

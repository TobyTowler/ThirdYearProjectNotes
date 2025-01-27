import cv2
import numpy as np
import matplotlib.pyplot as plt


def preprocess_image(image_path):
    """Preprocess the image: load, grayscale, and blur."""
    # Load image
    image = cv2.imread(image_path)
    if image is None:
        print("Error: Unable to load the image. Check the file path.")
        exit()

    # Convert to grayscale
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Apply Gaussian Blur
    blurred = cv2.GaussianBlur(gray, (5, 5), 0)

    return image, gray, blurred


def canny_edge_detection(blurred):
    """Apply Canny edge detection."""
    edges = cv2.Canny(blurred, threshold1=50, threshold2=150)
    return edges


def contour_detection(blurred):
    """Detect contours from a thresholded binary image."""
    _, binary = cv2.threshold(blurred, 127, 255, cv2.THRESH_BINARY)
    contours, _ = cv2.findContours(binary, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    return contours, binary


def watershed_segmentation(original, blurred):
    """Apply watershed segmentation to detect boundaries."""
    # Threshold to create a binary image
    _, binary = cv2.threshold(blurred, 127, 255, cv2.THRESH_BINARY_INV)

    # Distance transform
    dist_transform = cv2.distanceTransform(binary, cv2.DIST_L2, 5)
    _, sure_fg = cv2.threshold(dist_transform, 0.7 * dist_transform.max(), 255, 0)

    # Unknown regions
    sure_fg = np.uint8(sure_fg)
    unknown = cv2.subtract(binary, sure_fg)

    # Markers
    markers = cv2.connectedComponents(sure_fg)[1]
    markers = markers + 1
    markers[unknown == 255] = 0

    # Apply watershed
    markers = cv2.watershed(original, markers)
    segmented_image = original.copy()
    segmented_image[markers == -1] = [255, 0, 0]  # Mark boundaries in red

    return segmented_image


def display_results(title, image):
    """Display an image using matplotlib."""
    plt.imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
    plt.title(title)
    plt.axis("off")
    plt.show()


def main():
    # File path to your aerial image
    image_path = "./AdobeGold.jpg"

    # Step 1: Preprocess the image
    original_image, gray_image, blurred_image = preprocess_image(image_path)

    # Step 2: Canny Edge Detection
    edges = canny_edge_detection(blurred_image)
    edge_image = cv2.cvtColor(
        edges, cv2.COLOR_GRAY2BGR
    )  # Convert to BGR for visualization
    display_results("Canny Edge Detection", edge_image)

    # Step 3: Contour Detection
    contours, binary_image = contour_detection(blurred_image)
    contour_image = original_image.copy()
    cv2.drawContours(contour_image, contours, -1, (0, 255, 0), 2)  # Green contours
    display_results("Contour Detection", contour_image)

    # Step 4: Watershed Segmentation
    watershed_image = watershed_segmentation(original_image.copy(), blurred_image)
    display_results("Watershed Segmentation", watershed_image)

    # Step 5: Combined Results
    combined_image = cv2.addWeighted(edge_image, 0.5, contour_image, 0.5, 0)
    display_results("Combined Techniques", combined_image)


main()

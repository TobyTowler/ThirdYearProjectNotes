import cv2
import numpy as np
import matplotlib.pyplot as plt


def extract_field_outline(image_path):
    # Load the image
    image = cv2.imread(image_path)
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)  # Convert to grayscale

    # Apply Gaussian blur to reduce noise
    blurred = cv2.GaussianBlur(gray, (5, 5), 0)

    # Apply Otsu's thresholding (automatically finds optimal threshold)
    _, thresh = cv2.threshold(
        blurred, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)

    lower_green = np.array(
        [35, 40, 40]
    )  # Adjust these values based on the field's color
    upper_green = np.array([85, 255, 255])

    # Create a mask for the green field
    # green_mask = cv2.inRange(gray, lower_green, upper_green)

    # Apply Canny edge detection
    edges = cv2.Canny(thresh, 50, 150)

    # Morphological closing to fill gaps in edges
    kernel = np.ones((5, 5), np.uint8)
    edges_closed = cv2.morphologyEx(edges, cv2.MORPH_CLOSE, kernel)

    # Find contours
    contours, _ = cv2.findContours(
        edges_closed, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE
    )

    # Find the largest contour (assumed to be the field)
    largest_contour = max(contours, key=cv2.contourArea)

    # Convert to an array of (x, y) points
    field_outline = largest_contour.reshape(-1, 2)

    return field_outline, image, edges, edges_closed


def display_field_outline(image_path):
    field_outline, image, edges, edges_closed = extract_field_outline(
        image_path)

    # Plot results
    plt.figure(figsize=(10, 5))

    # Original Image
    plt.subplot(1, 3, 1)
    plt.imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
    plt.title("Original Image")
    plt.axis("off")

    # Edge Detection
    plt.subplot(1, 3, 2)
    plt.imshow(edges, cmap="gray")
    plt.title("Canny Edges")
    plt.axis("off")

    # Final Outline
    plt.subplot(1, 3, 3)
    plt.imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
    plt.plot(field_outline[:, 0], field_outline[:, 1],
             color="red", linewidth=2)
    plt.title("Extracted Field Outline")
    plt.axis("off")

    plt.show()

    return field_outline


# Example usage
image_path = "./imgs/overheadGolfCourse.jpg"  # Replace with your field image
outline_points = display_field_outline(image_path)

# Print the extracted outline points
print("Extracted Field Outline Points:")
print(outline_points)

# import cv2
# import numpy as np
# import matplotlib.pyplot as plt
#
#
# def extract_field_outlines(image_path, min_area=1000):
#     # Load the image
#     image = cv2.imread(image_path)
#     original_image = image.copy()  # Keep a copy for visualization
#
#     # Convert the image to RGB (for color filtering) and then to HSV
#     # hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
#     hsv = image
#
#     # Define a range for green color in HSV (typical for fields)
#     lower_green = np.array(
#         [35, 40, 40]
#     )  # Adjust these values based on the field's color
#     upper_green = np.array([85, 255, 255])
#
#     # Create a mask for the green field
#     green_mask = cv2.inRange(hsv, lower_green, upper_green)
#
#     # Perform morphological operations to clean up the mask (remove noise and fill gaps)
#     kernel = np.ones((5, 5), np.uint8)
#     green_mask_cleaned = cv2.morphologyEx(green_mask, cv2.MORPH_CLOSE, kernel)
#
#     # Find contours in the mask
#     contours, _ = cv2.findContours(
#         green_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE
#     )
#
#     # Filter contours based on area (to remove small noise)
#     large_contours = [
#         cnt for cnt in contours if cv2.contourArea(cnt) > min_area]
#
#     # Sort contours by area (descending order)
#     sorted_contours = sorted(large_contours, key=cv2.contourArea, reverse=True)
#
#     # Approximate each contour for accuracy
#     approx_contours = []
#     for contour in large_contours:
#         epsilon = 0.02 * cv2.arcLength(contour, True)
#         approx = cv2.approxPolyDP(contour, epsilon, True)
#         approx_contours.append(approx)
#
#     # Get the top 3 largest contours
#     top_contours = approx_contours[:3]
#
#     # Convert contours to arrays of points
#     outline_points = [cnt.reshape(-1, 2) for cnt in top_contours]
#
#     return outline_points, original_image, green_mask, green_mask_cleaned
#
#
# def display_field_outlines(image_path):
#     outline_points, original_image, green_mask, green_mask_cleaned = (
#         extract_field_outlines(image_path)
#     )
#
#     # Plot results
#     plt.figure(figsize=(12, 6))
#
#     # Original Image
#     plt.subplot(1, 3, 1)
#     plt.imshow(cv2.cvtColor(original_image, cv2.COLOR_BGR2RGB))
#     plt.title("Original Image")
#     plt.axis("off")
#
#     # Green Mask (Field Extraction)
#     plt.subplot(1, 3, 2)
#     plt.imshow(green_mask, cmap="gray")
#     plt.title("Green Mask")
#     plt.axis("off")
#
#     # Cleaned Mask (After Morphological Operations)
#     plt.subplot(1, 3, 3)
#     plt.imshow(green_mask_cleaned, cmap="gray")
#     plt.title("Cleaned Mask")
#     plt.axis("off")
#
#     # Show the outlines over the original image
#     plt.figure(figsize=(6, 6))
#     plt.imshow(cv2.cvtColor(original_image, cv2.COLOR_BGR2RGB))
#
#     # Draw the contours on the image
#     colors = ["red", "blue", "green", "yellow", "cyan"]
#     for i, outline in enumerate(outline_points):
#         plt.plot(
#             outline[:, 0],
#             outline[:, 1],
#             color=colors[i % len(colors)],
#             linewidth=2,
#             label=f"Outline {i + 1}",
#         )
#
#     plt.title("Top 3 Largest Field Outlines")
#     plt.legend()
#     plt.axis("off")
#     plt.show()
#
#     return outline_points
#
#
# # Example usage
# image_path = "./imgs/overheadGolfCourse.jpg"  # Replace with your field image
# outline_points = display_field_outlines(image_path)
#
# # Print the extracted outline points
# for i, outline in enumerate(outline_points):
#     print(f"\nOutline {i + 1} ({len(outline)} points):")
#     print(outline[:5])  # Print first 5 points as a sample

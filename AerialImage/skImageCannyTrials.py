import matplotlib.pyplot as plt
from skimage import io, color, feature
import numpy as np
from itertools import product


def test_canny_combinations(
    image_path, sigma_values, low_thresholds, high_thresholds, output_path
):
    # Load the image
    image = io.imread(image_path)
    gray_image = color.rgb2gray(image)  # Convert to grayscale

    # Generate valid parameter combinations (low_threshold < high_threshold)
    parameter_combinations = [
        (sigma, low_threshold, high_threshold)
        for sigma, low_threshold, high_threshold in product(
            sigma_values, low_thresholds, high_thresholds
        )
        if low_threshold < high_threshold
    ]

    # Group combinations by sigma
    grouped_combinations = {}
    for sigma, low_threshold, high_threshold in parameter_combinations:
        if sigma not in grouped_combinations:
            grouped_combinations[sigma] = []
        grouped_combinations[sigma].append((low_threshold, high_threshold))

    # Plot results
    rows = len(grouped_combinations)  # No additional row for original image
    cols = max(len(grouped_combinations[sigma])
               for sigma in grouped_combinations)

    # Increase figsize to make the images bigger
    fig, axes = plt.subplots(
        rows, cols, figsize=(20, (rows) * 6)
    )  # Adjust figsize for larger output

    # Ensure axes is always 2D, even if it's only 1 row or column
    if rows == 1:
        axes = np.expand_dims(axes, axis=0)  # Ensure axes is always 2D
    if cols == 1:
        axes = np.expand_dims(axes, axis=1)  # Ensure axes is always 2D

    # Iterate through grouped combinations directly
    for row_idx, (sigma, thresholds) in enumerate(grouped_combinations.items()):
        for col_idx, (low_threshold, high_threshold) in enumerate(thresholds):
            # Apply Canny edge detection with current parameters
            edges = feature.canny(
                gray_image,
                sigma=sigma,
                low_threshold=low_threshold,
                high_threshold=high_threshold,
            )

            # Display the result
            ax = axes[row_idx, col_idx]
            ax.imshow(edges, cmap="gray")
            ax.set_title(f"LT={low_threshold}, HT={high_threshold}")
            ax.axis("off")

        # Add a label for the sigma row
        axes[row_idx, 0].text(
            -0.5,
            0.5,
            f"σ={sigma}",
            fontsize=14,
            va="center",
            ha="right",
            rotation=90,
            transform=axes[row_idx, 0].transAxes,
        )

    # Hide unused subplots (if any)
    for row in range(rows):
        for col in range(cols):
            # If the subplot should be empty, hide it
            if row >= len(grouped_combinations) or col >= len(
                grouped_combinations.get(
                    list(grouped_combinations.keys())[row], [])
            ):
                axes[row, col].axis("off")

    # Save the figure to a file
    plt.tight_layout()
    plt.savefig(
        output_path
    )  # Save the image (output_path is the file name with extension)
    plt.close()  # Close the figure to free memory


# Define your parameter ranges
sigma_values = [1, 2]  # Removed sigma=3
low_thresholds = [0.1, 0.2, 0.3]  # Test lower thresholds
high_thresholds = [0.2, 0.3, 0.4]  # Test higher thresholds

# Path to your image
image_path = "./imgs/AdobeGold.jpg"  # Replace with your image path

# Path to save the output image (output_path)
output_path = image_path + "output.jpg"

# Run the program
test_canny_combinations(
    image_path, sigma_values, low_thresholds, high_thresholds, output_path
)


"""
results

adobeGold = 1, 0.1, 0.4 -- 1, 0.1, any
overheadGolfCourse = 2, 0.1, 0.2 -- 1, 0,2, 0.1
overheadGolfGreen = 2, 0.1, 0.2 -- 1, 0.1, 0.3
overheadGolf1 = 





"""

import rasterio
import numpy as np
import cv2
import torch
import torchvision.transforms as T
import segmentation_models_pytorch as smp
import matplotlib.pyplot as plt

# =======================
# 1️⃣ Load Sentinel-2 Image
# =======================
sentinel_image_path = "./imgs/map1.tif"

# Open the Sentinel-2 TIFF file
with rasterio.open(sentinel_image_path) as dataset:
    num_bands = dataset.count
    print(f"Number of bands in image: {num_bands}")

    # Read all bands and visualize to determine order
    bands = [dataset.read(i + 1).astype(np.float32) for i in range(num_bands)]

# Display bands for manual verification
fig, axes = plt.subplots(1, num_bands, figsize=(15, 5))
for i in range(num_bands):
    axes[i].imshow(bands[i], cmap="gray")
    axes[i].set_title(f"Band {i + 1}")
plt.show()

# =======================
# 2️⃣ Identify Correct Bands (Red, Green, Blue, NIR)
# =======================
if num_bands == 4:  # Common Sentinel-2 RGB + NIR case
    red, green, blue, nir = bands
else:
    raise ValueError("Unexpected number of bands! Manually verify the image.")

# Normalize bands (Scale to 0-1)
red /= 10000.0
green /= 10000.0
blue /= 10000.0
nir /= 10000.0

# Compute NDVI (Vegetation Index)
ndvi = (nir - red) / (nir + red + 1e-6)

# Display NDVI
plt.imshow(ndvi, cmap="RdYlGn")
plt.colorbar()
plt.title("NDVI - Field Vegetation Index")
plt.show()

# =======================
# 3️⃣ Prepare Image for U-Net
# =======================
# Stack RGB + NDVI as input channels
input_image = np.stack([red, green, blue, ndvi], axis=-1)
input_size = (1024, 1024)  # Resize for model compatibility
resized_image = cv2.resize(input_image, input_size)

# Convert to PyTorch tensor
transform = T.Compose(
    [
        T.ToTensor(),
        T.Normalize(
            mean=[0.5, 0.5, 0.5, 0.0], std=[0.2, 0.2, 0.2, 0.1]
        ),  # Adjusted for Sentinel-2
    ]
)

image_tensor = (
    transform(resized_image)
    .unsqueeze(0)
    .to("cuda" if torch.cuda.is_available() else "cpu")
)

# =======================
# 4️⃣ Load and Run U-Net Model
# =======================
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
model = (
    smp.Unet(
        encoder_name="efficientnet-b4",
        encoder_weights=None,
        in_channels=4,  # Using 4 channels (RGB + NDVI)
        classes=1,
    )
    .to(device)
    .eval()
)

# Perform segmentation
with torch.no_grad():
    output = model(image_tensor).cpu().squeeze().numpy()

# Apply sigmoid activation
segmentation_mask = torch.sigmoid(torch.tensor(output)).numpy()

# Show segmentation output
plt.figure(figsize=(10, 8))
plt.imshow(segmentation_mask, cmap="gray")
plt.title("Sentinel-2 Field Segmentation Mask")
plt.colorbar()
plt.show()

# =======================
# 5️⃣ Post-Processing: Extract Field Boundaries
# =======================
# Convert mask to binary
binary_mask = (segmentation_mask > 0.3).astype(np.uint8) * 255

# Apply morphological operations to refine boundaries
kernel = np.ones((3, 3), np.uint8)
binary_mask = cv2.morphologyEx(
    binary_mask, cv2.MORPH_CLOSE, kernel
)  # Close small holes
binary_mask = cv2.morphologyEx(
    binary_mask, cv2.MORPH_OPEN, kernel
)  # Remove small noise

# Find contours
# contours, _ = cv2.findContours(binary_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

contours, _ = cv2.findContours(
    binary_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

# Select the largest field contour
if contours:
    largest_contour = max(contours, key=cv2.contourArea)

    # Use an accurate contour approximation
    epsilon = 0.002 * cv2.arcLength(largest_contour, True)
    simplified_contour = cv2.approxPolyDP(largest_contour, epsilon, True)

    # Extract field boundary points
    field_points = simplified_contour.reshape(-1, 2)

    # Draw the field outline
    outlined_image = (resized_image[:, :, :3] * 255).astype(np.uint8)
    cv2.drawContours(outlined_image, [simplified_contour], -1, (0, 255, 0), 2)

    # Show final result
    plt.figure(figsize=(10, 8))
    plt.imshow(outlined_image)
    plt.title("Field Outline from Sentinel-2")
    plt.show()

    print("Extracted Field Boundary Points:", field_points)
else:
    print("No field detected. Try adjusting thresholding.")

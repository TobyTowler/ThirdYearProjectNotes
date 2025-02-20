import numpy as np
import matplotlib.pyplot as plt

from skimage import filters
from skimage.color import rgb2gray
from skimage.data import camera
from skimage.io import imread
from skimage.util import compare_images


image = rgb2gray(imread("./imgs/overheadGolfCourse.jpg"))
edge_roberts = filters.roberts(image)
edge_sobel = filters.sobel(image)

fig, axes = plt.subplots(ncols=2, sharex=True, sharey=True, figsize=(8, 4))

axes[0].imshow(edge_roberts, cmap=plt.cm.gray)
axes[0].set_title("Roberts Edge Detection")

axes[1].imshow(edge_sobel, cmap=plt.cm.gray)
axes[1].set_title("Sobel Edge Detection")

for ax in axes:
    ax.axis("off")

plt.tight_layout()
plt.show()

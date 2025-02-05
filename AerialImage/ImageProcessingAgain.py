import imageio.v3 as iio
import ipympl
import matplotlib.pyplot as plt
import numpy as np
import skimage as ski
from PIL import ImageFilter


maize_roots = iio.imread(uri="./imgs/overheadGolfGreen.jpg")
maize_roots = np.array(maize_roots)

# display original image
fig, ax = plt.subplots()
ax.imshow(maize_roots)

maize_roots[maize_roots < 128] = 0

# display modified image
fig, ax = plt.subplots()
ax.imshow(maize_roots)

plt.figure()
plt.imshow(maize_roots)
plt.show(block=True)

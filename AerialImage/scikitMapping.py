import matplotlib.pyplot as plt
from skimage import io, color, feature
import numpy as np
from itertools import product


def readImg(image):
    image = imread(image)

from PIL import Image, ImageFilter
import matplotlib.pyplot as plt

filename_cat = "./imgs/overheadGolfGreen.jpg"

with Image.open(filename_cat) as img_cat:
    img_cat.load()

# img_cat = img_cat.crop((800, 0, 1650, 1281))
img_cat.show()

img_cat_gray = img_cat.convert("L")
img_cat_gray.show()
threshold = 100
img_cat_threshold = img_cat_gray.point(lambda x: 255 if x > threshold else 0)
img_cat_threshold.show()


red, green, blue = img_cat.split()
red.show()
green.show()
blue.show()


threshold = 57
img_cat_threshold = blue.point(lambda x: 255 if x > threshold else 0)
img_cat_threshold = img_cat_threshold.convert("1")
img_cat_threshold.show()


def erode(cycles, image):
    for _ in range(cycles):
        image = image.filter(ImageFilter.MinFilter(3))
    return image


def dilate(cycles, image):
    for _ in range(cycles):
        image = image.filter(ImageFilter.MaxFilter(3))
    return image


step_1 = erode(12, img_cat_threshold)
step_1.show()

step_2 = dilate(58, step_1)
step_2.show()

cat_mask = erode(45, step_2)
cat_mask.show()

cat_mask = cat_mask.convert("L")
cat_mask = cat_mask.filter(ImageFilter.BoxBlur(20))
cat_mask.show()

blank = img_cat.point(lambda _: 0)
cat_segmented = Image.composite(img_cat, blank, cat_mask)
cat_segmented.show()

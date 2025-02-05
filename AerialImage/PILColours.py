from PIL import Image
import matplotlib.pyplot as plt


img = Image.open("./imgs/overheadGolfGreen.jpg")
img = img.convert("RGB")

d = img.getdata()

new_image = []
for item in d:
    # change all white (also shades of whites)
    # pixels to yellow
    if item[0] in list(range(200, 256)):
        new_image.append((255, 224, 100))
    else:
        new_image.append(item)

# update image data
img.putdata(new_image)

plt.figure()
plt.imshow(img)
plt.show(block=True)

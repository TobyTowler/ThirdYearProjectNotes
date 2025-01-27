import rioxarray
import matplotlib.pyplot as plt

# %matplotlib inline
xds = rioxarray.open_rasterio(
    "./HalesworthCloseUp.png",
    masked=True,
)


# xds.rio.write_crs("EPSG: 32618")
xds.rio.write_crs("epsg:4326", inplace=True)
# upscale_factor = 2
# new_width = xds.rio.width * upscale_factor
# new_height = xds.rio.height * upscale_factor
#
# xds_upsampled = xds.rio.reproject(
#     xds.rio.crs,
#     shape=(new_height, new_width),
#     resampling=Resampling.bilinear,
# )


xds.plot()


geometries = [
    {
        "type": "Polygon",
        "coordinates": [
            [
                [425499.18381405267, 4615331.540546387],
                [425499.18381405267, 4615478.540546387],
                [425526.18381405267, 4615478.540546387],
                [425526.18381405267, 4615331.540546387],
                [425499.18381405267, 4615331.540546387],
            ]
        ],
    }
]
# clipped = xds.rio.clip(geometries)

# clipped.plot()

import random


def genPoints(num):
    points = []
    for i in range(num):
        randX = random.randint(0, 300)
        randY = random.randint(0, 300)
        points.append([randX, randY, -1])  # X, Y, polar angle -1 is default
    return points


def grahamScan(points):
    hull = []
    points.sort(key=lambda x: x[1])
    hull.append(points[0])

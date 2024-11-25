import fields2cover as f2c
import random
import math
import turtle


class Point:
    X = -1
    Y = -1
    angle = -10

    def __init__(self, x, y):
        self.X = x
        self.Y = y
        self.angle = -10

    def __str__(self):
        return f"Point(X: {self.X}, Y: {self.Y}, Angle: {self.angle})"


def printPoints(points):
    print("PRINTING POINTS")
    for i in range(len(points) - 1):
        print(points[i])

    print("\n\n")


def genPoints(num, P: Point, size):
    points = []
    for i in range(num):
        randX = random.randint(P.X + 1, P.X + size)
        randY = random.randint(P.Y + 1, P.Y + size)
        points.append(Point(randX, randY))
    return points


def calcAngle(p1, p2):
    return math.atan((p2.Y - p1.Y) / (p2.X - p1.X))


def sortPoints(points, origin):
    hull = [origin]

    points.sort(key=lambda x: x.Y)
    printPoints(points)

    origin = hull[0]
    for i in range(len(points)):
        points[i].angle = calcAngle(origin, points[i])

    points.sort(key=lambda x: x.angle)
    printPoints(points)
    hull += points
    return hull


def drawPoints(arr):
    for i in arr:
        turtle.penup()
        for n in i:
            turtle.goto(n.X, n.Y)
            turtle.pendown()
        turtle.goto(i[0].X, i[0].Y)
    turtle.exitonclick()


def main():
    hull = []

    Origin = Point(20, 20)
    field = genPoints(8, Origin, 400)
    hull.append(sortPoints(field, Origin))

    hole1Base = Point(100, 100)
    hole1Points = genPoints(5, hole1Base, 50)
    hull.append(sortPoints(hole1Points, hole1Base))

    hole2Base = Point(150, 50)
    hole2Points = genPoints(3, hole2Base, 30)
    hull.append(sortPoints(hole2Points, hole2Base))

    # drawPoints(hull)

    map = []
    for i in hull:
        ring = f2c.LinearRing()
        for j in i:
            # p = f2c.Point(j.X, j.Y)
            ring.addGeometry(f2c.Point(j.X, j.Y))
        ring.addPoint(f2c.Point(i[0].X, i[0].Y))
        map.append(ring)

    print(len(map))
    f2c.Visualizer.figure()
    for i in map:
        f2c.Visualizer.plot(i)
    f2c.Visualizer.show()
    # f2c.Visualizer.save("Tutorial_image.png")


main()

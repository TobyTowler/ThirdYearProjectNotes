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


def genPoints(num):
    points = []
    for i in range(num):
        randX = random.randint(0, 300)
        randY = random.randint(0, 300)
        points.append(Point(randX, randY))
    return points


def calcAngle(p1, p2):
    return math.atan((p2.Y - p1.Y) / (p2.X - p1.X))


def sortPoints(points):
    hull = [Point(0, 0)]

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
    turtle.penup()
    for n in arr:
        turtle.goto(n.X, n.Y)
        turtle.pendown()

    turtle.goto(arr[0].X, arr[0].Y)
    turtle.exitonclick()


def main():
    map = genPoints(4)
    hull = sortPoints(map)
    drawPoints(hull)


main()

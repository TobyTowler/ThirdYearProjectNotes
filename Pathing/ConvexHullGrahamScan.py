import random
import math
import turtle


class Point:
    X = -1
    Y = -1
    angle = -1

    def __init__(self, x, y):
        self.X = x
        self.Y = y
        self.angle = -1

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
    return math.tan((p1.Y - p2.Y) - (p1.X - p2.X))


def sortPoints(points):
    hull = []
    points.sort(key=lambda x: x.Y)
    printPoints(points)

    hull.append(points[0])

    origin = hull[0]
    points.pop(0)
    for i in range(len(points) - 2):
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

def AcceptPoints(points):
    


def main():
    map = genPoints(10)
    hull = sortPoints(map)
    drawPoints(hull)


main()

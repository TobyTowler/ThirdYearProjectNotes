# import matplotlib.pyplot as plt
import turtle
import random


def createMap(n, k):
    mapBoundaries = []
    # map points
    pointsarr = []
    for i in range(n):
        randX = random.randint(0, 500)
        randY = random.randint(0, 500)
        pointsarr.append([randX, randY])

    pointsarr.sort()
    mapBoundaries.append(pointsarr)
    for i in range(k):
        holearr = []
        randBound = random.randint(1, 8)
        for j in range(randBound):
            randX = random.randint(0, 100)
            randY = random.randint(0, 100)
            holearr.append([randX, randY])
        mapBoundaries.append(holearr)
    return mapBoundaries


def sortPoints(arr):
    #    start = arr[0][1]
    #    newMap = [[]]
    #    before = []
    #    after = []
    #    print(newMap, "\n")
    #    for i in arr:
    #        num = i[1]
    #        if num < start:
    #            before.append(arr[i])
    #        else:
    #            after.append(arr[i])
    #
    #    newMap += before
    #    newMap.append(arr[0])
    #    newMap += after
    #    print("new map:::", newMap, "\n\n")
    #    return newMap
    #
    print("Hello")
    start = arr[0]
    left = []
    right = []
    for i in arr:
        if i[1] < start[1]:
            left.append(i)
        else:
            right.append(i)
    # left.append(start)
    left += right
    return left


map = createMap(8, 2)
print(map)

sortedMap = sortPoints(map[0])
print(sortedMap)


def draw(map):
    for n in map:
        turtle.goto(n)
        # turtle.pendown()

    turtle.goto(map[0])
    turtle.exitonclick()


draw(map[0])

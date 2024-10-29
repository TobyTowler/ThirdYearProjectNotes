# import matplotlib.pyplot as plt
import turtle
import random


def createMap(n, k):
    mapBoundaries = []
    # map points
    pointsarr = []
    for i in range(n):
        randX = random.randint(0, 300)
        randY = random.randint(0, 300)
        pointsarr.append([randX, randY])

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


def sortPoints(map):
    above = []
    below = []
    map.sort()
    origin = map[0]
    newMap = [origin]
    map.pop(0)
    for i in map:
        if i[1] < origin[1] + 10:
            print(i, origin, "below")
            below.append(i)
        else:
            print(i, origin, "above")
            above.append(i)

    above.reverse()

    # i = len(below) - 1
    # if i > 0:
    #     if below[i][1] < below[i - 1][1]:
    #         temp = below[i]
    #         below[i] = below[i - 1]
    #         below[i - 1] = temp
    #
    # else:
    #     i = len(above) - 1
    #     # if above[i][0] > above[i - 1][0]:
    #     #     temp = above[i]
    #     #     above[i] = above[i - 1]
    #     #     above[i - 1] = temp
    #     for j in range(len(above)):
    #         if above[i][0] <
    #

    newMap += below
    newMap += above
    print("\nBELOW", below)
    print("\nABOVE", above)

    return newMap


map = createMap(15, 2)
print("Map", map)

sortedMap = sortPoints(map[0])
print("Sorted map", sortedMap)


def draw(map):
    turtle.penup()
    # turtle.hideturtle()
    # turtle.speed(0)
    for n in map:
        turtle.goto(n)
        turtle.pendown()
        # turtle.pendown()

    turtle.goto(map[0])
    turtle.exitonclick()


# Work out O(n) complexity
# draw(map[0])

# test = [[0, 0], [0, 300], [300, 300], [300, 0]]
draw(sortedMap)

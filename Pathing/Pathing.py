import fields2cover as f2c
import math
# import Mapping


def mowerConfig(length, width):
    mower = f2c.Robot(length, width)
    return mower


def fieldConfig():
    rand = f2c.Random(42)
    field = rand.generateRandField(1e4, 5)
    cell = field.getField()
    return cell, field


def headlandGen(cells, mower):
    const_hl = f2c.HG_Const_gen()
    no_hl = const_hl.generateHeadlands(cells, 3.0 * mower.getWidth())
    return no_hl


def swatchGen(mower, no_hl):
    n_swath = f2c.OBJ_NSwath()
    bf_sw_gen = f2c.SG_BruteForce()
    swaths_bf_nswath = bf_sw_gen.generateBestSwaths(
        n_swath, mower.getCovWidth(), no_hl.getGeometry(0)
    )
    return swaths_bf_nswath


def routeGen(cells, robot):
    const_hl = f2c.HG_Const_gen()
    mid_hl = const_hl.generateHeadlands(cells, 1.5 * robot.getWidth())
    no_hl = const_hl.generateHeadlands(cells, 3.0 * robot.getWidth())
    bf = f2c.SG_BruteForce()
    swaths = bf.generateSwaths(math.pi / 2.0, robot.getCovWidth(), no_hl)
    route_planner = f2c.RP_RoutePlannerBase()
    route = route_planner.genRoute(mid_hl, swaths)

    return route


def drawCell(arr):
    f2c.Visualizer.figure()
    for i in arr:
        f2c.Visualizer.plot(i)
    f2c.Visualizer.show()
    # f2c.Visualizer.save("Tutorial_image.pn


def main():
    mower = mowerConfig(2, 5)
    fieldToCalc, fieldToDraw = fieldConfig()
    headland = headlandGen(fieldToCalc, mower)

    arrToDraw = [fieldToDraw, headland]
    # drawCell(arrToDraw)

    swaths = swatchGen(mower, headland)
    # arrToDraw.append(swaths)

    route = routeGen(fieldToCalc, mower)
    arrToDraw.append(route)
    drawCell(arrToDraw)


main()

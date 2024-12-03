import fields2cover as f2c
import math
# import Mapping


def mowerConfig(length, width):
    mower = f2c.Robot(length, width)
    mower.setMinTurningRadius(2)  # m
    mower.setMaxDiffCurv(0.1)  # 1/m^2
    return mower


def fieldConfig(angles):
    rand = f2c.Random()
    field = rand.generateRandField(1e4, angles)
    cells = field.getField()
    return cells


def drawCell(arr):
    f2c.Visualizer.figure()
    for i in arr:
        f2c.Visualizer.plot(i)
    f2c.Visualizer.show()
    # f2c.Visualizer.save("Tutorial_image.pn


def main():
    mower = mowerConfig(2.0, 5.0)

    rand = f2c.Random(42)
    field = rand.generateRandField(1e4, 6)
    hole = rand.generateRandCell(121, 4)
    # hole1 = hole.getField()
    cell = field.getField()
    # cell = f2c.Cell()

    # cells = fieldConfig(6)

    const_hl = f2c.HG_Const_gen()
    no_hl = const_hl.generateHeadlands(cell, 3.0 * mower.getWidth())

    bf = f2c.SG_BruteForce()
    swaths = bf.generateSwaths(math.pi, mower.getCovWidth(), no_hl.getGeometry(0))
    snake_sorter = f2c.RP_Snake()
    swaths = snake_sorter.genSortedSwaths(swaths)

    path_planner = f2c.PP_PathPlanning()
    dubins_cc = f2c.PP_DubinsCurvesCC()
    path_dubins_cc = path_planner.planPath(mower, swaths, dubins_cc)

    drawCell([cell, swaths, no_hl, path_dubins_cc])
    print(cell[0].area())
    print(path_dubins_cc)


main()

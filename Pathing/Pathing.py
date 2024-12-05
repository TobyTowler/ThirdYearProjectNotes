import fields2cover as f2c
import math
import random
# import Mapping


def mowerConfig(length, width):
    mower = f2c.Robot(length, width)
    mower.setMinTurningRadius(2)  # m
    mower.setMaxDiffCurv(0.1)  # 1/m^2
    return mower


def fieldConfig21313(angles):
    rand = f2c.Random(42)
    field = rand.generateRandField(1e4, 6)
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
    # hole = rand.generateRandCell(121, 4)
    # # hole1 = hole.getField()
    cell = field.getField()
    print(cell)
    # cell = f2c.Cell()

    # cell = fieldConfig21313(6)

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


def randomMultiHoles():
    mower = mowerConfig(1.0, 1.0)

    random.seed(5)
    cells = f2c.Cells(
        f2c.Cell(
            f2c.LinearRing(
                f2c.VectorPoint(
                    [
                        f2c.Point(0, 0),
                        f2c.Point(60, 0),
                        f2c.Point(60, 60),
                        f2c.Point(0, 60),
                        f2c.Point(0, 0),
                        random.randint(0, 150),
                    ]
                )
            )
        )
    )
    cells.addRing(
        0,
        f2c.LinearRing(
            f2c.VectorPoint(
                [
                    f2c.Point(12, 12),
                    f2c.Point(12, 18),
                    f2c.Point(18, 18),
                    f2c.Point(18, 12),
                    f2c.Point(12, 12),
                ]
            )
        ),
    )
    cells.addRing(
        0,
        f2c.LinearRing(
            f2c.VectorPoint(
                [
                    f2c.Point(36, 36),
                    f2c.Point(36, 48),
                    f2c.Point(48, 48),
                    f2c.Point(48, 36),
                    f2c.Point(36, 36),
                ]
            )
        ),
    )

    const_hl = f2c.HG_Const_gen()
    mid_hl = const_hl.generateHeadlands(cells, 1.5 * mower.getWidth())
    no_hl = const_hl.generateHeadlands(cells, 3.0 * mower.getWidth())

    bf = f2c.SG_BruteForce()
    swaths = bf.generateSwaths(math.pi / 2.0, mower.getCovWidth(), no_hl)

    route_planner = f2c.RP_RoutePlannerBase()
    route = route_planner.genRoute(mid_hl, swaths)

    drawCell([cells, swaths, no_hl, route])
    print(cells[0].area())
    print(route)


# main()
# multiholes()


def multiholes():
    mower = mowerConfig(1.0, 1.0)

    cells = f2c.Cells(
        f2c.Cell(
            f2c.LinearRing(
                f2c.VectorPoint(
                    [
                        f2c.Point(0, 0),
                        f2c.Point(60, 0),
                        f2c.Point(60, 60),
                        f2c.Point(0, 60),
                        f2c.Point(0, 0),
                    ]
                )
            )
        )
    )


cells.addRing(
    0,
    f2c.LinearRing(
        f2c.VectorPoint(
            [
                f2c.Point(12, 12),
                f2c.Point(12, 18),
                f2c.Point(18, 18),
                f2c.Point(18, 12),
                f2c.Point(12, 12),
            ]
        )
    ),
)
cells.addRing(
    0,
    f2c.LinearRing(
        f2c.VectorPoint(
            [
                f2c.Point(36, 36),
                f2c.Point(36, 48),
                f2c.Point(48, 48),
                f2c.Point(48, 36),
                f2c.Point(36, 36),
            ]
        )
    ),
)

const_hl = f2c.HG_Const_gen()
mid_hl = const_hl.generateHeadlands(cells, 1.5 * mower.getWidth())
no_hl = const_hl.generateHeadlands(cells, 3.0 * mower.getWidth())

bf = f2c.SG_BruteForce()
swaths = bf.generateSwaths(math.pi / 2.0, mower.getCovWidth(), no_hl)

route_planner = f2c.RP_RoutePlannerBase()
route = route_planner.genRoute(mid_hl, swaths)

drawCell([cells, swaths, no_hl, route])
print(cells[0].area())
print(route)

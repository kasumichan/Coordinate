//
// Created by liunianqi on 2021/8/27.
//

#include "Hexahedron.h"
#include "Tetrahedron.h"

Hexahedron::Hexahedron() = default;

Hexahedron::Hexahedron(const QVector<Point> &_pointList) : Element(_pointList) {
    setElementList();
}

Hexahedron::Hexahedron(const Hexahedron &_hexahedron)
        : Element(_hexahedron) {
    setElementList();
}

Point Hexahedron::centroid() const {
    QVector<QVector<int>> splitOrder = {{2, 4, 6, 7},
                                        {2, 4, 3, 7},
                                        {0, 2, 3, 4},
                                        {2, 4, 5, 6},
                                        {1, 2, 4, 5},
                                        {0, 1, 2, 4}};
    QVector<QVector<Point>> tetrPointList(splitOrder.size());
    std::transform(splitOrder.cbegin(), splitOrder.cend(), tetrPointList.begin(),
                   [this](QVector<int> order) {
                       return QVector<Point>{pointList[order[0]], pointList[order[1]], pointList[order[2]],
                                             pointList[order[3]]};
                   });

    return std::accumulate(tetrPointList.cbegin(), tetrPointList.cend(), Point{0, 0, 0},
                           [](Point a, const QVector<Point> &b) {
                               return a + Tetrahedron(b).centroid() * Tetrahedron(b).size();
                           }) /
           std::accumulate(tetrPointList.cbegin(), tetrPointList.cend(), 0,
                           [](float a, const QVector<Point>& b) { return a + Tetrahedron(b).size(); });
}

float Hexahedron::size() const {
    return 0;
}

Plane Hexahedron::getPlane() const {
    return Plane{(pointList[0] + pointList[4]) / 2,
                 (pointList[1] + pointList[5]) / 2,
                 (pointList[2] + pointList[6]) / 2};
}

void Hexahedron::setElementList() {
    elementList = {
            {0, 1, 2, 3},
            {4, 5, 6, 7},
            {0, 4, 5, 1},
            {1, 5, 6, 2},
            {2, 6, 7, 3},
            {3, 7, 4, 0}};
}

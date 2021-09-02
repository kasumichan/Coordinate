//
// Created by liunianqi on 2021/8/27.
//

#include "Hexahedron.h"
#include "Tetrahedron.h"

Hexahedron::Hexahedron() {
}

Hexahedron::Hexahedron(const QVector<Point> &pointList) : Element(pointList) {
    elementList = {
            {0, 1, 2, 3},
            {4, 5, 6, 7},
            {0, 4, 5, 1},
            {1, 5, 6, 2},
            {2, 6, 7, 3},
            {3, 7, 4, 0}};
}

Hexahedron::Hexahedron(const Hexahedron &hexahedron)
        : Element(hexahedron) {
    elementList = {
            {0, 1, 2, 3},
            {4, 5, 6, 7},
            {0, 4, 5, 1},
            {1, 5, 6, 2},
            {2, 6, 7, 3},
            {3, 7, 4, 0}};
}

Point Hexahedron::centroid() const {
    QVector<QVector<Point>> tetrPointList;
    tetrPointList.push_back(QVector<Point>{pointList[2], pointList[4], pointList[6], pointList[7]});
    tetrPointList.push_back(QVector<Point>{pointList[2], pointList[4], pointList[3], pointList[7]});
    tetrPointList.push_back(QVector<Point>{pointList[0], pointList[2], pointList[3], pointList[4]});
    tetrPointList.push_back(QVector<Point>{pointList[2], pointList[4], pointList[5], pointList[6]});
    tetrPointList.push_back(QVector<Point>{pointList[1], pointList[2], pointList[4], pointList[5]});
    tetrPointList.push_back(QVector<Point>{pointList[0], pointList[1], pointList[2], pointList[4]});

    Point weightedPoint(0, 0, 0);
    float volume = 0;
    for (auto pointList: tetrPointList) {
        Tetrahedron tetr(pointList);
        weightedPoint = weightedPoint + tetr.centroid() * tetr.size();
        volume += tetr.size();
    }
    return weightedPoint / volume;
}

float Hexahedron::size() const {
    return 0;
}

Plane Hexahedron::getPlane() const {
    return Plane((pointList[0] + pointList[4]) / 2,
                 (pointList[1] + pointList[5]) / 2, (pointList[2] + pointList[6]) / 2);
}

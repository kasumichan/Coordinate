//
// Created by liunianqi on 2021/8/27.
//

#include "Tetrahedron.h"
#include "Triangle.h"

Tetrahedron::Tetrahedron() = default;

Tetrahedron::Tetrahedron(const QVector<Point> &_pointList) : Element(_pointList) {
    setElementList();
}

Tetrahedron::Tetrahedron(const Tetrahedron &_tetrahedron)
        : Element(_tetrahedron) {
    setElementList();
}

Point Tetrahedron::centroid() const {
    return (pointList[0] + pointList[1] + pointList[2] + pointList[3]) / 4;
}

float Tetrahedron::size() const {
    QVector<Point> basePoint{pointList[0], pointList[1], pointList[2]};
    Triangle base(basePoint);
    Plane basePlane(base.getPointList());
    float height = pointList[3].distanceToPlane(basePlane);
    return base.size() * height / 3;
}

Plane Tetrahedron::getPlane() const {
    return Plane{centroid(), pointList[0], pointList[1]};
}

void Tetrahedron::setElementList() {
    elementList = {
            {0, 1, 3},
            {1, 2, 3},
            {2, 0, 3},
            {0, 1, 2}};
}

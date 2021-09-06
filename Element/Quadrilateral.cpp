//
// Created by liunianqi on 2021/8/27.
//

#include "Quadrilateral.h"

Quadrilateral::Quadrilateral() = default;

Quadrilateral::Quadrilateral(const QVector<Point> &_pointList)
        : Element(_pointList) {
    setElementList();
    setTriangle();
}

Quadrilateral::Quadrilateral(const Quadrilateral &_quadrilateral)
        : Element(_quadrilateral) {
    setElementList();
    setTriangle();
}

Point Quadrilateral::centroid() const {
    return (tr1.centroid() + tr2.centroid()) / 2;
}

float Quadrilateral::size() const {
    return tr1.size() + tr2.size();
}

Plane Quadrilateral::getPlane() const {
    return Plane(getPointList());
}

void Quadrilateral::setElementList() {
    elementList = {
            {0, 1, 2},
            {1, 2, 3}};
}

void Quadrilateral::setTriangle() {
    QVector<Point> tr1Point = {pointList[0], pointList[1], pointList[2]};
    QVector<Point> tr2Point = {pointList[1], pointList[2], pointList[3]};
    tr1 = Triangle(tr1Point);
    tr2 = Triangle(tr2Point);
}

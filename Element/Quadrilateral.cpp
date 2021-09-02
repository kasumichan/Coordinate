//
// Created by liunianqi on 2021/8/27.
//

#include "Quadrilateral.h"

Quadrilateral::Quadrilateral() = default;

Quadrilateral::Quadrilateral(const QVector<Point> &pointList)
        : Element(pointList) {
    elementList = {
            {0, 1, 2},
            {1, 2, 3}};
    QVector<Point> tr1Point = {pointList[0], pointList[1], pointList[2]};
    QVector<Point> tr2Point = {pointList[0], pointList[1], pointList[2]};
    tr1 = Triangle(tr1Point);
    tr2 = Triangle(tr2Point);
}

Quadrilateral::Quadrilateral(const Quadrilateral &quadrilateral)
        : Element(quadrilateral) {
    elementList = {
            {0, 1, 2},
            {1, 2, 3}};
    QVector<Point> tr1Point = {pointList[0], pointList[1], pointList[2]};
    QVector<Point> tr2Point = {pointList[0], pointList[1], pointList[2]};
    tr1 = Triangle(tr1Point);
    tr2 = Triangle(tr2Point);
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
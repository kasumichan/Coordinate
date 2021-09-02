//
// Created by liunianqi on 2021/8/27.
//

#include "Triangle.h"
#include <QVector3D>

Triangle::Triangle() {
}

Triangle::Triangle(const QVector<Point> &pointList)
        : Element(pointList) {
    elementList = {
            {0, 1, 2}};
}

Triangle::Triangle(const Triangle &triangle)
        : Element(triangle) {
    elementList = {
            {0, 1, 2}};
}

Point Triangle::centroid() const {
    return (pointList[0] + pointList[1] + pointList[2]) / 3;
}

float Triangle::size() const {
    Point oneSide = pointList[1] - pointList[0];
    Point anotherSide = pointList[2] - pointList[0];
    return QVector3D::crossProduct(oneSide, anotherSide).length() / 2;
}

Plane Triangle::getPlane() const {
    return Plane(getPointList());
}
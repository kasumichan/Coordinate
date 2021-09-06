//
// Created by liunianqi on 2021/8/27.
//

#include "Triangle.h"
#include <QVector3D>

Triangle::Triangle() {
}

Triangle::Triangle(const QVector<Point> &_pointList)
        : Element(_pointList) {
    setElementList();
}

Triangle::Triangle(const Triangle &_triangle)
        : Element(_triangle) {
    setElementList();
}

Point Triangle::centroid() const {
    return (pointList[0] + pointList[1] + pointList[2]) / 3;
}

float Triangle::size() const {
    QVector3D oneSide = pointList[1] - pointList[0];
    QVector3D anotherSide = pointList[2] - pointList[0];
    return QVector3D::crossProduct(oneSide, anotherSide).length() / 2;
}

Plane Triangle::getPlane() const {
    return Plane(getPointList());
}

void Triangle::setElementList() {
    elementList = {
            {0, 1, 2}};
}

//
// Created by liunianqi on 2021/8/27.
//

#include "Plane.h"
#include <QDebug>

Plane::Plane() = default;

Plane::Plane(const QVector<Point> &_pointList) {
    assert(_pointList.count() >= 3);
    Point a = _pointList[0];
    Point b = _pointList[1];
    Point c = _pointList[2];
    QVector3D oneSide(b - a);
    QVector3D anotherSide(c - a);

    normalVector = QVector3D::crossProduct(oneSide, anotherSide).normalized();

    assert(normalVector.length() > 1e-7);
    A = normalVector.x();
    B = normalVector.y();
    C = normalVector.z();
    D = -A * a.x() - B * a.y() - C * a.z();
}

Plane::Plane(const Point &_a, const Point &_b, const Point &_c)
        : Plane(QVector<Point>{_a, _b, _c}) {
}

float Plane::getA() const {
    return A;
}

float Plane::getB() const {
    return B;
}

float Plane::getC() const {
    return C;
}

float Plane::getD() const {
    return D;
}

QVector3D Plane::getNormalVector() const {
    return normalVector;
}
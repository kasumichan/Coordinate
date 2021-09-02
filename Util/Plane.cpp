//
// Created by liunianqi on 2021/8/27.
//

#include "Plane.h"
#include <QDebug>

Plane::Plane() = default;

Plane::Plane(const QVector<Point> &pointList) {
    if (pointList.count() < 3) {
        qDebug() << "error";
    } else {
        Point a = pointList[0];
        Point b = pointList[1];
        Point c = pointList[2];
        QVector3D oneSide((b - a).x(), (b - a).y(), (b - a).z());
        QVector3D anotherSide((c - a).x(), (c - a).y(), (c - a).z());

        normalVector = QVector3D::crossProduct(oneSide, anotherSide).normalized();
        if (abs(normalVector.length()) < 1e-7) {
            qDebug() << "error";
        } else {
            A = normalVector.x();
            B = normalVector.y();
            C = normalVector.z();
            D = -A * a.x() - B * a.y() - C * a.z();
        }
    }
}

Plane::Plane(const Point &a, const Point &b, const Point &c)
        : Plane(QVector<Point>{a, b, c}) {
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
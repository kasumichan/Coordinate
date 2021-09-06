//
// Created by liunianqi on 2021/8/29.
//

#include "Axis.h"

Axis::Axis() = default;

Axis::Axis(const Point &_base, const QVector3D &_x, const QVector3D &_y, const QVector3D &_z) {
    base = _base;
    x = _x;
    y = _y;
    z = _z;
}

Point Axis::getBase() const {
    return base;
}

QVector3D Axis::getX() const {
    return x;
}

QVector3D Axis::getY() const {
    return y;
}

QVector3D Axis::getZ() const {
    return z;
}
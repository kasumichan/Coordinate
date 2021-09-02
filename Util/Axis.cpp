//
// Created by liunianqi on 2021/8/29.
//

#include "Axis.h"

Axis::Axis() {
}

Axis::Axis(Point base, QVector3D x, QVector3D y, QVector3D z) {
    this->base = base;
    this->x = x;
    this->y = y;
    this->z = z;
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
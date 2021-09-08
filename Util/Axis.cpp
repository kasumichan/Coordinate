//
// Created by liunianqi on 2021/8/29.
//

#include "Axis.h"

Axis::Axis() = default;

Axis::Axis(const Point &_base, const QVector3D &_x, const QVector3D &_y, const QVector3D &_z) {
    this->base = _base;
    this->x = _x;
    this->y = _y;
    this->z = _z;
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

void Axis::setBase(const Point &_point) {
    this->base = _point;
}

void Axis::setX(const QVector3D &_x) {
    this->x = _x;
}

void Axis::setY(const QVector3D &_y) {
    this->y = _y;
}

void Axis::setZ(const QVector3D &_z) {
    this->z = _z;
}

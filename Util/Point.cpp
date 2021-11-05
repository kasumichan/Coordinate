//
// Created by liunianqi on 2021/8/27.
//
#include "Point.h"
#include "Plane.h"
#include "QtMath"

Point::Point() : QVector3D() {
}

Point::Point(float _x, float _y, float _z, int _id) : QVector3D(_x, _y, _z) {
    this->id = _id;
}

Point Point::operator+(const Point &other) const {
    return {x() + other.x(), y() + other.y(), z() + other.z(), id};
}

Point Point::operator-(const Point &other) const {
    return {x() - other.x(), y() - other.y(), z() - other.z(), id};
}

Point Point::operator*(float a) const {
    return {a * x(), a * y(), a * z(), id};
}

Point Point::operator/(float a) const {
    assert(abs(a) > 1e-7);
    return {x() / a, y() / a, z() / a, id};
}

float Point::distanceToPlane(const Plane &plane) const {
    return abs(plane.getA() * x() + plane.getB() * y() + plane.getC() * z() + plane.getD()) /
           sqrt(pow(plane.getA(), 2) + pow(plane.getB(), 2) + pow(plane.getC(), 2));
}

void Point::setID(int _id) {
    this->id = _id;
}

int Point::getID() const {
    return id;
}

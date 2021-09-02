//
// Created by liunianqi on 2021/8/27.
//
#include "Point.h"
#include "Plane.h"
#include "QtMath"

Point::Point() : QVector3D() {
}

Point::Point(float x, float y, float z) : QVector3D(x, y, z) {
}
Point Point::operator+(const Point &other) const {
    return Point(x() + other.x(), y() + other.y(), z() + other.z());
}

Point Point::operator-(const Point &other) const {
    return Point(x() - other.x(), y() - other.y(), z() - other.z());
}

Point Point::operator*(float a) const {
    return Point(a * x(), a * y(), a * z());
}

Point Point::operator/(float a) const {
    if (abs(a) > 1e-7) {
        return Point(x() / a, y() / a, z() / a);
    }
    return Point(x(), y(), z());
}

float Point::distanceToPlane(const Plane &plane) const {
    return abs(plane.getA() * x() + plane.getB() * y() + plane.getC() * z() + plane.getD()) /
           sqrt(pow(plane.getA(), 2) + pow(plane.getB(), 2) + pow(plane.getC(), 2));
}

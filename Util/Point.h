//
// Created by liunianqi on 2021/8/27.
//

#ifndef COORDINATE_POINT_H
#define COORDINATE_POINT_H

#include <QVector3D>

class Plane;

class Point : public QVector3D {

public:
    Point();

    Point(float _x, float _y, float _z);

    Point operator+(const Point &other) const;

    Point operator-(const Point &other) const;

    Point operator*(float a) const;

    Point operator/(float a) const;

    float distanceToPlane(const Plane &plane) const;
};


#endif //COORDINATE_POINT_H

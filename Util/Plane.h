//
// Created by liunianqi on 2021/8/27.
//

#ifndef COORDINATE_PLANE_H
#define COORDINATE_PLANE_H

#include "Point.h"
#include <QVector>
#include <QVector3D>

class Plane {
private:
    float A{};
    float B{};
    float C{};
    float D{};
    QVector3D normalVector;

public:
    Plane();

    explicit Plane(const QVector<Point> &_pointList);

    Plane(const Point &_a, const Point &_b, const Point &_c);

    float getA() const;

    float getB() const;

    float getC() const;

    float getD() const;

    QVector3D getNormalVector() const;
};


#endif //COORDINATE_PLANE_H

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

    explicit Plane(const QVector<Point> &pointList);

    Plane(const Point &a, const Point &b, const Point &c);

    float getA() const;

    float getB() const;

    float getC() const;

    float getD() const;

    QVector3D getNormalVector() const;
};


#endif //COORDINATE_PLANE_H

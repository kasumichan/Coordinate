//
// Created by liunianqi on 2021/8/29.
//

#ifndef COORDINATE_AXIS_H
#define COORDINATE_AXIS_H

#include "Point.h"
#include <QVector3D>


class Axis {
private:
    Point base;
    QVector3D x, y, z;
public:
    Axis();

    Axis(const Point &_base, const QVector3D &_x, const QVector3D &_y, const QVector3D &_z);

    Point getBase() const;

    void setBase(const Point &_point);

    void setX(const QVector3D &_x);

    void setY(const QVector3D &_y);

    void setZ(const QVector3D &_z);

    QVector3D getX() const;

    QVector3D getY() const;

    QVector3D getZ() const;


};


#endif //COORDINATE_AXIS_H

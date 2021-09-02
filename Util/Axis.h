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

    Axis(Point base, QVector3D x, QVector3D y, QVector3D z);

    Point getBase() const;

    QVector3D getX() const;

    QVector3D getY() const;

    QVector3D getZ() const;


};


#endif //COORDINATE_AXIS_H

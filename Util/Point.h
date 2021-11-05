//
// Created by liunianqi on 2021/8/27.
//

#ifndef COORDINATE_POINT_H
#define COORDINATE_POINT_H

#include <QVector3D>

class Plane;

class Point : public QVector3D {

private:
    int id{};

public:
    Point();

    Point(float _x, float _y, float _z, int _id);

    Point operator+(const Point &other) const;

    Point operator-(const Point &other) const;

    Point operator*(float a) const;

    Point operator/(float a) const;

    float distanceToPlane(const Plane &plane) const;

    void setID(int _id);

    int getID() const;
};


#endif //COORDINATE_POINT_H

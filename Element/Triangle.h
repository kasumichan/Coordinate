//
// Created by liunianqi on 2021/8/27.
//

#ifndef COORDINATE_TRIANGLE_H
#define COORDINATE_TRIANGLE_H

#include "Element.h"

class Triangle : public Element {
private:
public:
    Triangle();

    explicit Triangle(const QVector<Point> &_pointList);

    Triangle(const Triangle &_triangle);

    Point centroid() const override;

    float size() const override;

    Plane getPlane() const override;

    void setElementList();
};


#endif //COORDINATE_TRIANGLE_H

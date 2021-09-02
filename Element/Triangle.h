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

    Triangle(const QVector<Point> &pointList);

    Triangle(const Triangle &triangle);

    Point centroid() const override;

    float size() const override;

    Plane getPlane() const override;
};


#endif //COORDINATE_TRIANGLE_H

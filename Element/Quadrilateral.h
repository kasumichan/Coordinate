//
// Created by liunianqi on 2021/8/27.
//

#ifndef COORDINATE_QUADRILATERAL_H
#define COORDINATE_QUADRILATERAL_H

#include "Triangle.h"

class Quadrilateral : public Element {
private:
    Triangle tr1;
    Triangle tr2;

public:
    Quadrilateral();

    explicit Quadrilateral(const QVector<Point> &_pointList);

    Quadrilateral(const Quadrilateral &_quadrilateral);

    Point centroid() const override;

    float size() const override;

    Plane getPlane() const override;

    void setElementList();

    void setTriangle();
};


#endif //COORDINATE_QUADRILATERAL_H

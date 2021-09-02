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

    explicit Quadrilateral(const QVector<Point> &pointList);

    Quadrilateral(const Quadrilateral &quadrilateral);

    Point centroid() const override;

    float size() const override;

    Plane getPlane() const override;
};


#endif //COORDINATE_QUADRILATERAL_H

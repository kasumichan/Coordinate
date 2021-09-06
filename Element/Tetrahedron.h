//
// Created by liunianqi on 2021/8/27.
//

#ifndef COORDINATE_TETRAHEDRON_H
#define COORDINATE_TETRAHEDRON_H

#include "Element.h"

class Tetrahedron : public Element {
public:
    Tetrahedron();

    explicit Tetrahedron(const QVector<Point> &_pointList);

    Tetrahedron(const Tetrahedron &_tetrahedron);

    Point centroid() const override;

    float size() const override;

    Plane getPlane() const override;

    void setElementList();
};


#endif //COORDINATE_TETRAHEDRON_H

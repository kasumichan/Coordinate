//
// Created by liunianqi on 2021/8/27.
//

#ifndef COORDINATE_HEXAHEDRON_H
#define COORDINATE_HEXAHEDRON_H

#include "Element.h"

class Hexahedron : public Element {
public:
    Hexahedron();

    explicit Hexahedron(const QVector<Point> &pointList);

    Hexahedron(const Hexahedron &hexahedron);

    Point centroid() const override;

    float size() const override;

    Plane getPlane() const override;
};


#endif //COORDINATE_HEXAHEDRON_H

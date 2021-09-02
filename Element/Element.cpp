//
// Created by liunianqi on 2021/8/27.
//

#include "Element.h"

Element::Element() = default;

Element::Element(const QVector<Point> &pointList)
        : pointList(pointList) {
}

Element::Element(const Element &element) {
    pointList = element.pointList;
}

QVector<Point> Element::getPointList() const {
    return pointList;
}

void Element::setAxis(const Axis &_axis) {
    this->axis = _axis;
}


void Element::setID(int _id) {
    this->id = _id;
}

Axis Element::getAxis() const {
    return axis;
}

int Element::getID() const {
    return id;
}

QVector<QVector<int>> Element::getElementList() const {
    return elementList;
}

//
// Created by liunianqi on 2021/8/27.
//

#include "Element.h"

Element::Element() {
}

Element::Element(const QVector<Point> &pointList)
        : pointList(pointList) {
}

Element::Element(const Element &element) {
    pointList = element.pointList;
}

QVector<Point> Element::getPointList() const {
    return pointList;
}

void Element::setAxis(const Axis &axis) {
    this->axis = axis;
}

void Element::setID(const int id) {
    this->id = id;
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

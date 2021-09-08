//
// Created by liunianqi on 2021/8/27.
//

#include "Element.h"

Element::Element() = default;

Element::Element(const QVector<Point> &_pointList)
        : pointList(_pointList) {
}

Element::Element(const Element &_element) {
    pointList = _element.pointList;
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

void Element::setName(QString _name) {
    this->name = _name;
}

QString Element::getName() const {
    return name;
}

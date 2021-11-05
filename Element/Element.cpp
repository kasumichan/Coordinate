//
// Created by liunianqi on 2021/8/27.
//

#include "Element.h"

#include <utility>

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

void Element::setPointAxisList(const Axis &_axis) {
    this->pointAxisList.append(_axis);
}


void Element::setID(int _id) {
    this->id = _id;
}

QVector<Axis> Element::getPointAxisList() const {
    return pointAxisList;
}

int Element::getID() const {
    return id;
}

QVector<QVector<int>> Element::getElementList() const {
    return elementList;
}

void Element::setName(QString _name) {
    this->name = std::move(_name);
}

QString Element::getName() const {
    return name;
}

void Element::setCentroidAxis(const Axis &_axis) {
    this->centroidAxis = _axis;
}

Axis Element::getCentroidAxis() const {
    return centroidAxis;
}

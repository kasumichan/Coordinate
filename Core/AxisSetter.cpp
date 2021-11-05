//
// Created by dell on 2021/9/7.
//

#include "AxisSetter.h"

AxisSetter::AxisSetter(Element *_element, const SetAxisMethod &_setAxisMethod, const Axis &_axis) {
    this->element = _element;
    this->setAxisMethod = _setAxisMethod;
    this->axis = _axis;
}

QVector<Axis> AxisSetter::setAxis() {
    QVector<Axis> axisList;
    switch (setAxisMethod) {
        case SetAxisMethod::set : {
            for (auto &point: element->getPointList()) {
                Axis pointAxis{point, axis.getX(), axis.getY(), axis.getZ()};
                axisList.append(pointAxis);
                element->setPointAxisList(pointAxis);
            }
            element->setCentroidAxis(Axis{element->centroid(), axis.getX(), axis.getY(), axis.getZ()});
            break;
        }
        case SetAxisMethod::project : {
            QVector3D z = element->getPlane().getNormalVector();
            QVector3D x = (axis.getX() - QVector3D::dotProduct(axis.getX(), z) * z).normalized();
            QVector3D y = QVector3D::crossProduct(z, x).normalized();
            for (auto &point: element->getPointList()) {
                Axis pointAxis{point, x, y, z};
                axisList.append(pointAxis);
                element->setPointAxisList(pointAxis);
            }
            element->setCentroidAxis(Axis{element->centroid(), x, y, z});
            break;
        }
        default:
            break;
    }
    return axisList;
}

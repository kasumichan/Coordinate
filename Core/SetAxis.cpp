//
// Created by dell on 2021/9/7.
//

#include "SetAxis.h"

SetAxis::SetAxis(Element *_element, const SetAxisMethod &_setAxisMethod, const Axis &_axis) {
    Axis axis;
    switch (_setAxisMethod) {
        case SetAxisMethod::set : {
            axis = {_element->centroid(), _axis.getX(), _axis.getY(), _axis.getZ()};
            break;
        }
        case SetAxisMethod::project : {
            QVector3D z = _element->getPlane().getNormalVector();
            QVector3D x = (_axis.getX() - QVector3D::dotProduct(_axis.getX(), z) * z).normalized();
            QVector3D y = QVector3D::crossProduct(z, x).normalized();
            axis = {_element->centroid(), x, y, z};
        }
        default:
            break;
    }
    _element->setAxis(axis);
}

//
// Created by dell on 2021/9/7.
//

#ifndef COORDINATE_AXISSETTER_H
#define COORDINATE_AXISSETTER_H


#include "../Element/Element.h"
#include "../Enum/SetAxisMethod.h"

class AxisSetter {
private:
    Element *element;
    SetAxisMethod setAxisMethod;
    Axis axis;

public:
    AxisSetter(Element *_element, const SetAxisMethod &_setAxisMethod, const Axis &_axis);

    QVector<Axis> setAxis();
};


#endif //COORDINATE_AXISSETTER_H

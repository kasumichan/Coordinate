//
// Created by dell on 2021/9/7.
//

#ifndef COORDINATE_SETAXIS_H
#define COORDINATE_SETAXIS_H


#include "../Element/Element.h"
#include "../Enum/SetAxisMethod.h"

class SetAxis {
public:
    SetAxis(Element *_element, const SetAxisMethod &_setAxisMethod, const Axis &_axis);
};


#endif //COORDINATE_SETAXIS_H

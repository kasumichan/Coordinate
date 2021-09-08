//
// Created by dell on 2021/9/7.
//

#ifndef COORDINATE_CALCAXIS_H
#define COORDINATE_CALCAXIS_H

#include "../Enum/InputType.h"
#include "../Util/Axis.h"

class CalcAxis {
private:
    InputType inputType;
    float *coordinateData;
public:

    CalcAxis(InputType _inputType, float *coordinateData);

    Axis getAxis() const;

};


#endif //COORDINATE_CALCAXIS_H

//
// Created by dell on 2021/9/7.
//

#ifndef COORDINATE_AXISCALCULATOR_H
#define COORDINATE_AXISCALCULATOR_H

#include "../Enum/InputType.h"
#include "../Util/Axis.h"

class AxisCalculator {
private:
    InputType inputType;
    float *coordinateData;
public:

    AxisCalculator(InputType _inputType, float *coordinateData);

    Axis getAxis() const;

};


#endif //COORDINATE_AXISCALCULATOR_H

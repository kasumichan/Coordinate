//
// Created by dell on 2021/9/7.
//

#include "AxisCalculator.h"
#include <QVector>

AxisCalculator::AxisCalculator(InputType _inputType, float *_coordinateData) {
    this->inputType = _inputType;
    this->coordinateData = _coordinateData;
}

Axis AxisCalculator::getAxis() const {
    QVector3D x, y, z;
    x = {coordinateData[3] - coordinateData[0],
         coordinateData[4] - coordinateData[1],
         coordinateData[5] - coordinateData[2]};
    x.normalize();
    switch (inputType) {
        case InputType::threePoints : {
            y = {coordinateData[6] - coordinateData[0],
                 coordinateData[7] - coordinateData[1],
                 coordinateData[8] - coordinateData[2]};

            y = (y - x * QVector3D::dotProduct(x, y)).normalized();
            z = QVector3D::crossProduct(x, y).normalized();
            break;
        }
        case InputType::originAndNormalVector : {
            QVector<float> vec = {x[0], x[1], x[2]};
            auto smallest = std::min_element(vec.cbegin(), vec.cend(), [](float i, float j) { return abs(i) < abs(j); });
            int smallestIndex = std::distance(vec.cbegin(), smallest);
            QVector3D e{0, 0, 0};
            e[smallestIndex] = 1;

            y = QVector3D::crossProduct(e, x).normalized();
            z = QVector3D::crossProduct(x, y).normalized();
            break;
        }
        default:
            break;
    }
    return Axis{Point(), x, y, z};
}

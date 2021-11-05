//
// Created by dell on 2021/9/9.
//

#ifndef COORDINATE_AXISINFOWRITER_H
#define COORDINATE_AXISINFOWRITER_H

#include "../Element/Element.h"


class AxisInfoWriter {
private:
    QVector<Axis> axisList;
public:

    explicit AxisInfoWriter(const QVector<Axis> &_axisList);

    void write(const QString &fileName = "../Data/output.txt");

};


#endif //COORDINATE_AXISINFOWRITER_H

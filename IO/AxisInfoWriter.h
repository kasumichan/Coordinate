//
// Created by dell on 2021/9/9.
//

#ifndef COORDINATE_AXISINFOWRITER_H
#define COORDINATE_AXISINFOWRITER_H

#include "../Element/Element.h"


class AxisInfoWriter {
private:
    QVector<Element *> elementPtrList;
public:

    explicit AxisInfoWriter(const QVector<Element *> &_elementPtrList);

    void write(const QString &fileName = "../Data/output.txt");

};


#endif //COORDINATE_AXISINFOWRITER_H

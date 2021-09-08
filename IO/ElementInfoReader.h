//
// Created by liunianqi on 2021/8/29.
//

#ifndef COORDINATE_ELEMENTINFOREADER_H
#define COORDINATE_ELEMENTINFOREADER_H

#include <QVector3D>
#include <QVector>
#include <QMap>
#include <QFile>
#include "../Element/Element.h"
#include "../Enum/InputType.h"


class ElementInfoReader {
private:
    QVector<Element *> elementPtrList;
    QMap<std::string, QVector<double>> node;
public:
    void processLine(const std::string &line);

    void read(const QString &fileName = "../Data/input.txt");

    QVector<Element *> getElementPtrList() const;

};


#endif //COORDINATE_ELEMENTINFOREADER_H

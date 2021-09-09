//
// Created by dell on 2021/9/9.
//

#include "AxisInfoWriter.h"
#include <QFile>
#include <sstream>
#include <QDebug>

void AxisInfoWriter::write(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "error";
        return;
    }
    std::stringstream ss;
    ss << "ID  X   Y   Z   UX  UY  UZ  VX  VY  VZ  WX  WY  WZ " << std::endl;
    file.write(QString::fromStdString(ss.str()).toUtf8());
    for (auto &elementPointer: elementPtrList) {
        int id = elementPointer->getID();
        Axis axis = elementPointer->getAxis();
        Point base = axis.getBase();
        QVector3D x = axis.getX();
        QVector3D y = axis.getY();
        QVector3D z = axis.getZ();
        ss.clear();
        ss.str("");
        ss << id << " " << base.x() << " " << base.y() << " " << base.z() << " "
           << x[0] << " " << x[1] << " " << x[2] << " "
           << y[0] << " " << y[1] << " " << y[2] << " "
           << z[0] << " " << z[1] << " " << z[2] << std::endl;
        file.write(QString::fromStdString(ss.str()).toUtf8());
    }
    file.close();
}

AxisInfoWriter::AxisInfoWriter(const QVector<Element *> &_elementPtrList) {
    this->elementPtrList = _elementPtrList;
}

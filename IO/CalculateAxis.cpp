//
// Created by liunianqi on 2021/8/29.
//

#include "CalculateAxis.h"
#include "../Element/Triangle.h"
#include "../Element/Tetrahedron.h"
#include "../Element/Hexahedron.h"
#include "../UI/Canvas.h"
#include <sstream>
#include <QDebug>

CalculateAxis::CalculateAxis(float *coordinateData, int inputType) {
    this->coordinateData = coordinateData;
    this->inputType = inputType;
}

void CalculateAxis::input(QString fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "error";
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        processLine(line.toStdString());
    }
    file.close();
    addAxis();
}

void CalculateAxis::output(QString fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "error";
        return;
    }
    std::stringstream ss;
    ss << "ID  X   Y   Z   UX  UY  UZ  VX  VY  VZ  WX  WY  WZ " << std::endl;
    file.write(QString::fromStdString(ss.str()).toUtf8());
    for (auto elementPointer: elementPointerList) {
        int id = elementPointer->getID();
        Axis axis = elementPointer->getAxis();
        Point base = axis.getBase();
        QVector3D x = axis.getX();
        QVector3D y = axis.getY();
        QVector3D z = axis.getZ();
        std::stringstream ss;
        ss << id << " " << base.x() << " " << base.y() << " " << base.z() << " "
           << x[0] << " " << x[1] << " " << x[2] << " "
           << y[0] << " " << y[1] << " " << y[2] << " "
           << z[0] << " " << z[1] << " " << z[2] << std::endl;
        file.write(QString::fromStdString(ss.str()).toUtf8());
    }
    file.close();
}

void CalculateAxis::processLine(std::string line) {
    QVector<Point> pointList;
    QVector<std::string> res;
    std::string result;
    std::stringstream input;
    input << line;
    while (input >> result) {
        res.push_back(result);
    }
    if (res[0] == "NODE") {
        node[res[1]] = {atof(res[2].c_str()), atof(res[3].c_str()),
                        atof(res[4].c_str())};
    } else {
        if (res[0] == "SHELL") {
            for (int i = 2; i < 5; ++i) {
                pointList.push_back(Point(node[res[i]][0], node[res[i]][1], node[res[i]][2]));
            }
            elementPointerList.push_back(new Triangle(pointList));
        } else if (res[0] == "TETR4") {
            for (int i = 2; i < 6; ++i) {
                pointList.push_back(Point(node[res[i]][0], node[res[i]][1], node[res[i]][2]));
            }
            elementPointerList.push_back(new Tetrahedron(pointList));
        } else {
            for (int i = 2; i < 10; ++i) {
                pointList.push_back(Point(node[res[i]][0], node[res[i]][1], node[res[i]][2]));
            }
            elementPointerList.push_back(new Hexahedron(pointList));
        }
        elementPointerList[elementPointerList.size() - 1]->setID(atoi(res[1].c_str()));
    }

}

void CalculateAxis::addAxis() {
    for (auto elementPointer: elementPointerList) {
        switch (inputType) {
            case 0: {
                QVector3D x(coordinateData[3] - coordinateData[0],
                            coordinateData[4] - coordinateData[1],
                            coordinateData[5] - coordinateData[2]);
                x.normalize();
                QVector3D y(coordinateData[6] - coordinateData[0],
                            coordinateData[7] - coordinateData[1],
                            coordinateData[8] - coordinateData[2]);
                y.normalize();
                QVector3D z = QVector3D::crossProduct(x, y).normalized();
                elementPointer->setAxis(Axis(elementPointer->centroid(), x, y, z));
                break;
            }
            case 1: {
                QVector3D x(coordinateData[3] - coordinateData[0],
                            coordinateData[4] - coordinateData[1],
                            coordinateData[5] - coordinateData[2]);
                x.normalize();
                QVector3D z = elementPointer->getPlane().getNormalVector();
                QVector3D y = QVector3D::crossProduct(z, x).normalized();
                elementPointer->setAxis(Axis(elementPointer->centroid(), x, y, z));
                break;
            }
            case 2: {
                QVector3D x(coordinateData[3] - coordinateData[0],
                            coordinateData[4] - coordinateData[1],
                            coordinateData[5] - coordinateData[2]);
                QVector3D z = elementPointer->getPlane().getNormalVector();
                x = (x - QVector3D::dotProduct(x, z) * z).normalized();
                QVector3D y = QVector3D::crossProduct(z, x).normalized();
                elementPointer->setAxis(Axis(elementPointer->centroid(), x, y, z));
                break;
            }
            default:
                break;
        }
    }
}

void CalculateAxis::work() {
    input();
    output();
    Canvas *canvas = new Canvas(elementPointerList);
    canvas->show();
}
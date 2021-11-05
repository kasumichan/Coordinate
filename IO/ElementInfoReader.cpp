//
// Created by liunianqi on 2021/8/29.
//

#include "ElementInfoReader.h"
#include "../Element/Triangle.h"
#include "../Element/Tetrahedron.h"
#include "../Element/Hexahedron.h"
#include "../UI/Canvas.h"
#include <sstream>
#include <QDebug>


void ElementInfoReader::read(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "No such file";
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        processLine(line.toStdString());
    }
    file.close();
}


void ElementInfoReader::processLine(const std::string &line) {
    QVector<Point> pointList;
    QVector<std::string> res;
    std::string result;
    std::stringstream input;
    input << line;
    while (input >> result) {
        res.push_back(result);
    }
    if (res[0] == "NODE") {
        node[res[1]] = {std::stof(res[2]), std::stof(res[3]), std::stof(res[4]), std::stof(res[1])};
    } else {
        if (res[0] == "SHELL") {
            for (int i = 2; i < 5; ++i) {
                pointList.push_back(Point(node[res[i]][0], node[res[i]][1], node[res[i]][2], node[res[i]][3]));
            }
            elementPtrList.push_back(new Triangle(pointList));
        } else if (res[0] == "TETR4") {
            for (int i = 2; i < 6; ++i) {
                pointList.push_back(Point(node[res[i]][0], node[res[i]][1], node[res[i]][2], node[res[i]][3]));
            }
            elementPtrList.push_back(new Tetrahedron(pointList));
        } else {
            for (int i = 2; i < 10; ++i) {
                pointList.push_back(Point(node[res[i]][0], node[res[i]][1], node[res[i]][2], node[res[i]][3]));
            }
            elementPtrList.push_back(new Hexahedron(pointList));
        }
        elementPtrList[elementPtrList.size() - 1]->setID(std::stoi(res[1]));
        elementPtrList[elementPtrList.size() - 1]->setName(QString::fromStdString(res[0]));
    }

}

QVector<Element *> ElementInfoReader::getElementPtrList() const {
    return elementPtrList;
}



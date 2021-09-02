//
// Created by liunianqi on 2021/8/29.
//

#ifndef COORDINATE_CALCULATEAXIS_H
#define COORDINATE_CALCULATEAXIS_H

#include <QVector3D>
#include <QVector>
#include <QMap>
#include <QFile>
#include "../Element/Element.h"



class CalculateAxis {
private:
    int inputType;
    float *coordinateData;
    QVector<Element *> elementPointerList;
    QMap<std::string, QVector<double>> node;
public:
    CalculateAxis(float *coordinateData, int inputType);
    void work();
    void processLine(const std::string& line);
    void input(const QString& fileName="../Data/input.txt");
    void output(const QString& fileName="../Data/output.txt");
    void addAxis();
};


#endif //COORDINATE_CALCULATEAXIS_H

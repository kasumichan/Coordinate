//
// Created by liunianqi on 2021/8/27.
//

#ifndef COORDINATE_ELEMENT_H
#define COORDINATE_ELEMENT_H

#include "../Util/Plane.h"
#include "../Util/Axis.h"
#include <QVector>

class Element {
protected:
    QVector<Point> pointList;
    QVector<QVector<int>> elementList;
    QVector<Axis> pointAxisList;
    Axis centroidAxis;
    QString name;
    int id{};

public:
    Element();

    explicit Element(const QVector<Point> &_pointList);

    Element(const Element &_element);

    virtual float size() const = 0;

    virtual Point centroid() const = 0;

    virtual Plane getPlane() const = 0;

    QVector<Point> getPointList() const;

    void setPointAxisList(const Axis &_axis);

    QVector<Axis> getPointAxisList() const;

    void setCentroidAxis(const Axis &_axis);

    Axis getCentroidAxis() const;

    void setID(int _id);

    int getID() const;

    void setName(QString _name);

    QString getName() const;

    QVector<QVector<int>> getElementList() const;
};


#endif //COORDINATE_ELEMENT_H

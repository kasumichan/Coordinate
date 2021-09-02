//
// Created by liunianqi on 2021/8/28.
//

#ifndef COORDINATE_CANVAS_H
#define COORDINATE_CANVAS_H

#include <QWidget>
#include <QVector3D>
#include <QMouseEvent>
#include <QMatrix4x4>
#include <QPainter>
#include "../Element/Element.h"


class Canvas : public QWidget {
private:

    QVector<Element *> elementPointerList;
    QMatrix4x4 rotateMat;
    QPoint mousePos;
    int ratio;
    bool mousePressed;

public:
    Canvas(QVector<Element *> elementPointerList, QWidget *parent = nullptr);


protected:
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

    void wheelEvent(QWheelEvent *event);

    QPointF getPoint(const QVector3D &vt, int ratio) const;

    void draw(const QVector<Point> &vertexList, const QVector<QVector<int>> &elementList,
              const Axis &axis, QPainter &painter) const;
};


#endif //COORDINATE_CANVAS_H

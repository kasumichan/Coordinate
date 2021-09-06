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
    float ratio;
    bool mousePressed;

public:
    explicit Canvas(QVector<Element *> _elementPointerList, QWidget *parent = nullptr);


protected:
    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void wheelEvent(QWheelEvent *event) override;

    static QPointF getPoint(const QVector3D &vt, float ratio) ;

    void draw(const QVector<Point> &vertexList, const QVector<QVector<int>> &elementList,
              const Axis &axis, QPainter &painter) const;
};


#endif //COORDINATE_CANVAS_H

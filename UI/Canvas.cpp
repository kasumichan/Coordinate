//
// Created by liunianqi on 2021/8/28.
//

#include "Canvas.h"

#include <utility>

Canvas::Canvas(QVector<Element *> _elementPointerList, QWidget *parent)
        : QWidget(parent), elementPointerList(std::move(_elementPointerList)) {
    mousePressed = false;
    ratio = (width() > height() ? height() : width()) / 24;
}

void Canvas::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.fillRect(this->rect(), Qt::white);
    QPen pen(Qt::black);
    painter.setPen(pen);
    painter.drawRect(this->rect().adjusted(0, 0, -1, -1));

    for (auto &elementPointer: elementPointerList) {
        QVector<Point> vertexList = elementPointer->getPointList();
        QVector<QVector<int>> elementList = elementPointer->getElementList();
        Axis axis = elementPointer->getAxis();
        draw(vertexList, elementList, axis, painter);
    }
}

void Canvas::mousePressEvent(QMouseEvent *event) {
    mousePressed = true;
    mousePos = event->pos();
    QWidget::mousePressEvent(event);
}

void Canvas::mouseMoveEvent(QMouseEvent *event) {
    if (mousePressed) {
        const QPoint posOffset = event->pos() - mousePos;
        mousePos = event->pos();
        rotateMat.rotate(1.1f, QVector3D(0.5f * float(posOffset.y()),
                                         -0.5f * float(posOffset.x()), 0.0f));
        update();
    }
    QWidget::mouseMoveEvent(event);
}

void Canvas::mouseReleaseEvent(QMouseEvent *event) {
    mousePressed = false;
    QWidget::mouseReleaseEvent(event);
}

void Canvas::wheelEvent(QWheelEvent *event) {
    QPoint scroll = event->angleDelta();
    if (scroll.y() > 0)
        ratio *= 1.1;
    else
        ratio *= 0.9;
    update();
    QWidget::wheelEvent(event);
}

void Canvas::draw(const QVector<Point> &vertexList, const QVector<QVector<int>> &elementList,
                  const Axis &axis, QPainter &painter) const {
    QVector<QVector3D> mVertexList;
    QVector<int> vertexMaxList;
    float vertexMaxValue;
    QVector3D base = axis.getBase();
    QVector3D x_coord = base + axis.getX();
    QVector3D y_coord = base + axis.getY();
    QVector3D z_coord = base + axis.getZ();
    base = base * rotateMat;
    x_coord = x_coord * rotateMat;
    y_coord = y_coord * rotateMat;
    z_coord = z_coord * rotateMat;

    for (int i = 0; i < vertexList.count(); ++i) {
        QVector3D vertex = vertexList[i] * rotateMat;
        mVertexList.push_back(vertex);
        if (i == 0) {
            vertexMaxList.push_back(0);
            vertexMaxValue = vertex.z();
        } else {
            if (vertex.z() > vertexMaxValue) {
                vertexMaxList.clear();
                vertexMaxList.push_back(i);
                vertexMaxValue = vertex.z();
            } else if (abs(vertex.z() - vertexMaxValue) < 1e-7) {
                vertexMaxList.push_back(i);
            }
        }
    }

    painter.save();
    painter.translate(width() / 2, height() / 2);

    QVector<QPainterPath> elementPathList;
    QVector<float> elementZValues;
    QVector<QPointF> elementZPoints;
    QVector<int> elementFrontList;


    QLineF x_axis(getPoint(base, ratio), getPoint(x_coord, ratio));
    QLineF y_axis(getPoint(base, ratio), getPoint(y_coord, ratio));
    QLineF z_axis(getPoint(base, ratio), getPoint(z_coord, ratio));

    for (int i = 0; i < elementList.count(); ++i) {
        QVector<QVector3D> v_list;
        QVector3D centroid;
        for (int j = 0; j < elementList[i].count(); ++j) {
            centroid += mVertexList[elementList[i][j]];
            v_list.push_back(mVertexList[elementList[i][j]]);
        }
        centroid /= float(v_list.count());
        QPainterPath element_path;
        element_path.moveTo(getPoint(v_list[0], ratio));
        for (int j = 1; j < v_list.count(); ++j) {
            element_path.lineTo(getPoint(v_list[j], ratio));
        }
        element_path.closeSubpath();

        bool is_front = true;
        for (auto &vertex_index: vertexMaxList) {
            if (!elementList[i].contains(vertex_index)) {
                is_front = false;
                break;
            }
        }
        if (is_front) {
            elementFrontList.push_back(i);
        }
        elementPathList.push_back(element_path);
        elementZValues.push_back(centroid.z());
        elementZPoints.push_back((getPoint(centroid, ratio)));
    }

    QVector<int> element_front_remove;
    for (int i = 0; i < elementFrontList.count(); ++i) {
        for (int j = 0; j < elementFrontList.count(); ++j) {
            if (i == j)
                continue;
            int index_i = elementFrontList[i];
            int index_j = elementFrontList[j];
            if (elementZValues[index_i] > elementZValues[index_j] &&
                elementPathList[index_i].contains(elementZPoints[index_j])) {
                element_front_remove.push_back(index_j);
            }
        }
    }
    for (auto &index: element_front_remove) {
        elementFrontList.removeOne(index);
    }

    painter.setRenderHint(QPainter::Antialiasing, true);

    for (auto &index: elementFrontList) {
        painter.fillPath(elementPathList[index], Qt::blue);
    }

    painter.setPen(QPen(Qt::white, 1, Qt::DashLine));
    for (int i = 0; i < elementPathList.count(); ++i) {
        if (elementFrontList.contains(i))
            continue;
        painter.drawPath(elementPathList[i]);
    }

    painter.setPen(QPen(Qt::black, 2));
    for (auto &index: elementFrontList) {
        painter.drawPath(elementPathList[index]);
    }
    painter.setPen(QPen(Qt::red, 2));
    painter.drawLine(x_axis);
    painter.drawLine(y_axis);
    painter.drawLine(z_axis);
    painter.restore();

}


QPointF Canvas::getPoint(const QVector3D &vt, float ratio) {
    return QPointF{vt.x() * ratio, vt.y() * ratio};
}
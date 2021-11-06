//
// Created by liunianqi on 2021/8/28.
//

#ifndef COORDINATE_MAINWINDOW_H
#define COORDINATE_MAINWINDOW_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QTableWidget>
#include <QLabel>
#include <set>
#include "../Element/Element.h"
#include "../Enum/InputType.h"
#include "../Enum/SetAxisMethod.h"
#include "Canvas.h"

class MainWindow : public QWidget {

Q_OBJECT
private:
    int currentRowIndex;
    Axis axis;
    QVector<Axis> axisSet;
    QVector<Element *> elementPtrList;
    Canvas *canvas;

    InputType inputType;
    SetAxisMethod setAxisMethod;


    QTableWidget *elementInfoTable;

    QPushButton *readBtn;
    QPushButton *plotBtn;

    QLabel *inputTypeLabel;
    QLabel *methodTypeLabel;

    QComboBox *inputTypeBox;
    QComboBox *methodTypeBox;

    QPushButton *inputBtn;
    QPushButton *confirmBtn;
    QPushButton *outputBtn;

public:
    explicit MainWindow(QWidget *parent = nullptr);

    void input();

    void initUI();

    void initLayout();

    void updateTableInfo();

    void addListener();



private slots:

    void on_inputTypeBox_currentIndexChanged(int index);

    void on_methodTypeBox_currentIndexChanged(int index);

    void on_readBtn_clicked();

    void on_plotBtn_clicked();

    void on_inputBtn_clicked();

    void on_confirmBtn_clicked();

    void on_elementInfoTable_clicked();

    void on_outputBtn_clicked();

    void updateData(float *data);

};


#endif //COORDINATE_MAINWINDOW_H
//
// Created by liunianqi on 2021/8/28.
//

#ifndef COORDINATE_MAINWINDOW_H
#define COORDINATE_MAINWINDOW_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QTableWidget>
#include "../Element/Element.h"
#include "../Enum/InputType.h"

class MainWindow : public QWidget {

Q_OBJECT
private:

    int currentRowIndex;
    Axis axis;
    QVector<Element *> elementPtrList;

    InputType inputType;
    QComboBox *inputTypeBox;
    QComboBox *methodTypeBox;
    QPushButton *inputBtn;
    QPushButton *readBtn;
    QPushButton *plotBtn;
    QTableWidget *elementInfoTable;
    QPushButton *confirmBtn;
    QPushButton *cancelBtn;

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

    void updateData(float *data);

};


#endif //COORDINATE_MAINWINDOW_H
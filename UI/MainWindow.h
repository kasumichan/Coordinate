//
// Created by liunianqi on 2021/8/28.
//

#ifndef COORDINATE_MAINWINDOW_H
#define COORDINATE_MAINWINDOW_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>

class MainWindow : public QWidget {

Q_OBJECT
private:

    float *coordinateData;
    int inputType;
    QComboBox *inputTypeBox;
    QPushButton *inputBtn;
    QPushButton *confirmBtn;

public:
    MainWindow(QWidget *parent = nullptr);
    void initUI();
    void initLayout();
    void addListener();


private slots:

    void on_inputType_currentIndexChanged(int index);

    void on_input_clicked();

    void on_confirm_clicked();

    void updateData(float *data);

};


#endif //COORDINATE_MAINWINDOW_H
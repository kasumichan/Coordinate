//
// Created by liunianqi on 2021/8/28.
//

#include "MainWindow.h"
#include "InputDialog.h"
#include "../IO/CalculateAxis.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
        : QWidget(parent) {
    coordinateData = new float[9];
    inputType = 0;
    inputTypeBox = new QComboBox(this);
    inputBtn = new QPushButton(this);
    confirmBtn = new QPushButton(this);
    initUI();
    initLayout();
    addListener();
}

void MainWindow::initUI() {
    setWindowTitle("Main");
    resize(600, 200);
    inputBtn->setText("Input Data");
    confirmBtn->setText("Confirm");
    inputTypeBox->addItem("Three Points");
    inputTypeBox->addItem("Origin & Normal Vector");
    inputTypeBox->addItem("Projection");
}

void MainWindow::initLayout() {
    QVBoxLayout *vBoxLayout = new QVBoxLayout();
    vBoxLayout->addWidget(inputTypeBox);
    vBoxLayout->addWidget(inputBtn);
    vBoxLayout->addWidget(confirmBtn);
    setLayout(vBoxLayout);
}

void MainWindow::addListener() {
    connect(inputBtn, SIGNAL(clicked()), this, SLOT(on_input_clicked()));
    connect(inputTypeBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(on_inputType_currentIndexChanged(int)));
    connect(confirmBtn, SIGNAL(clicked()), this, SLOT(on_confirm_clicked()));
}

void MainWindow::on_inputType_currentIndexChanged(int index) {
    inputType = index;
}

void MainWindow::on_input_clicked() {
    InputDialog *dialog;
    if (inputType == 0) {
        dialog = new InputDialog(3);
    } else {
        dialog = new InputDialog(2);
    }
    connect(dialog, SIGNAL(sendData(float * )), this, SLOT(updateData(float * )));
    dialog->show();
}

void MainWindow::on_confirm_clicked() {
    CalculateAxis calculateAxis(coordinateData, inputType);
    calculateAxis.work();

}


void MainWindow::updateData(float *data) {
    coordinateData = data;
}
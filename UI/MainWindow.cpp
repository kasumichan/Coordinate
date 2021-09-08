//
// Created by liunianqi on 2021/8/28.
//

#include "MainWindow.h"
#include "InputDialog.h"
#include "../IO/ElementInfoReader.h"
#include "../Core/CalcAxis.h"
#include "../Core/SetAxis.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
        : QWidget(parent) {
    currentRowIndex = -1;
    inputType = InputType::threePoints;
    elementInfoTable = new QTableWidget(this);
    readBtn = new QPushButton(this);
    plotBtn = new QPushButton(this);
    inputTypeBox = new QComboBox(this);
    methodTypeBox = new QComboBox(this);
    inputBtn = new QPushButton(this);
    confirmBtn = new QPushButton(this);
    initUI();
    updateTableInfo();
    initLayout();
    addListener();
}

void MainWindow::initUI() {
    setWindowTitle("Main");
    resize(1960, 1280);

    readBtn->setText("Read");
    plotBtn->setText("Plot");
    inputBtn->setText("Input Data");
    confirmBtn->setText("Confirm");

    inputTypeBox->addItem("Three Points");
    inputTypeBox->addItem("Origin & Normal Vector");
    methodTypeBox->addItem("Set");
    methodTypeBox->addItem("Projection");

    QStringList headerText;
    headerText << "Element" << "ID" << "Method" << "Axis";
    elementInfoTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    elementInfoTable->setSelectionMode(QAbstractItemView::SingleSelection);
    elementInfoTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    elementInfoTable->setRowCount(elementPtrList.size());
    elementInfoTable->setColumnCount(headerText.size());
    elementInfoTable->setHorizontalHeaderLabels(headerText);
    elementInfoTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    elementInfoTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    elementInfoTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    elementInfoTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
}

void MainWindow::initLayout() {
    auto *vBoxLayout = new QVBoxLayout();
    vBoxLayout->addWidget(elementInfoTable);
    vBoxLayout->addWidget(readBtn);
    vBoxLayout->addWidget(plotBtn);

    vBoxLayout->addWidget(inputTypeBox);
    vBoxLayout->addWidget(methodTypeBox);

    vBoxLayout->addWidget(inputBtn);
    vBoxLayout->addWidget(confirmBtn);
    setLayout(vBoxLayout);
}

void MainWindow::addListener() {
    connect(elementInfoTable, SIGNAL(cellClicked(int, int)),
            this, SLOT(on_elementInfoTable_clicked()));
    connect(inputTypeBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(on_inputTypeBox_currentIndexChanged(int)));
    connect(methodTypeBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(on_methodTypeBox_currentIndexChanged(int)));
    connect(plotBtn, SIGNAL(clicked(bool)), this, SLOT(on_plotBtn_clicked()));
    connect(readBtn, SIGNAL(clicked(bool)), this, SLOT(on_readBtn_clicked()));
    connect(inputBtn, SIGNAL(clicked(bool)), this, SLOT(on_inputBtn_clicked()));
    connect(confirmBtn, SIGNAL(clicked(bool)), this, SLOT(on_confirmBtn_clicked()));

}

void MainWindow::on_inputTypeBox_currentIndexChanged(int index) {
    switch (index) {
        case 0:
            inputType = InputType::threePoints;
            break;
        case 1:
            inputType = InputType::originAndNormalVector;
            break;
        default:
            break;
    }
}

void MainWindow::on_inputBtn_clicked() {
    InputDialog *dialog;
    switch (inputType) {
        case InputType::threePoints:
            dialog = new InputDialog(3);
            break;
        case InputType::originAndNormalVector:
            dialog = new InputDialog(2);
            break;
        default:
            break;
    }
    connect(dialog, SIGNAL(sendData(float * )), this, SLOT(updateData(float * )));
    dialog->show();
}

void MainWindow::on_confirmBtn_clicked() {
    //    ElementInfoReader calculateAxis(coordinateData, inputType);
    //    calculateAxis.work();
    SetAxisMethod setAxisMethod;
    if (elementInfoTable->item(currentRowIndex, 2)->text() == "Set") {
        setAxisMethod = SetAxisMethod::set;
    } else {
        setAxisMethod = SetAxisMethod::project;
    }
    SetAxis{elementPtrList.at(currentRowIndex), setAxisMethod, axis};
    elementInfoTable->setItem(currentRowIndex, 3,
                              new QTableWidgetItem(elementPtrList.at(currentRowIndex)->getAxis().toString()));
}


void MainWindow::updateData(float *data) {
    CalcAxis calcAxis(inputType, data);
    axis = calcAxis.getAxis();
}

void MainWindow::input() {
    ElementInfoReader reader;
    reader.read();
    elementPtrList = reader.getElementPtrList();
}

void MainWindow::updateTableInfo() {
    for (int i = 0; i < elementPtrList.size(); ++i) {
        elementInfoTable->setItem(i, 0, new QTableWidgetItem(elementPtrList[i]->getName()));
        elementInfoTable->setItem(i, 1, new QTableWidgetItem(QString::number(elementPtrList[i]->getID())));
    }

}

void MainWindow::on_elementInfoTable_clicked() {
    currentRowIndex = elementInfoTable->selectedItems().front()->row();
}

void MainWindow::on_methodTypeBox_currentIndexChanged(int index) {
    switch (index) {
        case 0:
            elementInfoTable->setItem(currentRowIndex, 2, new QTableWidgetItem("Set"));
            break;
        case 1:
            elementInfoTable->setItem(currentRowIndex, 2, new QTableWidgetItem("Project"));
            break;
        default:
            break;
    }
}

void MainWindow::on_readBtn_clicked() {
    input();
    updateTableInfo();
}

void MainWindow::on_plotBtn_clicked() {

}


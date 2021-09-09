//
// Created by liunianqi on 2021/8/28.
//

#include "MainWindow.h"
#include "InputDialog.h"
#include "../IO/ElementInfoReader.h"
#include "../Core/CalcAxis.h"
#include "../Core/SetAxis.h"
#include "../IO/AxisInfoWriter.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
        : QWidget(parent) {
    currentRowIndex = -1;
    inputType = InputType::threePoints;
    setAxisMethod = SetAxisMethod::set;
    canvas = new Canvas(elementPtrList);

    elementInfoTable = new QTableWidget(this);

    readBtn = new QPushButton(this);
    plotBtn = new QPushButton(this);

    inputTypeLabel = new QLabel(this);
    methodTypeLabel = new QLabel(this);

    inputTypeBox = new QComboBox(this);
    methodTypeBox = new QComboBox(this);

    inputBtn = new QPushButton(this);
    confirmBtn = new QPushButton(this);

    initUI();
    initLayout();
    addListener();
}

void MainWindow::initUI() {
    this->setWindowTitle("Main");
    this->resize(1920, 1080);

    QStringList headerText;
    headerText << "Element" << "ID" << "Method" << "Axis";
    elementInfoTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    elementInfoTable->setSelectionMode(QAbstractItemView::SingleSelection);
    elementInfoTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    elementInfoTable->setColumnCount(headerText.size());
    elementInfoTable->setHorizontalHeaderLabels(headerText);
    elementInfoTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    elementInfoTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
    elementInfoTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Interactive);
    elementInfoTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Interactive);

    readBtn->setText("Read");
    plotBtn->setText("Plot");

    inputTypeLabel->setText("Setting");
    methodTypeLabel->setText("Method");

    inputTypeBox->addItem("Three Points");
    inputTypeBox->addItem("Origin & Normal Vector");
    methodTypeBox->addItem("Set");
    methodTypeBox->addItem("Projection");

    inputBtn->setText("Input Data");
    confirmBtn->setText("Apply");

}

void MainWindow::initLayout() {
    auto *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(elementInfoTable);

    auto *topLayout = new QHBoxLayout();
    topLayout->addWidget(readBtn);
    topLayout->addWidget(plotBtn);

    mainLayout->addLayout(topLayout);

    auto *comboBoxLayout = new QHBoxLayout();
    comboBoxLayout->addWidget(methodTypeLabel);
    comboBoxLayout->addWidget(methodTypeBox);
    comboBoxLayout->addWidget(inputTypeLabel);
    comboBoxLayout->addWidget(inputTypeBox);

    mainLayout->addLayout(comboBoxLayout);

    auto *bottomLayout = new QHBoxLayout();
    bottomLayout->addWidget(inputBtn);
    bottomLayout->addWidget(confirmBtn);

    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);
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

void MainWindow::on_methodTypeBox_currentIndexChanged(int index) {
    switch (index) {
        case 0:
            setAxisMethod = SetAxisMethod::set;
            break;
        case 1:
            setAxisMethod = SetAxisMethod::project;
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
    if (currentRowIndex == -1) {
        QMessageBox::critical(nullptr, "Error", "You have not selected any element",
                              QMessageBox::Ok | QMessageBox::Default, QMessageBox::Cancel | QMessageBox::Escape, 0);
        return;
    }

    switch (setAxisMethod) {
        case SetAxisMethod::set : {
            elementInfoTable->setItem(currentRowIndex, 2, new QTableWidgetItem("Set"));
            break;
        }
        case SetAxisMethod::project : {
            elementInfoTable->setItem(currentRowIndex, 2, new QTableWidgetItem("Project"));
            break;
        }
        default:
            break;
    }

    SetAxis{elementPtrList.at(currentRowIndex), setAxisMethod, axis};
    elementInfoTable->setItem(currentRowIndex, 3,
                              new QTableWidgetItem(elementPtrList.at(currentRowIndex)->getAxis().toString()));
    AxisInfoWriter axisInfoWriter(elementPtrList);
    axisInfoWriter.write();

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
    elementInfoTable->setRowCount(elementPtrList.size());
    for (int i = 0; i < elementPtrList.size(); ++i) {
        elementInfoTable->setItem(i, 0, new QTableWidgetItem(elementPtrList[i]->getName()));
        elementInfoTable->setItem(i, 1, new QTableWidgetItem(QString::number(elementPtrList[i]->getID())));
    }

}

void MainWindow::on_elementInfoTable_clicked() {
    currentRowIndex = elementInfoTable->selectedItems().front()->row();
}


void MainWindow::on_readBtn_clicked() {
    input();
    updateTableInfo();
}

void MainWindow::on_plotBtn_clicked() {
    canvas->setElementPtrList(elementPtrList);
    canvas->show();
}


//
// Created by liunianqi on 2021/8/28.
//

#include <QPushButton>
#include <QGridLayout>
#include <QValidator>
#include "InputDialog.h"


InputDialog::InputDialog(int _dim, QWidget *parent)
        : QDialog(parent), dimension(_dim) {
    numLabel = new QLabel *[dimension];
    charLabel = new QLabel *[3];
    edit = new QLineEdit *[3 * dimension];
    ok = new QPushButton(this);
    cancel = new QPushButton(this);
    initUI();
    initLayout();
    addListener();
}

void InputDialog::initUI() {
    for (int i = 0; i < dimension; ++i) {
        numLabel[i] = new QLabel(this);
        numLabel[i]->setText(QString::number(i + 1));
    }

    auto* qDoubleValidator = new QDoubleValidator(-100, 100, 5);
    qDoubleValidator->setNotation(QDoubleValidator::StandardNotation);
    for (int i = 0; i < 3 * dimension; ++i) {
        edit[i] = new QLineEdit(this);
        edit[i]->setValidator(qDoubleValidator);
    }

    for (int i = 0; i < 3; ++i) {
        charLabel[i] = new QLabel(this);
        charLabel[i]->setText(QString('X' + i));
    }

    ok->setText("Confirm");
    cancel->setText("Cancel");
}

void InputDialog::initLayout() {
    setWindowTitle("Input Coordinate");
    resize(600, 50 * dimension);
    auto *layout = new QGridLayout(this);
    for (int i = 0; i < 3; ++i)
        layout->addWidget(charLabel[i], 1, i + 2);
    for (int i = 0; i < dimension; ++i) {
        layout->addWidget(numLabel[i], i + 2, 1);
        for (int j = 0; j < 3; ++j) {
            layout->addWidget(edit[i * 3 + j], i + 2, j + 2);
        }
    }
    layout->addWidget(ok, dimension + 2, 2);
    layout->addWidget(cancel, dimension + 2, 4);
    setLayout(layout);
}

void InputDialog::addListener() {
    connect(ok, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancel, SIGNAL(clicked()), this, SLOT(reject()));
}

void InputDialog::accept() {
    auto *data = new float[3 * dimension];
    for (int i = 0; i < 3 * dimension; ++i) {
        data[i] = edit[i]->text().toDouble();
    }
    emit sendData(data);
    QDialog::accept();
}

void InputDialog::reject() {
    QDialog::reject();
}
//
// Created by liunianqi on 2021/8/28.
//

#ifndef COORDINATE_INPUTDIALOG_H
#define COORDINATE_INPUTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>

class InputDialog : public QDialog {

Q_OBJECT

private:
    int dimension;
    QLabel **numLabel;
    QLabel **charLabel;
    QLineEdit **edit;
    QPushButton *ok;
    QPushButton *cancel;

public:
    InputDialog(int dim, QWidget *parent = nullptr);

    void initUI();

    void initLayout();

    void addListener();

private slots:

    void accept();

    void reject();

signals:

    void sendData(float *data);
};


#endif //COORDINATE_INPUTDIALOG_H

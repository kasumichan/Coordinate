#include "./UI/MainWindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    std::vector<Element *> b;
//    ElementInfoTable w(b);
//    w.show();
    MainWindow w;
    w.show();

    return a.exec();
}

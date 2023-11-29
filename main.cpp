#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow mainwindow;
    mainwindow.show();
    mainwindow.setWindowTitle("任务三");
    return QApplication::exec();
}

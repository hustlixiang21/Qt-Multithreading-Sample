#ifndef MISSION3_MAINWINDOW_H
#define MISSION3_MAINWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include "CircleThread.h"
#include "SquareThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

    void paintEvent(QPaintEvent *event) override;

private slots:
    void on_startpaint_clicked();

private:
    Ui::mainwindow *ui;
    // 画圆线程对象
    CircleThread *circleThread = nullptr;
    QVector<QPoint> circlePoints;
    // 画方线程对象
    SquareThread *squareThread = nullptr;
    QVector<QPoint> squarePoints;

};


#endif //MISSION3_MAINWINDOW_H

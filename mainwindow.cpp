#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);
    // 创建画圆的线程
    circleThread = new CircleThread(this, QPoint(width() / 4, height() / 2 - height() / 10), qMin(width() / 2, height()) / 2 - 50);
    // 连接画圆线程的数据发送信号和主线程的数据接收槽函数
    connect(circleThread, &CircleThread::circlePoint, this, [&](const QPoint &pt) {
        circlePoints.append(pt);
        // 更新调用paintEvent
        update();
    });
    // 创建画方的线程
    squareThread = new SquareThread(this, QPoint(width() * 3 / 5 , height() / 5 - height() / 35), qMin(width() / 2, height() / 2) - 20) ;
    // 连接画方线程的数据发送信号和主线程的数据接收槽函数
    connect(squareThread, &SquareThread::squarePoint, this, [&](const QPoint &pt) {
        squarePoints.append(pt);
        // 更新调用paintEvent
        update();
    });
    // 连接按钮的点击信号和画圆线程的启动槽函数
    connect(ui->startpaint, &QPushButton::clicked, this, &MainWindow::on_startpaint_clicked);
}

MainWindow::~MainWindow() {
    if (circleThread && circleThread->isRunning()) {
        circleThread->requestInterruption(); // 如果CircleThread支持中断
        circleThread->quit(); // 请求线程退出
        circleThread->wait(); // 等待线程结束
        delete circleThread; // 删除线程对象
        circleThread = nullptr;
    }
    if (squareThread && squareThread->isRunning()) {
        squareThread->requestInterruption(); // 如果SquareThread支持中断
        squareThread->quit(); // 请求线程退出
        squareThread->wait(); // 等待线程结束
        delete squareThread; // 删除线程对象
        squareThread = nullptr;
    }
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setPen(Qt::blue);
    // 画出所有圆的点
    for (const QPoint &pt : circlePoints) {
        painter.drawPoint(pt);
    }
    // 连接点画圆（可选）
    if (circlePoints.size() > 1) {
        painter.setPen(Qt::red);
        painter.drawPolyline(circlePoints.constData(), circlePoints.size());
    }

    // 画出所有方的点
    for (const QPoint &pt : squarePoints) {
        painter.drawPoint(pt);
    }
    // 连接点画方（可选）
    if (squarePoints.size() > 1) {
        painter.setPen(Qt::blue);
        painter.drawPolyline(squarePoints.constData(), squarePoints.size());
    }
}

void MainWindow::on_startpaint_clicked() {
    // 启动画圆线程
    circleThread->start();
    // 启动画方线程
    squareThread->start();
}
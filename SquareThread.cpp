#include "SquareThread.h"

SquareThread::SquareThread(QObject *parent, const QPoint &topLeft, int sideLength)
        : QThread(parent), topLeft(topLeft), sideLength(sideLength) {
}

SquareThread::~SquareThread() {
    wait();
}

void SquareThread::run() {
    // 方形的四个顶点
    QPoint points[4] = {
            topLeft,
            QPoint(topLeft.x() + sideLength, topLeft.y()),
            QPoint(topLeft.x() + sideLength, topLeft.y() + sideLength),
            QPoint(topLeft.x(), topLeft.y() + sideLength)
    };

    // 沿着每条边绘制点
    for (int i = 0; i < 4; ++i) {
        QPoint start = points[i];
        QPoint end = points[(i + 1) % 4];
        int dx = (end.x() - start.x()) / sideLength;
        int dy = (end.y() - start.y()) / sideLength;

        for (int j = 0; j <= sideLength; ++j) {
            int x = start.x() + dx * j;
            int y = start.y() + dy * j;
            emit squarePoint(QPoint(x, y));
            QThread::msleep(5); // 控制绘制速度
        }
    }
}
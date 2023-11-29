#include "CircleThread.h"

CircleThread::~CircleThread() {
    wait();
}

CircleThread::CircleThread(QObject *parent, const QPoint &center, int radius)
        : QThread(parent), center(center), radius(radius) {
}

void CircleThread::process() {
    double radianIncrement = 2 * (M_PI / 180.0); // 每次增加的弧度（1度）

    // 计算新点的位置，这里以圆的参数方程为例
    int centerX = center.x();
    int centerY = center.y();
    int x = centerX + static_cast<int>(radius * cos(circleAngle));
    int y = centerY + static_cast<int>(radius * sin(circleAngle));
    circleAngle += radianIncrement;

    // 发送新点的位置
    emit circlePoint(QPoint(x, y));
}

void CircleThread::run() {
    while (!isInterruptionRequested()) {
        process();
        if (circleAngle >= 2 * M_PI) break;
        msleep(62);
    }
}

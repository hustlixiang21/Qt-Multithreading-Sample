#ifndef MISSION3_CIRCLETHREAD_H
#define MISSION3_CIRCLETHREAD_H

#include <QThread>
#include <Qpoint.h>

class CircleThread : public QThread{
    Q_OBJECT
public:
    QPoint center;
    int radius;
    double circleAngle = 0;

    explicit CircleThread(QObject *parent = nullptr, const QPoint &center = QPoint(), int radius = 0);

    ~CircleThread() override ;

public slots:
    // 用于处理点的数据
    void process();

protected:
    void run() override;

signals:
    // 用于发送点的数据
    void circlePoint(const QPoint &pt);
};

#endif //MISSION3_CIRCLETHREAD_H

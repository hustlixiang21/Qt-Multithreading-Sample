#ifndef MISSION3_SQUARETHREAD_H
#define MISSION3_SQUARETHREAD_H


#include <QThread>
#include <Qpoint.h>

class SquareThread : public QThread{
    Q_OBJECT
public:
    explicit SquareThread(QObject *parent = nullptr, const QPoint &topLeft = QPoint(), int sideLength = 0);
    ~SquareThread() override;

signals:
    void squarePoint(const QPoint &pt);

protected:
    void run() override;

private:
    QPoint topLeft;
    int sideLength;
};


#endif //MISSION3_SQUARETHREAD_H

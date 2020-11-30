#include "finishtask.h"

FinishTask::FinishTask(QObject *parent) : QObject(parent)
{
}

void FinishTask::doJob(int count)
{
    timer->deleteLater();
    qDebug() << count;
    count++;
    timer = new QTimer();
    connect(timer, &QTimer::timeout, [=]() {
        doJob(count);
    });
    timer->setInterval(1000*count);
    timer->setSingleShot(1);
    timer->start();
}

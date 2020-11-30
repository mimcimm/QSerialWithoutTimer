#ifndef FINISHTASK_H
#define FINISHTASK_H

#include <QObject>
#include <QDebug>
#include <QTimer>

class FinishTask : public QObject
{
    Q_OBJECT
public:
    explicit FinishTask(QObject *parent = nullptr);
//int count =0;
//signals:

    QTimer * timer ;

   public slots:
    void doJob(int count);
};

#endif // FINISHTASK_H

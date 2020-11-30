#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QSerialPort>
#include <QDebug>

class SerialPort : public QObject
{
    Q_OBJECT
public:
    SerialPort(int id);
    QSerialPort *serial;
    int id;

signals:

public slots:
    void initializeSerialPort();
};


//*****
#include<QThread>
class EvtLoopTicker : public QObject
{
    Q_OBJECT
public:
    int counttt=0;
    EvtLoopTicker(QObject *pParent = nullptr)
        : QObject(pParent)
    {
    }
public slots:
    void launch() {
        tickNext();
    }
private slots:
    void tick(){
        qDebug() << "tick";
        QThread::sleep(1);
        tickNext();
        counttt++;
        qDebug() << counttt;
    }
private:
    void tickNext(){
        QMetaObject::invokeMethod(this, "tick", Qt::QueuedConnection);
    }
};

#endif // SERIALPORT_H

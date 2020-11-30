#ifndef RENDEREVENT_H
#define RENDEREVENT_H

#include <QObject>
#include <QDebug>
#include <QEvent>
#include <QApplication>
#include<QThread>

class RenderEvent : public QObject
{
    Q_OBJECT
public:
    int counttt=0;
    QThread *ttr;
    RenderEvent(QThread *tret, QObject *pParent = nullptr)
        : QObject(pParent){
        //        setParent(NULL);
        //        moveToThread(tret);
        //        ttr= tret;
        update();
    }

public slots:
    void update() {
        updateLater();
        qDebug() << "aaa";
        QThread::sleep(1);
    }

    void updateLater() {
        qDebug() << "bbb";
        if (!m_updatePending) {
            qDebug() << "ccc";
            m_updatePending = true;
            QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest));
        }
    }

protected:
    bool m_updatePending;
    bool event(QEvent *event){
        qDebug() << "ddd";
        if (event->type() == QEvent::UpdateRequest){
            qDebug() << "eeee";
            m_updatePending = false;
            update();
            return true;
        }else{
            qDebug() << "fff";
            return QObject::event(event);
        }
    }
};
#endif // RENDEREVENT_H

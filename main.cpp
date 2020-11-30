#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QTimer>

#include "serialport.h"
#include "renderevent.h"
#include "finishtask.h"

EvtLoopTicker *ticker;
bool counter = true;
void pulse(){
    qDebug()<< "count" << counter;
    if(counter){
        ticker->deleteLater();
        counter=false;

    }else{
        ticker = new EvtLoopTicker();
        ticker->launch();
        counter=true;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 1.Yordam Önerisi
    QTimer tt;
    QObject::connect(&tt, &QTimer::timeout, pulse);
    tt.start(10000);


    // 2.Yordam Önerisi
    QThread *serialThread = new QThread;
    RenderEvent *rEvent = new RenderEvent(serialThread);

    // 3.Yordam Önerisi
    FinishTask *ftask = new FinishTask();
    ftask->doJob(2);
   
    return a.exec();
}

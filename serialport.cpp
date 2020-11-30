#include "serialport.h"

SerialPort::SerialPort(int id)
{
    this->id = id;
    initializeSerialPort();
}


void SerialPort::initializeSerialPort()
{
    serial = new QSerialPort();
    //serial->moveToThread(serialThread);
    serial->setPortName("COM15");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);


    //  serial->write("written");
}

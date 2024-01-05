#include "tcpserverthread.h"

TcpServerThread::TcpServerThread(int ID, QObject *parent):QThread(parent) {
    _socketDescriptor = ID;
}


void TcpServerThread::run(){
    // thread starts here
    qDebug() << _socketDescriptor << " Starting thread";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->_socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()),Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << _socketDescriptor << " Client connected";

    // make this thread a loop
    exec();
}

void TcpServerThread::readyRead()
{
    QByteArray Data = socket->readAll();
    qDebug() << _socketDescriptor << " Data in: " << Data;
    socket->write(Data);
}

void TcpServerThread::disconnected()
{
    qDebug() << _socketDescriptor << " Disconnected";
    socket->deleteLater();
    exit(0);
}

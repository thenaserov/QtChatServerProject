#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent)
    : QTcpServer{parent} {
}

void TcpServer::StartServer() {
    // control conneection status
    if(!this->listen(QHostAddress::LocalHost ,40400)) {
        qDebug() << "Could not start server";
    } else {
        qDebug() << "Listening...";
    }
}

void TcpServer::incomingConnection(int socketDescriptor) {
    qDebug() << socketDescriptor << " Connecting...";
    TcpServerThread *thread = new TcpServerThread(socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

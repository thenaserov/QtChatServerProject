#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent)
    : QTcpServer{parent} {
    server = new QTcpServer(this);
    // whenever a user connects, it will emit signal
    connect(server, SIGNAL(newConnection()),
            this, SLOT(newConnection()));
    if(!server->listen(QHostAddress::LocalHost, 40400)) {
        qDebug() << "Server could not start";
    } else {
        qDebug() << "Server started!";
    }
}

void TcpServer::newConnection() {
    // need to grab the socket
    QTcpSocket *socket = server->nextPendingConnection();
    socket->write("Hello client\r\n");
    socket->flush();
    socket->waitForBytesWritten(3000);
    socket->close();
}

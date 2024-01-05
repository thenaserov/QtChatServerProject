#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent)
    : QObject{parent} {
    server = new QTcpServer(this);

    // whenever a user connects, it will emit signal
    connect(server, SIGNAL(newConnection()), this, SLOT(NewConnection()));
    // control conneection status
    if(!server->listen(QHostAddress::Any, 9999)) {
        qDebug() << "Server could not start";
    } else {
        qDebug() << "Server started!";
    }
}

void TcpServer::NewConnection() {
    // need to grab the socket
    QTcpSocket *socket = server->nextPendingConnection();
    socket->write("Hello User!");
    socket->flush();
    socket->waitForBytesWritten(3000);

    // get the name of the user and store him online
    socket->close();
}

#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent)
    : QTcpServer{parent} {
}

void TcpServer::StartServer()
{
    // whenever a user connects, it will emit signal
    // connect(server, SIGNAL(newConnection()), this, SLOT(NewConnection()));
    // control conneection status
    if(!this->listen(QHostAddress::Any,1234)) {
        qDebug() << "Could not start server";
    } else {
        qDebug() << "Listening...";
    }
}

void TcpServer::incomingConnection(int socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";
    TcpServerThread *thread = new TcpServerThread(socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

// void TcpServer::NewConnection() {
//     // need to grab the socket
//     QTcpSocket *socket = server->nextPendingConnection();
//     socket->write("Hello User!");
//     socket->flush();
//     socket->waitForBytesWritten(3000);

//     // get the name of the user and store him online
//     socket->close();
// }

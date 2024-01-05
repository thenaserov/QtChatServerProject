#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QVector>
#include "tcpserverthread.h"

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);
    void StartServer();

private:
    QVector<QString> _usersVector;

protected:
    void incomingConnection(int socketDescriptor);

public slots:
    // void NewConnection();

signals:
};

#endif // TCPSERVER_H

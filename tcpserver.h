#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);

private:
    QTcpServer *server;

protected:

public slots:
    void newConnection();

signals:
};

#endif // TCPSERVER_H

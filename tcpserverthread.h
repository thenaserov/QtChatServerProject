#ifndef TCPSERVERTHREAD_H
#define TCPSERVERTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class TcpServerThread : public QThread
{
    Q_OBJECT
public:
    TcpServerThread(int ID, QObject* parent);
    void run();

private:
    QTcpSocket *socket;
    int _socketDescriptor;

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();
};

#endif // TCPSERVERTHREAD_H

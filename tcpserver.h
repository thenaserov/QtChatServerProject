#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QVector>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);
private:
    QTcpServer* server;
    QVector<QString> _usersVector;

public slots:
    void NewConnection();

signals:
};

#endif // TCPSERVER_H

#include <QCoreApplication>
#include "tcpserver.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // tcp server is instanciated here
    TcpServer server;

    return a.exec();
}

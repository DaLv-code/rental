#include "thread.h"
#include <unistd.h>
#include <QMessageBox>

Thread::Thread(int sock, QObject *parent) :
    QThread(parent)
{
    this->sock=sock;
}

void Thread::run()
{
    char msg[1024];
    while(read(sock, msg, sizeof(msg))!=-1)
    {
        emit setMsg(QString(msg));
        memset(msg,0,sizeof(msg));
    }
    this->terminate();
}

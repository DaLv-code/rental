#include "chat.h"
#include "ui_chat.h"
#include <unistd.h>
#include "thread.h"

chat::chat(std::string Get_id, int sock, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);
    this->Get_id = Get_id;
    this->sock=sock;
    thread = new Thread(sock, this);
    connect(thread, SIGNAL(setMsg(QString)), this, SLOT(chatAppend(QString)));
    thread->start();
}

chat::~chat()
{
    delete ui;
}

void chat::chatAppend(QString msg)
{
    ui->textbox->append(msg);
}

void chat::on_send_btn_clicked()
{
    std::string chatMsg="["+Get_id+"님] "+ui->write->text().toStdString();
    ui->textbox->append(QString::fromStdString(chatMsg));
    write(sock, chatMsg.c_str(), chatMsg.length());
    ui->write->clear();
}

void chat::closeEvent(QCloseEvent *event)
{
    std::string chatLog=ui->textbox->toPlainText().toStdString();
    SQL="INSERT INTO chatlogTB VALUES ('"+Get_id+"','"+chatLog+"')";
    query.exec(QString::fromStdString(SQL));
    thread->terminate();
}

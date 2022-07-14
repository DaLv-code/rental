#include "chat.h"
#include "ui_chat.h"

chat::chat(std::string Get_id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);
    this->Get_id = Get_id;
}

chat::~chat()
{
    delete ui;
}

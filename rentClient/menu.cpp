#include "menu.h"
#include "ui_menu.h"
#include "user_infor.h"
#include "tourist.h"
#include "rentacar.h"
#include "chat.h"
#include "change.h"
#include <unistd.h>

menu::menu(std::string Get_id, int sock, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    this->Get_id = Get_id;
    this->sock=sock;
}

menu::~menu()
{
    delete ui;
}

void menu::on_user_infor_clicked()
{
    this->hide();
    user_infor user_infor(Get_id, sock);
    user_infor.setModal(true);
    user_infor.exec();
    this->show();
}

void menu::on_tourist_clicked()
{
    this->hide();
    tourist tourist(sock);
    tourist.setModal(true);
    tourist.exec();
    this->show();
}

void menu::on_logout_btn_clicked()
{
    this->close();
}

void menu::on_rental_btn_clicked()
{
    this->hide();
    rentacar rentacar(Get_id, sock);
    rentacar.setModal(true);
    rentacar.exec();
    this->show();
}

void menu::on_change_btn_clicked()
{
    this->hide();
    change change(Get_id, sock);
    change.setModal(true);
    change.exec();
    this->show();
}

void menu::on_center_btn_clicked()
{
    write(sock, "request", sizeof("request"));
    //this->hide();
    chat chat(Get_id, sock);
    chat.setModal(true);
    chat.exec();
    this->show();
}

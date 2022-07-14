#include "change.h"
#include "ui_change.h"
#include "menu.h"

change::change(std::string Get_id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change)
{
    ui->setupUi(this);
    this->Get_id = Get_id;
}

change::~change()
{
    delete ui;
}

void change::on_inquiry_btn_clicked()
{

}

void change::on_cancel_btn_clicked()
{

}

void change::on_back_btn_clicked()
{
    this->hide();
    menu menu(Get_id);
    menu.setModal(true);
    menu.exec();
    this->show();
}

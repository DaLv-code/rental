#include "pay.h"
#include "ui_pay.h"
#include <cstring>
#include "string"
#include "rentacar.h"

pay::pay(std::string Get_id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pay)
{
    ui->setupUi(this);
    this->Get_id=Get_id;
    i = 0;

    SQL="SELECT cost FROM reservationTB WHERE userId = '"+Get_id+"'";
    query.exec(QString::fromStdString(SQL));
    query.next();
    int Cost = query.value(0).toInt();
    ui->fee->setText(query.value(0).toString());

    SQL="SELECT userRating, userPoint FROM userTB WHERE userId = '"+Get_id+"'";
    query.exec(QString::fromStdString(SQL));
    query.next();
    std::string Discount = query.value(0).toString().toStdString();
    if(Discount == "Member")
    {
        ui->discount->setText(QString::number(0));
        ui->total->setText(QString::number(Cost));
    }
    else if(Discount == "Premium")
    {
        ui->discount->setText(QString::number(Cost/10));
        ui->total->setText(QString::number(Cost-Cost/10));
    }
    else if(Discount == "VIP")
    {
        ui->discount->setText(QString::number(Cost/5));
        ui->total->setText(QString::number(Cost-Cost/5));
    }
    ui->point->setText(query.value(1).toString());

}

pay::~pay()
{
    delete ui;
}

void pay::on_pay_btn_clicked()
{
    if(i==1)
    {
        SQL = "UPDATE userTB SET userPoint = '0' WHERE userId = '"+Get_id+"'";
        query.exec(QString::fromStdString(SQL));
    }
    SQL = "UPDATE reservationTB SET payment = '"+ui->total->text().toStdString()+"' WHERE userId = '"+Get_id+"'";
    query.exec(QString::fromStdString(SQL));
    QMessageBox::information(this, "둘이옵서예 렌터카","결제가 완료되었습니다.");
}


void pay::on_apply_btn_clicked()
{
    i=1;
    SQL="SELECT cost FROM reservationTB WHERE userId = '"+Get_id+"'";
    query.exec(QString::fromStdString(SQL));
    query.next();
    int Cost = query.value(0).toInt();
    ui->fee->setText(query.value(0).toString());

    SQL="SELECT userRating, userPoint FROM userTB WHERE userId = '"+Get_id+"'";
    query.exec(QString::fromStdString(SQL));
    query.next();
    std::string Discount = query.value(0).toString().toStdString();
    if(Discount == "Member")
    {
        ui->discount->setText(QString::number(0));
        ui->total->setText(QString::number(Cost-query.value(1).toInt()));
    }
    else if(Discount == "Premium")
    {
        ui->discount->setText(QString::number(Cost/10));
        ui->total->setText(QString::number(Cost-Cost/10-query.value(1).toInt()));
    }
    else if(Discount == "VIP")
    {
        ui->discount->setText(QString::number(Cost/5));
        ui->total->setText(QString::number(Cost-Cost/5-query.value(1).toInt()));
    }
    ui->point->setText((QString::number(0)));
}

void pay::on_back_btn_clicked()
{
    this->hide();
    rentacar rentacar(Get_id);
    rentacar.setModal(true);
    rentacar.exec();
    this->show();
}

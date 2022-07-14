#include "rentacar.h"
#include "ui_rentacar.h"
#include "reservation.h"
#include "menu.h"

rentacar::rentacar(std::string Get_id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rentacar)
{
    ui->setupUi(this);
    this->Get_id = Get_id;
}

rentacar::~rentacar()
{
    delete ui;
}

void rentacar::on_inquiry_btn_clicked()
{
    ui->carlist->clear();
    ui->carlist->setHorizontalHeaderItem(0, new QTableWidgetItem("차종"));
    ui->carlist->setHorizontalHeaderItem(1, new QTableWidgetItem("종류"));
    ui->carlist->setHorizontalHeaderItem(2, new QTableWidgetItem("제원"));
    ui->carlist->setHorizontalHeaderItem(3, new QTableWidgetItem("렌트비용"));
    ui->carlist->setHorizontalHeaderItem(4, new QTableWidgetItem("남은 수량"));

    if(ui->all_btn->isChecked())
        SQL="SELECT * FROM carTB";
    else if(ui->gasoline_btn->isChecked())
        SQL="SELECT * FROM carTB Where carKind = '휘발유'";
    else if(ui->desel_btn->isChecked())
        SQL="SELECT * FROM carTB Where carKind = '경유'";
    else if(ui->gas_btn->isChecked())
        SQL="SELECT * FROM carTB Where carKind = 'LPG'";
    else if(ui->battery_btn->isChecked())
        SQL="SELECT * FROM carTB Where carKind = '전기차'";

    query.exec(QString::fromStdString(SQL));
    rec=query.record();
    int i=0;
    while(query.next())
    {
        ui->carlist->setItem(i,0,new QTableWidgetItem(query.value(rec.indexOf("carName")).toString()));
        ui->carlist->setItem(i,1,new QTableWidgetItem(query.value(rec.indexOf("carKind")).toString()));
        ui->carlist->setItem(i,2,new QTableWidgetItem(query.value(rec.indexOf("carData")).toString()));
        ui->carlist->setItem(i,3,new QTableWidgetItem(query.value(rec.indexOf("carCost")).toString()));
        ui->carlist->setItem(i++,4,new QTableWidgetItem(query.value(rec.indexOf("carCount")).toString()));
    }
}

void rentacar::on_reservation_btn_clicked()
{
    int rowNum=ui->carlist->currentRow(); //선택한 행정보
    std::string Carname = ui->carlist->item(rowNum, 0)->text().toStdString();

    reservation reservation(Get_id, Carname);
    reservation.setModal(true);
    reservation.exec();
    this->show();
}

void rentacar::on_back_btn_clicked()
{
    this->hide();
    menu menu(Get_id);
    menu.setModal(true);
    menu.exec();
    this->show();
}

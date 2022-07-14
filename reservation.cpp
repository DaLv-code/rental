#include "reservation.h"
#include "ui_reservation.h"
#include <cstring>
#include <string>
#include "pay.h"
#include "rentacar.h"

reservation::reservation(std::string Get_id, std::string Carname, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reservation)
{
    ui->setupUi(this);
    this->Get_id = Get_id;
    this->Carname = Carname;
    SQL="SELECT carCost, carCount FROM carTB WHERE carName = '"+Carname+"'";
    query.exec(QString::fromStdString(SQL));
    query.next();
    carcost = query.value(0).toInt();
    carcount = query.value(1).toInt();
}

reservation::~reservation()
{
    delete ui;
}


void reservation::on_reservation_btn_clicked()
{
    if(carcount != 0)
    {
        std::string rentalDate = ui->calendarWidget->selectedDate().toString("MM/dd").toStdString();
        int daynum = ui->spinBox->value();
        std::string CarCost = std::to_string(carcost*daynum);
        std::string Daynum = std::to_string(daynum);
        SQL="INSERT INTO reservationTB VALUES ('"+Get_id+"','"+Carname+"','"+CarCost+"','"+rentalDate+"','"+Daynum+"','0')";
        query.exec(QString::fromStdString(SQL));
        SQL="UPDATE carTB SET carCount = '"+std::to_string(carcount-1)+"' WHERE carName= '"+Carname+"'";
        query.exec(QString::fromStdString(SQL));
        QMessageBox::information(this, "", "예약이 완료되었습니다.");
        this->close();
        pay pay(Get_id);
        pay.setModal(true);
        pay.exec();
        this->show();
    }
    else
    {
        QMessageBox::warning(this, "","예약 가능한 차량이 없습니다.");
    }
}

void reservation::on_back_btn_clicked()
{
    this->hide();
    rentacar rentacar(Get_id);
    rentacar.setModal(true);
    rentacar.exec();
    this->show();
}

#include "tourist.h"
#include "ui_tourist.h"
#include "menu.h"

tourist::tourist(int sock, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tourist)
{
    ui->setupUi(this);
    this->sock=sock;
}

tourist::~tourist()
{
    delete ui;
}

void tourist::on_search_btn_clicked() //여행지 조회
{
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("여행지"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("주소"));

    SQL="SELECT * FROM jejuTB";
    query.exec(QString::fromStdString(SQL));
    rec=query.record();
    int i=0;
    while(query.next())
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(rec.indexOf("place")).toString()));
        ui->tableWidget->setItem(i++,1,new QTableWidgetItem(query.value(rec.indexOf("address")).toString()));
    }
}

void tourist::on_back_btn_clicked()
{
    this->hide();
    menu menu(Get_id, sock);
    menu.setModal(true);
    menu.exec();
    this->show();
}

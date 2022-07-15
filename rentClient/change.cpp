#include "change.h"
#include "ui_change.h"
#include "menu.h"

change::change(std::string Get_id, int sock, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change)
{
    ui->setupUi(this);
    this->Get_id = Get_id;
    this->sock=sock;
}

change::~change()
{
    delete ui;
}

void change::on_back_btn_clicked()
{
    this->hide();
    menu menu(Get_id, sock);
    menu.setModal(true);
    menu.exec();
    this->show();
}

void change::on_pushButton_clicked() //예약 조회
{
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("아이디"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("차종"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("렌트비용"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("날짜"));
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("대여일자"));
    ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("결제비용"));

    SQL="SELECT * FROM reservationTB";
    query.exec(QString::fromStdString(SQL));
    rec=query.record();
    int i=0;
    while(query.next())
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(rec.indexOf("userId")).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(rec.indexOf("carName")).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(query.value(rec.indexOf("cost")).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(query.value(rec.indexOf("rentalDate")).toString()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(query.value(rec.indexOf("dayNum")).toString()));
        ui->tableWidget->setItem(i++,5,new QTableWidgetItem(query.value(rec.indexOf("payment")).toString()));
    }
}

void change::on_pushButton_2_clicked() //예약 취소
{
    int rowNum=ui->tableWidget->currentRow();
    SQL="DELETE FROM reservationTB WHERE userId = '"+ui->tableWidget->item(rowNum, 0)->text().toStdString()+"'";
    query.exec(QString::fromStdString(SQL));
    on_pushButton_clicked();
    QMessageBox::information(nullptr,"Succsefull","예약 취소가 완료되었습니다");
}

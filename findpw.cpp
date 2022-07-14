#include "findpw.h"
#include "ui_findpw.h"
#include "login.h"

findpw::findpw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::findpw)
{
    ui->setupUi(this);
}

findpw::~findpw()
{
    delete ui;
}

void findpw::on_findpw_btn_clicked()
{
    std::string Get_id=ui->find_pw->text().toStdString();
    SQL = "SELECT userPw FROM userTB WHERE userId='"+ui->find_pw->text().toStdString()+"'";
    query.exec(QString::fromStdString(SQL));
    query.next();

    QMessageBox::information(this,"둘이옵서예 렌터카","비밀번호는 "+query.value(0).toString()+"입니다.");
}

void findpw::on_back_btn_clicked()
{
    this->close();
}

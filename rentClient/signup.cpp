#include "signup.h"
#include "ui_signup.h"
#include "login.h"

signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_confirm_btn_clicked()
{
    std::string Get_name=ui->signup_name->text().toStdString();
    std::string Get_id=ui->signup_id->text().toStdString();
    std::string Get_pw=ui->signup_pw->text().toStdString();
    std::string Get_pw2=ui->signup_pw2->text().toStdString();

    if(Get_pw == Get_pw2)
    {
        SQL="INSERT INTO userTB (userName, userId, userPw, userRating) VALUES('"+Get_name+"','"+Get_id+"','"+Get_pw+"','member')";
        query.exec(QString::fromStdString(SQL));
        QMessageBox::information(this,"둘이옵서예 렌터카","가입이 완료되었습니다.");
        QMessageBox::information(this,"둘이옵서예 렌터카","회원등급 : <준회원>");
        this->close();
    }
    else
    {
        QMessageBox::warning(this,"둘이옵서예 렌터카","비밀번호가 일치하지 않습니다.");
    }
}

void signup::on_idcheck_btn_clicked()
{
    std::string Get_id=ui->signup_id->text().toStdString();
    SQL = "SELECT userId FROM userTB WHERE userId='"+Get_id+"'";
    query.exec(QString::fromStdString(SQL));
    query.next();
    if(query.value(0) == ui->signup_id->text())
    {
        QMessageBox::warning(this,"둘이옵서예 렌터카","이미 사용중인 아이디입니다.");
    }
    else
    {
        ui->confirm_btn->setEnabled(true);
        QMessageBox::information(this,"둘이옵서예 렌터카","사용가능한 아이디입니다.");
    }
}

void signup::on_back_btn_clicked()
{
    this->close();
}


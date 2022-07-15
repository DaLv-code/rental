#include "login.h"
#include "ui_login.h"
#include "signup.h"
#include "menu.h"
#include "findpw.h"

Login::Login(int sock, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    this->sock=sock;
}

Login::~Login()
{
    delete ui;
}

void Login::on_login_btn_clicked()
{
    std::string Get_id=ui->get_id->text().toStdString();
    SQL = "SELECT userPw, userName, userRating FROM userTB WHERE userId='"+ui->get_id->text().toStdString()+"'";
    query.exec(QString::fromStdString(SQL));
    query.next();
    if(query.value(2) == "Member")
    {
        if(query.value(0) == ui->get_pw->text())
        {
            QMessageBox::information(this,"둘이옵서예 렌터카", query.value(1).toString()+"님 환영합니다.");
            this->hide();
            menu menu(Get_id, sock);
            menu.setModal(true);
            menu.exec();
            this->show();
            ui->get_id->clear();
            ui->get_pw->clear();
        }
        else
        {
            ui->get_id->clear();
            ui->get_pw->clear();
            QMessageBox::warning(this,"둘이옵서예 렌터","아이디 또는 비밀번호를 잘못 입력했습니다.");
        }
    }
    else
    {
        ui->get_id->clear();
        ui->get_pw->clear();
        QMessageBox::warning(this,"둘이옵서예 렌터", "<준회원>등급만 로그인이 가능합니다.");
    }
}

void Login::on_signup_btn_clicked()
{
    this->hide();
    signup signup;
    signup.setModal(true);
    signup.exec();
    this->show();
    ui->get_id->clear();
    ui->get_pw->clear();
}

void Login::on_find_btn_clicked()
{
    this->hide();
    findpw findpw;
    findpw.setModal(true);
    findpw.exec();
    this->show();
    ui->get_id->clear();
    ui->get_pw->clear();
}

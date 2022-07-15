#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <database.h>
#include <cstring>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(int sock, QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_login_btn_clicked();
    void on_signup_btn_clicked();
    void on_find_btn_clicked();

private:
    DB database;
    Ui::Login *ui;
    QSqlQuery query;
    QSqlRecord rec;
    std::string SQL;
    int sock;
};
#endif // LOGIN_H

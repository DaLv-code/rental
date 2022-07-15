#ifndef USER_INFOR_H
#define USER_INFOR_H
#include "database.h"
#include <QDialog>

namespace Ui {
class user_infor;
}

class user_infor : public QDialog
{
    Q_OBJECT

public:
    explicit user_infor(std::string Get_id, int sock, QWidget *parent = nullptr);
    ~user_infor();

private slots:
    void on_change_name_btn_clicked();
    void on_change_pw_btn_clicked();
    void on_withdraw_btn_clicked();
    void on_back_btn_clicked();

private:
    Ui::user_infor *ui;
    QSqlQuery query;
    QSqlRecord rec;
    std::string SQL;
    std::string Get_id;
    int sock;
};

#endif // USER_INFOR_H

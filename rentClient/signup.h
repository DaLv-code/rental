#ifndef SIGNUP_H
#define SIGNUP_H
#include "database.h"
#include <QDialog>

namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_confirm_btn_clicked();

    void on_idcheck_btn_clicked();

    void on_back_btn_clicked();

private:
    Ui::signup *ui;
    QSqlQuery query;
    QSqlRecord rec;
    std::string SQL;
};

#endif // SIGNUP_H

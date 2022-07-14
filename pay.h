#ifndef PAY_H
#define PAY_H
#include "database.h"
#include <QDialog>

namespace Ui {
class pay;
}

class pay : public QDialog
{
    Q_OBJECT

public:
    explicit pay(std::string Get_id, QWidget *parent = nullptr);
    ~pay();

private slots:
    void on_pay_btn_clicked();

    void on_apply_btn_clicked();

    void on_back_btn_clicked();

private:
    Ui::pay *ui;
    QSqlQuery query;
    QSqlRecord rec;
    std::string SQL;
    std::string Get_id;
    int i;
};

#endif // PAY_H

#ifndef reservation_H
#define reservation_H
#include "database.h"
#include <QDialog>

namespace Ui {
class reservation;
}

class reservation : public QDialog
{
    Q_OBJECT

public:
    explicit reservation(std::string Get_id, std::string Carname, QWidget *parent = nullptr);
    ~reservation();

private slots:
    void on_reservation_btn_clicked();

    void on_back_btn_clicked();

private:
    Ui::reservation *ui;
    QSqlQuery query;
    QSqlRecord rec;
    std::string SQL;
    std::string Get_id;
    std::string Carname;
    int carcost;
    int carcount;
};

#endif // reservation_H

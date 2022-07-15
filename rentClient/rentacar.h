#ifndef RENTACAR_H
#define RENTACAR_H
#include "database.h"
#include <QDialog>

namespace Ui {
class rentacar;
}

class rentacar : public QDialog
{
    Q_OBJECT

public:
    explicit rentacar(std::string Get_id, int sock, QWidget *parent = nullptr);
    ~rentacar();

private slots:
    void on_inquiry_btn_clicked();

    void on_reservation_btn_clicked();

    void on_back_btn_clicked();

private:
    Ui::rentacar *ui;
    QSqlQuery query;
    QSqlRecord rec;
    std::string SQL;
    std::string Get_id;
    int sock;
};

#endif // RENTACAR_H

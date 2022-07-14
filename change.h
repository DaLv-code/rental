#ifndef CHANGE_H
#define CHANGE_H
#include "database.h"
#include <QDialog>

namespace Ui {
class change;
}

class change : public QDialog
{
    Q_OBJECT

public:
    explicit change(std::string Get_id, QWidget *parent = nullptr);
    ~change();

private slots:
    void on_inquiry_btn_clicked();

    void on_cancel_btn_clicked();

    void on_back_btn_clicked();

private:
    Ui::change *ui;
    QSqlQuery query;
    QSqlRecord rec;
    std::string SQL;
    std::string Get_id;
};

#endif // CHANGE_H

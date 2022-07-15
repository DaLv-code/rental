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
    explicit change(std::string Get_id, int sock, QWidget *parent = nullptr);
    ~change();

private slots:
    void on_back_btn_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::change *ui;
    QSqlQuery query;
    QSqlRecord rec;
    std::string SQL;
    std::string Get_id;
    int sock;
};

#endif // CHANGE_H

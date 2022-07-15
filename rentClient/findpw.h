#ifndef FINDPW_H
#define FINDPW_H

#include <QDialog>
#include <cstring>
#include "database.h"

namespace Ui {
class findpw;
}

class findpw : public QDialog
{
    Q_OBJECT

public:
    explicit findpw(QWidget *parent = nullptr);
    ~findpw();

private slots:
    void on_findpw_btn_clicked();

    void on_back_btn_clicked();

private:
    Ui::findpw *ui;
    QSqlQuery query;
    QSqlRecord rec;
    std::string SQL;
    std::string Get_id;
};

#endif // FINDPW_H

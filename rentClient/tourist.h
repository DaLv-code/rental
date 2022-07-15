#ifndef TOURIST_H
#define TOURIST_H
#include <cstring>
#include <QDialog>
#include "database.h"

namespace Ui {
class tourist;
}

class tourist : public QDialog
{
    Q_OBJECT

public:
    explicit tourist(int sock, QWidget *parent = nullptr);
    ~tourist();

private slots:
    void on_search_btn_clicked();
    void on_back_btn_clicked();

private:
    Ui::tourist *ui;
    QSqlQuery query;
    QSqlRecord rec;
    std::string SQL;
    std::string Get_id;
    int sock;
};

#endif // TOURIST_H

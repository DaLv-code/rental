#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include <cstring>

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(std::string Get_id, QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_user_infor_clicked();

    void on_tourist_clicked();

    void on_logout_btn_clicked();

    void on_rental_btn_clicked();

    void on_change_btn_clicked();

    void on_center_btn_clicked();

private:
    Ui::menu *ui;
    std::string Get_id;
};

#endif // MENU_H

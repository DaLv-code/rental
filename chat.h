#ifndef chat_H
#define chat_H
#include "database.h"
#include <QDialog>

namespace Ui {
class chat;
}

class chat : public QDialog
{
    Q_OBJECT

public:
    explicit chat(std::string Get_id, QWidget *parent = nullptr);
    ~chat();

private:
    Ui::chat *ui;
    QSqlQuery query;
    QSqlRecord rec;
    std::string SQL;
    std::string Get_id;
};

#endif // chat_H

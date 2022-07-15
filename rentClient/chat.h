#ifndef chat_H
#define chat_H
#include "database.h"
#include <QDialog>
#include "thread.h"

namespace Ui {
class chat;
}

class chat : public QDialog
{
    Q_OBJECT

public:
    explicit chat(std::string Get_id, int sock, QWidget *parent = nullptr);
    ~chat();

private slots:
    void on_send_btn_clicked();
    void chatAppend(QString msg);
    void closeEvent(QCloseEvent *event);

private:
    Ui::chat *ui;
    QSqlQuery query;
    QSqlRecord rec;
    std::string SQL;
    std::string Get_id;
    int sock;
    Thread * thread;
};

#endif // chat_H

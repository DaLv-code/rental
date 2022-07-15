#ifndef DB_H
#define DB_H

#include <iostream>
#include <string>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QtSql>
#include <QDebug>
#include <cstring>

class DB
{
protected:
    QSqlDatabase db;

public:
    DB() {
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setDatabaseName("rental");
        db.setHostName("10.10.20.35");
        db.setUserName("open");
        db.setPassword("root1234");
        db.setPort(3306);
        if (db.open()){
        }
        else{
            QMessageBox::critical(nullptr,"Error",db.lastError().text());
        }
    }
    ~DB() {
        db.close();
    }
};

#endif

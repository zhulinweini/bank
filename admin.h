#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include<QDebug>

extern "C"
{
#include"slite3_function.h"
#include"sqlite3.h"
}

namespace Ui {
class admin;
}

class admin : public QWidget
{
    Q_OBJECT

public:

    explicit admin(QWidget *parent = 0);

    ~admin();
    void fun_db(sqlite3 *a);
    sqlite3 *db;
private:
    Ui::admin *ui;
      //sqlite3 *fdb;
signals:
    void sendmsg_ad_enter(QString str);
private slots:
    void on_pushButton_alter_back_clicked();
    void on_pushButton_close_back_clicked();
    void on_pushButton_op_back_clicked();
    void on_pushButton_op_ok_clicked();
    void on_pushButton_close_ok_clicked();
    void on_pushButton_alter_ok_clicked();
};

#endif // ADMIN_H



#ifndef USER_H
#define USER_H

#include <QWidget>
#include<QMessageBox>
extern "C"
{
#include"slite3_function.h"
#include"sqlite3.h"
}

namespace Ui {
class user;
}

class user : public QWidget
{
    Q_OBJECT

public:

    explicit user(QWidget *parent = 0);
    ~user();
 sqlite3 *db;
private:
    Ui::user *ui;

signals:
    void sendmsg_enter(QString str);
private slots:
    void on_pushButton_saving_back_clicked();
    void on_pushButton_draw_back_clicked();
    void on_pushButton_change_back_clicked();
    void on_pushButton_trade_back_clicked();
    void on_pushButton_saving_ok_clicked();
    void on_pushButton_draw_ok_clicked();
    void on_pushButton_change_ok_clicked();
    void on_pushButton_trade_balance_clicked();
    void on_pushButton_trade_detail_clicked();
};

#endif // USER_H

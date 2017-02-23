#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"user.h"
#include"admin.h"



extern "C"
{
#include"sqlite3.h"
#include"slite3_function.h"

}
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    sqlite3 *db;
      explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:

    void on_pushButton_primary_enter_clicked();
    //显示主界面
     void show_primary_menu(QString str);

     void on_comboBox_user_type_activated(const QString &arg1);

     void on_pushButton_exit_clicked();

private:
    Ui::Widget *ui;
    //登录user
    user *enter;
    admin *ad_enter;
    //获取user和admin
    QString use;
    //user *us;
  //  admin *admi;

};

#endif // WIDGET_H

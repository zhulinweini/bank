#include "widget.h"
#include "ui_widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

     this->enter=new user();
     this->ad_enter=new admin();
    int result=sqlite3_open("bank.db",&db);
    if(result!=SQLITE_OK)
    {
        qDebug()<<"openerror";


    }




    this->enter->db=db;
    this->ad_enter->db=db;

  connect(this->enter,SIGNAL(sendmsg_enter(QString)),this,SLOT(show_primary_menu(QString)));
     //登录到admin界面连接；

  connect(this->ad_enter,SIGNAL(sendmsg_ad_enter(QString)),this,SLOT(show_primary_menu(QString)));

}

Widget::~Widget()
{
    delete ui;
}
//登录到user界面
void Widget::on_pushButton_primary_enter_clicked()
{


    QString  str=ui->lineEdi_dl_user->text();;
    char*  dluser;
    QByteArray ba1 = str.toLatin1();
    dluser=ba1.data();
    QString  str1=ui->lineEdit_dl_password->text();;
    char*  dlpwd;
    QByteArray ba = str1.toLatin1();
    dlpwd=ba.data();

    qDebug()<<dluser;
    qDebug()<<dlpwd;
    int a=register_use_pwd(enter->db,dluser,dlpwd);



     if(this->use=="user"&&a==0){
         a=1;
    this->hide();
    this->enter->show();
     }
     if(this->use=="admin"&&a==0){
         a=1;
         this->hide();
         this->ad_enter->show();
     }
}
//显示主界面
 void Widget::show_primary_menu(QString str)
 {
     qDebug()<<str;
     this->show();
 }
//获取user和admin
void Widget::on_comboBox_user_type_activated(const QString &arg1)
{
      this->use=ui->comboBox_user_type->currentText();
      qDebug()<<this->use;
}
//退出程序
void Widget::on_pushButton_exit_clicked()
{
    sqlite3_close(this->db);
    //ui->pushButton_exit->exit();
    //ui->pushButton_exit->close();
}

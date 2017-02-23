#include "admin.h"
#include "ui_admin.h"
#include<QMessageBox>
admin::admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}
//返回主界面
void admin::on_pushButton_alter_back_clicked()
{
    this->hide();
    emit this->sendmsg_ad_enter("alter_back");
}

void admin::on_pushButton_close_back_clicked()
{
    this->hide();
    emit this->sendmsg_ad_enter("close_back");
}

void admin::on_pushButton_op_back_clicked()
{
    this->hide();
    emit this->sendmsg_ad_enter("op_back");
}
//开户确认
void admin::on_pushButton_op_ok_clicked()
{

    qDebug()<<"fdsafdsa"<<this->db;
    QString str_user=ui->lineEdit_op_acount_user->text();
    char* user;
    QByteArray ba=str_user.toLatin1();
    user=ba.data();

    /*
    QString str_money=ui->lineEdit_op_amount_money->text();
    char *money;
    QByteArray ba1=str_money.toLatin1();
    money=ba1.data();
    *float num = data.toFloat();/
    */
    QString str_money=ui->lineEdit_op_amount_money->text();
    float money=str_money.toFloat();

    QString str_password=ui->lineEdit_op_acount_password->text();
    char *password;
    QByteArray ba2=str_password.toLatin1();
    password=ba2.data();

    QString str_newpassword=ui->lineEdit_acount_newpassword->text();
    char *newpassword;
    QByteArray ba3=str_newpassword.toLatin1();
    newpassword=ba3.data();


    qDebug()<<user;
    qDebug()<<money;
    qDebug()<<password;

    if(str_password==str_newpassword)
    {


         qDebug()<<"this==3====="<<this->db;
      int i=op_account_function(this->db,user,password,money);
      if(i==1){
      QMessageBox::question(this,"开户","开户成功！",QMessageBox::Yes|QMessageBox::No);
      }
      else{
        QMessageBox::question(this,"开户","开户失败！",QMessageBox::Yes|QMessageBox::No);
      }

    }

}
//销户

void admin::on_pushButton_close_ok_clicked()
{

    QString str_user=ui->lineEdit_close_user->text();
    char* user;
    QByteArray ba=str_user.toLatin1();
    user=ba.data();

    QString str_password=ui->lineEdit_close_password->text();
    char *password;
    QByteArray ba2=str_password.toLatin1();
    password=ba2.data();

    qDebug()<<user;
    qDebug()<<password;
   int i=close_user_function(this->db,user,password);
   if(i==1){
   QMessageBox::question(this,"开户","开户成功！",QMessageBox::Yes|QMessageBox::No);
   }
   else{
     QMessageBox::question(this,"开户","开户失败！",QMessageBox::Yes|QMessageBox::No);
   }
}
//修改密码
void admin::on_pushButton_alter_ok_clicked()
{
    QString str_user=ui->lineEdit_alter_user->text();
    char* user;
    QByteArray ba=str_user.toLatin1();
    user=ba.data();

    QString str_password=ui->lineEdit_alter_oldpassword->text();
    char *oldpassword;
    QByteArray ba2=str_password.toLatin1();
    oldpassword=ba2.data();

    QString str_newpassword=ui->lineEdit_alter_newpassword->text();
    char* newpassword;
    QByteArray ba3=str_newpassword.toLatin1();
    newpassword=ba3.data();

    QString str_npassword=ui->lineEdit_alter_okpassword->text();
    char *npassword;
    QByteArray ba4=str_npassword.toLatin1();
    npassword=ba4.data();

    int a=alter_password_function(this->db,user,oldpassword,newpassword,npassword);
    if(a==1){
    QMessageBox::question(this,"密码","修改密码成功！",QMessageBox::Yes|QMessageBox::No);
    }
    else{
      QMessageBox::question(this,"密码","修改密码失败！",QMessageBox::Yes|QMessageBox::No);
    }
}

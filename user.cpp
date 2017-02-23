#include "user.h"
#include "ui_user.h"
#include<qdebug>

user::user(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user)
{
    ui->setupUi(this);
}

user::~user()
{
    delete ui;
}
//返回到登录界面
void user::on_pushButton_saving_back_clicked()
{
    this->hide();
     qDebug()<<"this==4====="<<this->db;
    emit this->sendmsg_enter("saving_back");
}

void user::on_pushButton_draw_back_clicked()
{
    this->hide();
    emit this->sendmsg_enter("draw_back");
}

void user::on_pushButton_change_back_clicked()
{
    this->hide();
     emit this->sendmsg_enter("change_back");
}

void user::on_pushButton_trade_back_clicked()
{this->hide();

    emit this->sendmsg_enter("trade_back");
}
//存款
void user::on_pushButton_saving_ok_clicked()
{
    QString str_card=ui->lineEdit_saving_bankcard_number->text();
    char* card;
    QByteArray ba=str_card.toLatin1();
    card=ba.data();

    QString str_money=ui->lineEdit_saving_amount_money->text();
    char* money;
    QByteArray ba1=str_money.toLatin1();
    money=ba1.data();
    qDebug()<<card;
    qDebug()<<money;

    int i=saving_money_function(this->db,card,money);
    if(i==1){
    QMessageBox::question(this,"存款","存款成功！",QMessageBox::Yes|QMessageBox::No);
    }
    else{
      QMessageBox::question(this,"存款","存款失败！",QMessageBox::Yes|QMessageBox::No);
    }
}
//取款
void user::on_pushButton_draw_ok_clicked()
{
    QString str_card=ui->lineEdit->text();
    char* card;
    QByteArray ba=str_card.toLatin1();
    card=ba.data();

    QString str_money=ui->lineEdit_draw_take_money->text();
    char* money;
    QByteArray ba1=str_money.toLatin1();
    money=ba1.data();
    qDebug()<<card;
    qDebug()<<money;

    int i=draw_money_function(this->db,card,money);
    if(i==1){
    QMessageBox::question(this,"取款","取款成功！",QMessageBox::Yes|QMessageBox::No);
    }
    else{
      QMessageBox::question(this,"取款","取款失败！",QMessageBox::Yes|QMessageBox::No);
    }

}

//转账
void user::on_pushButton_change_ok_clicked()
{
    QString str_card=ui->lineEdit_change_bankcard_number->text();
    char* card;
    QByteArray ba=str_card.toLatin1();
    card=ba.data();

    QString str_card1=ui->lineEdit_other_bankcard_number->text();
    char* card1;
    QByteArray ba1=str_card1.toLatin1();
    card1=ba1.data();

    QString str_money=ui->lineEdit_change_transfer_money->text();
    char* money;
    QByteArray ba2=str_money.toLatin1();
    money=ba2.data();
    qDebug()<<card;
    qDebug()<<money;

    int i=change_money_function(this->db,card,card1,money);
    if(i==1){
    QMessageBox::question(this,"转账","转账成功！",QMessageBox::Yes|QMessageBox::No);
    }
    else{
      QMessageBox::question(this,"转账","转账失败！",QMessageBox::Yes|QMessageBox::No);
    }
}
//余额
void user::on_pushButton_trade_balance_clicked()
{
    QString str_card=ui->lineEdit_detail_card->text();
    char* card;
    QByteArray ba=str_card.toLatin1();
    card=ba.data();



   int a=details_money_function(this->db,card);
   if(a==-1){
   QMessageBox::question(this,"余额","查看余额失败！",QMessageBox::Yes|QMessageBox::No);
   }
   else{

         QString str=QString::number(a);
         ui->label->setText(str);
   }

}


//明细
void user::on_pushButton_trade_detail_clicked()
{

    QString str_card=ui->lineEdit_detail_card->text();
    char* card;
    QByteArray ba=str_card.toLatin1();
    card=ba.data();

    //char *buf=trade_details_function(this->db,card);
    char **dbResult=NULL;
    char *errmsg;
    //char buf[1024];
    int result,nrow,ncolumn;
    //sprintf(buf,"select * from BankCardDetail where BCno='%s';",card);
    QString buf=QString("select * from BankCardDetail where BCno='%1';").arg(str_card);
    char* buf1;
    QByteArray ba1=buf.toLatin1();
    buf1=ba1.data();
    result=sqlite3_get_table(this->db,buf1,&dbResult,&nrow,&ncolumn,&errmsg);
    if(dbResult[0]&&result==SQLITE_OK)
    {


            int i;
            for(i=1;i<nrow;i++){
                 printf("dbResult%d===%s\n",i,dbResult[i]);
                 ui->textEdit_trade_text->append(dbResult[i*ncolumn]);
                 ui->textEdit_trade_text->append(dbResult[i*ncolumn+1]);
                 ui->textEdit_trade_text->append(dbResult[i*ncolumn+2]);
                 ui->textEdit_trade_text->append(dbResult[i*ncolumn+3]);
                // i++;
            }



    }else{
        QMessageBox::question(this,"明细","查看明细失败！无此卡！",QMessageBox::Yes|QMessageBox::No);
    }


}

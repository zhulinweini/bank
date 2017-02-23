
#include"slite3_function.h"
//回调函数

void loadmyinfo(void * para,int n_column,char **column_value,char **column_name)
{
    int i=0;
    for(i=0;i<n_column;i++)
    {

        printf("%s\t",column_value[i]);
    }
    printf("\n");
    return 0;
}
//登录匹配
int register_use_pwd(sqlite3 *db,char *dluser,char *dlpwd)
{
       char *errmsg;
       char **dbResult=NULL;
        char buf[1024];
        int result;
    sprintf(buf,"select * from User where Uname='%s' and Upwd='%s';",dluser,dlpwd);

    printf("buf=%s\n",buf);
    result=sqlite3_get_table(db,buf,&dbResult,NULL,NULL,&errmsg);
    if(result==SQLITE_OK&&dbResult[0])
    {
        printf("dbresult=%s\n",dbResult[0]);
        sqlite3_free_table(dbResult);
        printf("errmsg=%s\n",errmsg);
        return 0;
    }else{
    return 1;
    }

}

//开户函数

int op_account_function(sqlite3 *db,char *user,char *password,float money)
{

#if 1

    char *errmsg=NULL;


     char buf[1024]="";
     char buf1[1024]="";
     int result1;
     char card[1024]="";
     int card1=10000000+srand(time(0))%(99999999-10000000);
     int card2=10000000+srand(time(0))%(99999999-10000000);
     sprintf(card,"%d%d",card1,card2);
      printf("card=%s\n",card);
    sprintf(buf,"insert into User values('%s','%s','user',datetime('now'));",user,password);
      printf("buf=%s\n",buf);
#endif
 //result=sqlite3_get_table(db,buf,&dbResult,NULL,NULL,&errmsg);
         sqlite3_exec(db,buf,NULL,NULL,&errmsg);

 if(errmsg)
 {
     printf("errmsg=%s\n",errmsg);
     return 0;
 }

    sprintf(buf1,"insert into BankCard values('%s','%s',%f);",card,user,money);
     printf("buf1=%s\n",buf1);
      sqlite3_exec(db,buf1,NULL,NULL,&errmsg);

      return 1;


}
//销户

int close_user_function(sqlite3 *db,char *name,char *password)
{
           char *errmsg=NULL;
           char *errmsg1=NULL;
          char **dbResult=NULL;
          char **dbResult1=NULL;
          char buf[1024];
          char buf1[1024];
         int result,result1;
       sprintf(buf,"delete from User where Uname='%s' and '%s';",name,password);
       result=sqlite3_get_table(db,buf,&dbResult,NULL,NULL,&errmsg);
       printf("buf=%s\n",buf);
       if(errmsg)
       {
           printf("errmsg=%s\n",errmsg);
           return 0;
       }
       if(result==SQLITE_OK)
       {
           sqlite3_free_table(dbResult);
       }
        sprintf(buf1,"delete from BankCard where Uname='%s';",name);
        printf("buf1=%s\n",buf1);
       result1=sqlite3_get_table(db,buf1,&dbResult1,NULL,NULL,&errmsg1);
       if(errmsg1)
       {
           printf("errmsg=%s\n",errmsg1);
           return 0;
       }
       if(result1==SQLITE_OK)
       {
           printf("liiiiiii\n");
           sqlite3_free_table(dbResult1);
       }

       return 1;
}


//修改密码
int alter_password_function(sqlite3 *db,char *user,char *oldpassword,char *newpassword,char *npassword)
{
    char *errmsg=NULL;
   char **dbResult=NULL;
    char buf[1024];
    int result;
 sprintf(buf,"update User set Upwd='%s' where Uname='%s' and Upwd='%s';",npassword,user,oldpassword);
 result=sqlite3_get_table(db,buf,&dbResult,NULL,NULL,&errmsg);

 if(errmsg)
 {
     printf("errmsg=%s\n",errmsg);
     return 0;
 }
 if(result==SQLITE_OK)
 {

     sqlite3_free_table(dbResult);

 }

 return 1;

}

////****
int saving_money_function(sqlite3 *db,char *card,char *money)
{
    char *errmsg;
    char *errmsg1;
    char *errmsg2;
    int text=99;
    char buf[1024];
    char buf1[1024];
    char buf2[1024];
     char **dbResult=NULL;
     char **dbResult1=NULL;
     char **dbResult2=NULL;
     int result,result1,result2;
     int flag=0;

      printf("moneeee=%s\n",money);
     int d=atoi(money);


      sprintf(buf,"select BCmon from BankCard where BCno='%s';",card);
      result=sqlite3_get_table(db,buf,&dbResult,NULL,NULL,&errmsg);
      if(dbResult[0]&&result==SQLITE_OK)
      {

          //printf("errmsg=%s\n",errmsg);
          flag=1;
      }
      printf("dbresult[1]=%s\n",dbResult[1]);
      int dbre=atoi(dbResult[1]);
      printf("d=%d\n",d);
      printf("dbre=%d\n",dbre);
      int sum=d+dbre;
      printf("sum=%d\n",sum);



     sprintf(buf1,"update BankCard set BCmon=%d where BCno='%s';",sum,card);
      result1=sqlite3_get_table(db,buf1,&dbResult1,NULL,NULL,&errmsg1);
     printf("bu1====%s\n",buf1);
     if(dbResult1[0]&&result1==SQLITE_OK)
     {

         printf("errmsg=%s\n",errmsg1);
         flag=1;
     }

      sprintf(buf2,"insert into BankCardDetail values('%s','存款','%s',datetime('now'));",card,money);
       result2=sqlite3_get_table(db,buf2,&dbResult2,NULL,NULL,&errmsg2);
      printf("bu====%s\n",buf2);
      if(dbResult2[0]&&result2==SQLITE_OK)
      {

          printf("errmsg=%s\n",errmsg2);
          flag=1;
      }
      if(flag){
          return 1;
      }else{
      return 0;
      }

}



//取款
int draw_money_function(sqlite3 *db,char *card,char *money)
{
    char *errmsg;
    char *errmsg1;
    char *errmsg2;
    char buf[1024];
    char buf1[1024];
    char buf2[1024];
     char **dbResult=NULL;
     char **dbResult1=NULL;
     char **dbResult2=NULL;
     int result,result1,result2;
     int d=atoi(money);

      sprintf(buf,"select BCmon from BankCard where BCno='%s';",card);
      result=sqlite3_get_table(db,buf,&dbResult,NULL,NULL,&errmsg);
      if(errmsg&&result==SQLITE_OK)
      {

          printf("errmsg=%s\n",errmsg);
          return 0;
      }
      printf("dbresult[1]=%s\n",dbResult[1]);
      int dbre=atoi(dbResult[1]);
      printf("d=%d\n",d);
      printf("dbre=%d\n",dbre);
      if(d>dbre)
      {
          return 0;
      }
      int sum=dbre-d;
      printf("sum=%d\n",sum);



     sprintf(buf1,"update BankCard set BCmon=%d where BCno='%s';",sum,card);
      result1=sqlite3_get_table(db,buf1,&dbResult1,NULL,NULL,&errmsg1);
     printf("bu1====%s\n",buf1);
     if(errmsg1&&result1==SQLITE_OK)
     {

         printf("errmsg=%s\n",errmsg1);
         return 0;
     }

      sprintf(buf2,"insert into BankCardDetail values('%s','取款','%s',datetime('now'));",card,money);
       result2=sqlite3_get_table(db,buf2,&dbResult2,NULL,NULL,&errmsg2);
      printf("bu====%s\n",buf2);
      if(errmsg2&&result2==SQLITE_OK)
      {

          printf("errmsg=%s\n",errmsg2);
          return 0;
      }
      return 1;
}




//转账
int change_money_function(sqlite3 *db,char *card,char *card1,char *money)
{
    char *errmsg;
    char *errmsg1;
    char *errmsg2;
    char *errmsg3;
    char *errmsg4;
    char *errmsg5;
    char *errmsg6;
    char buf[1024];
    char buf1[1024];
    char buf2[1024];
    char buf3[1024];
    char buf4[1024];
    char buf5[1024];
    char buf6[1024];
     char **dbResult=NULL;
     char **dbResult1=NULL;
     char **dbResult2=NULL;
     char **dbResult3=NULL;
     char **dbResult4=NULL;
     char **dbResult5=NULL;
     char **dbResult6=NULL;
    // char card2[64];
     int result,result1,result2,result3,result4,resulte5,resulte6;

    int money_tf=atoi(money);
    //1,卡
     sprintf(buf,"select BCmon from BankCard where BCno='%s';",card);
     result=sqlite3_get_table(db,buf,&dbResult,NULL,NULL,&errmsg);
     if(errmsg&&result==SQLITE_OK)
     {

         printf("errmsg=%s\n",errmsg);
         return 0;
     }
     printf("dbresult[1]=%s\n",dbResult[1]);
     int money_card=atoi(dbResult[1]);

     //转向卡
     sprintf(buf1,"select BCmon from BankCard where BCno='%s';",card1);
     result1=sqlite3_get_table(db,buf1,&dbResult,NULL,NULL,&errmsg1);
     if(errmsg1&&result1==SQLITE_OK)
     {

         printf("errmsg1=%s\n",errmsg1);
         return 0;
     }

     printf("dbresult[1]=%s\n",dbResult[1]);
     int money_card2=atoi(dbResult[1]);

     if(money_tf>money_card)
     {
         return 0;
     }

     int newmoney_card=money_card-money_tf;
     int newmoney_card1=money_card2+money_tf;

     //写入卡里转出
     sprintf(buf2,"update BankCard set BCmon=%d where BCno='%s';",newmoney_card,card);
      result2=sqlite3_get_table(db,buf2,&dbResult2,NULL,NULL,&errmsg2);
     printf("bu2====%s\n",buf2);
     if(errmsg2&&result2==SQLITE_OK)
     {

         printf("errmsg2=%s\n",errmsg2);
         return 0;
     }

     sprintf(buf3,"insert into BankCardDetail values('%s','转出','%s',datetime('now'));",card,money);
      result3=sqlite3_get_table(db,buf3,&dbResult3,NULL,NULL,&errmsg3);
     printf("bu3====%s\n",buf3);
     if(errmsg3&&result3==SQLITE_OK)
     {

         printf("errmsg3=%s\n",errmsg3);
         return 0;
     }



     //写入卡里转向
     sprintf(buf4,"update BankCard set BCmon=%d where BCno='%s';",newmoney_card1,card1);
      result1=sqlite3_get_table(db,buf4,&dbResult4,NULL,NULL,&errmsg4);
     printf("bu14====%s\n",buf4);
     if(errmsg4&&result4==SQLITE_OK)
     {

         printf("errmsg4=%s\n",errmsg4);
         return 0;
     }


     sprintf(buf5,"insert into BankCardDetail values('%s','转入','%s',datetime('now'));",card1,money);
      resulte5=sqlite3_get_table(db,buf5,&dbResult5,NULL,NULL,&errmsg5);
     printf("bu5====%s\n",buf5);
     if(errmsg5&&resulte5==SQLITE_OK)
     {

         printf("errmsg5=%s\n",errmsg5);
         return 0;
     }

     //更新表TransferAccount
     sprintf(buf6,"insert into TransferAccount values('%s','%s',datetime('now'),'%s');",card,money,card1);
      resulte6=sqlite3_get_table(db,buf6,&dbResult6,NULL,NULL,&errmsg6);
     printf("bu6====%s\n",buf6);
     if(errmsg6&&resulte6==SQLITE_OK)
     {

         printf("errmsg6=%s\n",errmsg6);
         return 0;
     }



     return 1;

}



//余额
int details_money_function(sqlite3 *db,char *card)
{
    char **dbResult=NULL;
    char *errmsg;
    char buf[1024];
    int result;
    sprintf(buf,"select BCmon from BankCard where BCno='%s';",card);
    result=sqlite3_get_table(db,buf,&dbResult,NULL,NULL,&errmsg);
    if(dbResult[0]&&result==SQLITE_OK)
    {
        printf("dbresult[1]=%s\n",dbResult[1]);
        int money_card=atoi(dbResult[1]);
        //printf("errmsg=%s\n",errmsg);
        return money_card;
    }
   // printf("dbresult[1]=%s\n",dbResult[1]);
    //int money_card=atoi(dbResult[1]);
    //printf("mmmm=%d\n",money_card);
    return -1;
}


/*
//明细
char *trade_details_function(sqlite3 *db,char *card)
{
    char **dbResult=NULL;
    char *errmsg;
    char buf[1024];
    int result;
    sprintf(buf,"select * from BankCardDetail where BCno='%s';",card);
    result=sqlite3_get_table(db,buf,&dbResult,NULL,NULL,&errmsg);
    if(dbResult[0]&&result==SQLITE_OK)
    {
        /*

       // printf("errmsg=%s\n",errmsg);
        printf("dbResult0===%s\n",dbResult[0]);
         printf("dbResult1===%s\n",dbResult[1]);
          printf("dbResult2===%s\n",dbResult[2]);
           printf("dbResult3===%s\n",dbResult[3]);
            printf("dbResult4===%s\n",dbResult[4]);
            int i=0;
            while(i<8){
                 printf("dbResult%d===%s\n",i,dbResult[i]);
                 if(dbResult[i+1]==NULL){
                     break;
                 }
                 i++;
            }

        return dbResult;

    }
}
*/

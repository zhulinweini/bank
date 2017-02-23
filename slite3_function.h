#ifndef _SQLITE3_FUNCTION_H_
#define _SQLITE3_FUNCTION_H_
#include<stdio.h>
#include"sqlite3.h"
#include<time.h>

extern int register_use_pwd(sqlite3 *db,char *dluser,char *dlpwd);
extern void loadmyinfo(void * para,int n_column,char **column_value,char **column_name);
extern int op_account_function(sqlite3 *db,char *user,char *password,float money);
extern int close_user_function(sqlite3 *db,char *name,char *password);
extern int alter_password_function(sqlite3 *db,char *user,char *oldpassword,char *newpassword,char *npassword);
extern int saving_money_function(sqlite3 *db,char *card,char *money);
extern int draw_money_function(sqlite3 *db,char *card,char *money);
extern int change_money_function(sqlite3 *db,char *card,char *card1,char *money);
extern int details_money_function(sqlite3 *db,char *card);
//extern char *trade_details_function(sqlite3 *db,char *card);
#endif




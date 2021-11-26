/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-23 20:28:08
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-26 11:14:07
 */
#ifndef __CALC_H__
#define __CALC_H__
void myinput(int *num1, int *num2);
int myadd(int num1, int num2);
int mymul(int num1, int num2);
int mydiv(int num1, int num2);
int mysub(int num1, int num2);
void print_help();
typedef int OP(int, int);
OP *funcfactory(char *op); //算数工厂
#endif
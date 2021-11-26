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
void myinput(double *num1, double *num2);
double myadd(double num1, double num2);
double mymul(double num1, double num2);
double mydiv(double num1, double num2);
double mysub(double num1, double num2);
void print_help();
typedef double OP(double, double);
OP *funcfactory(char *op); //算数工厂
#endif
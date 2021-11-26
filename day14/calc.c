/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-23 20:27:59
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-26 11:33:53
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

void myinput(double *num1, double *num2)
{
    //获取运算信息
    printf("input num1、num2:");
    scanf("%lf %lf", num1, num2);
}
void print_help()
{
    printf("*******welcome*******\n");
    printf("*help:帮助          *\n");
    printf("*add:加法           *\n");
    printf("*sub:减法           *\n");
    printf("*mul:乘法           *\n");
    printf("*div:除法           *\n");
    printf("*q:退出             *\n");
    return;
}
double myadd(double num1, double num2)
{
    return num1 + num2;
}
double mysub(double num1, double num2)
{
    return num1 - num2;
}
double mymul(double num1, double num2)
{
    return num1 * num2;
}
double mydiv(double num1, double num2)
{
    return num1 / num2;
}
OP *funcfactory(char *op)
{
    if (!strcmp(op, "add"))
    {
        return myadd;
    }
    else if (!strcmp(op, "sub"))
    {
        return mysub;
    }
    else if (!strcmp(op, "mul"))
    {
        return mymul;
    }
    else if (!strcmp(op, "div"))
    {
        return mydiv;
    }
    else
    {
        return NULL;
    }
}
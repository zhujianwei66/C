/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-23 20:27:59
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-26 10:42:37
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

void myinput(char *op, int *num1, int *num2)
{
    //获取运算信息
    printf("please input operator commend:");
    scanf("%s", op);
    if (!strcmp(op, "q"))
        exit(-1);
    printf("input num1、num2:");
    scanf("%d %d", num1, num2);
}
int myadd(int num1, int num2)
{
    return num1 + num2;
}
int mysub(int num1, int num2)
{
    return num1 - num2;
}
int mymul(int num1, int num2)
{
    return num1 * num2;
}
int mydiv(int num1, int num2)
{
    return num1 / num2;
}
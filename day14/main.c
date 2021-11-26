/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-23 20:28:16
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-26 10:39:18
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

int main(int argc, char *argv[])
{
    char op[32] = "";
    int num1 = 0, num2 = 0;
    int ret = 0;
    while (1)
    {
        //欢迎语
        printf("****************welcome*****************\n");
        printf("*please input 'q' when you want to exit*\n");
        myinput(op, &num1, &num2);
        //printf("%s\n", op);
        //printf("%d %d \n", num1, num2);
        //调用运算函数
        if (!strcmp(op, "+"))
        {
            ret = myadd(num1, num2);
        }
        else if (!strcmp(op, "-"))
        {
            ret = mysub(num1, num2);
        }
        else if (!strcmp(op, "*"))
        {
            ret = mymul(num1, num2);
        }
        else if (!strcmp(op, "/"))
        {
            ret = mydiv(num1, num2);
        }
        //输出运算结果
        printf("ret = %d\n", ret);
    }
    return 0;
}
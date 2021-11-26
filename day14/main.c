/*
 * @Descripttion: 简易计算器
 * @version: 1.1
 * @Author: ZhuJianwei
 * @Date: 2021-11-23 20:28:16
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-26 11:35:27
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

int main(int argc, char *argv[])
{
    char op[32] = "";
    double num1 = 0, num2 = 0;
    double ret = 0;
    OP *func = NULL;
    print_help();
    while (1)
    {
        printf("please input operator commend:");
        scanf("%s", op);
        //printf("%s\n", op);
        if (!strcmp(op, "q"))
        {
            printf("exit!\n");
            break;
        }
        else if (!strcmp(op, "help"))
        {
            print_help();
            continue;
        }
        else
        {
            func = funcfactory(op);
            //获取需要计算的数字
            myinput(&num1, &num2);
            //printf("%lf %lf \n", num1, num2);

            //调用运算函数
            ret = func(num1, num2);
            //输出运算结果
            printf("%f %s %f = %f\n", num1, op, num2, ret);
        }
    }
    return 0;
}
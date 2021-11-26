/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-23 20:28:16
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-25 20:59:20
 */
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main(int argc, char *argv[])
{
    char *op;
    int num1 = 0, num2 = 0;
    while (1)
    {
        //欢迎语
        printf("******welcome*******\n");
        myinput(op, &num1, &num2);
        printf("%d %d %s", num1, num2, *op);
        //调用运算函数

        //输出运算结果
    }

    system("pause");
    return 0;
}
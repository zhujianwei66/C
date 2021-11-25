/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-23 20:28:16
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-23 20:59:04
 */
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main(int argc, char *argv[])
{
    char *M;
    int num1 = 0, num2 = 0;
    while (1)
    {
        //欢迎语
        printf("******welcome*******\n");
        myinput(M, &num1, &num2);
        printf("%s %d %d", *M, num1, num2);
        //调用运算函数

        //输出运算结果
    }

    system("pause");
    return 0;
}
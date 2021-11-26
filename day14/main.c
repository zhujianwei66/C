/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-23 20:28:16
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-26 11:16:36
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
    OP *func = NULL;
    while (1)
    {
        //欢迎语
        print_help();
        printf("please input operator commend:");
        scanf("%s", op);
        if (!strcmp(op, "q"))
        {
            printf("exit!\n");
            break;
        }
        else
        {
            func = funcfactory(op);
        }
        myinput(&num1, &num2);
        //printf("%s\n", op);
        //printf("%d %d \n", num1, num2);
        //调用运算函数
        ret = func(num1, num2);
        //输出运算结果
        printf("ret = %d\n", ret);
    }
    return 0;
}
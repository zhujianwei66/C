/*
 * @Descripttion: volatile关键字的使用，可以强制访问内存，不放入寄存器
 *                  作用：1.防止编译器优化
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-06 16:12:05
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-06 16:21:04
 */
#include"stdio.h"

int main(int argc, char* argv[])
{
    volatile int num = 10;
    num = 11;
    num = 12;
    num = 13;
    num = 14;
    printf("num = %d\n",num);
    return 0;
}
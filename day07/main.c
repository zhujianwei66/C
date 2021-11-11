/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-11 09:52:21
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-11 09:59:20
 */
#include "stdio.h"
extern int va;     //func1.c中的全局变量va = 7
extern int getG(); //func1.c中的全局函数返回值为 20
extern int getO(); //func2.c中的全局函数返回值为 18

int main(int argc, char *argv[])
{
    printf("%d * %d * %d = %d\n", va, getG(), getO(), va * getG() * getO());
    return 0;
}
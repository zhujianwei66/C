/*
 * @Descripttion: 线段树的学习，通过c语言实现
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-20 10:05:34
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-20 11:21:29
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a[2] = {1, 2};
    int i = 0;
    a[i++] = a[i];
    printf("%d %d", a[0], a[1]);
    system("pause");
    return 0;
}
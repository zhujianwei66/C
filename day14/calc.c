/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-23 20:27:59
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-23 22:19:21
 */
#include <stdio.h>
void myinput(char *M, int *num1, int *num2)
{
    //获取运算信息
    printf("input operator:");
    scanf("%c", M);
    //printf("%c", M);
    printf("input num1、num2:");
    scanf("%d %d", num1, num2);
    printf("%d %d \n", *num1, *num2);
}
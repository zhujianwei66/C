/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-05 10:02:51
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-05 10:16:12
 */
#include "stdio.h"

int main(int argc, char *argv[]){
    int num1 = 0;
    int num2 = 0;
    printf("请输入两个int型数字(逗号隔开)：\n");
    scanf("%d,%d",&num1,&num2);
    printf("您输入的是num1 = %d,num2 = %d",num1,num2);
    return 0;
}
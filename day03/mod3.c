/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-06 20:13:14
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-07 09:05:59
 */
#include"stdio.h"

int main(int argc, char* argv[])
{
    int num =0;
    printf("请输入一个可以整数：\n");
    scanf("%d",&num);
    getchar();
    if(num%3==0){
        printf("可以被3整除\n");
    }else{
        printf("不可以被3整除\n");
    }
    return 0;
}
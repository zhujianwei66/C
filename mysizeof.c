/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-04 19:33:43
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-04 20:33:54
 */
#include"stdio.h"

int main(int argc,char *agrv[]){
    char c;
    short s;
    int i;
    long l;
    float f;
    double d;

    printf("char is %d Bit\n",sizeof(c));
    printf("short is %d Bit\n",sizeof(s));
    printf("int is %d Bit\n",sizeof(i));
    printf("long is %d Bit\n",sizeof(l));
    printf("float is %d Bit\n",sizeof(l));
    printf("double is %d Bit\n",sizeof(l));
    return 0;
}
/*
 * @Descripttion: 
        1.数组名代表第一个数组元素的地址（数组名是符号常量）
        2.多文件编译应使用g++ file1.c file2.c
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-10 19:30:22
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-10 20:39:58
 */
#include "stdio.h"
int data = 13;

void test01();
extern void add_data(void); //让全局变量data+10,需要和01fun.c一起编译！！
void test02();

int main(int argc, char *argv[])
{
    test02();
    return 0;
}

void test02()
{
    printf("data = %d\n", data);
    add_data();
    printf("data = %d\n", data);
    return;
}
void test01()
{
    int arr[5] = {0};
    printf("%p\n", arr);
    printf("%p\n", arr[0]);
    return;
}
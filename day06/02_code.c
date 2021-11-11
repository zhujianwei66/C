/*
 * @Descripttion: 
        1.局部静态变量，生命周期为整个进程。且仅在第一次定义有效
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-10 20:49:45
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-10 21:45:50
 */
#include "stdio.h"

void func();
void test01();
static int static_glo_data = 10; //静态全局变量
int glo_data = 20;               //普通全局变量
void test02();

int main(int argc, char *argv[])
{
    test02();
    return 0;
}
void test02()
{

    return;
}
void test01()
{
    func();
    func();
    func();
    func();
    return;
}
void func()
{
    static int data = 0;
    data++;
    printf("data = %d \n", data);
    return;
}
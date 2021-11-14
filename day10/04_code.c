/*
 * @Descripttion: 
                1.结构体的位域：指定成员大小
                    没有非位域隔开的叫相邻位域---c标准里说明位域只能是unsign int，实践发现unsign char也可以
                    相邻位域可以压缩，但压缩的位数不能超过自身类型大小
                    不可对位域取地址
                    对位域赋值不可超过位域本身的宽度
                2.位域的另起一个存储单元
                3.无意义位段位域案例
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-14 19:39:26
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-14 20:19:48
 */
#include <stdio.h>

struct Data
{
    unsigned char a : 2;
    unsigned char b : 2;
    unsigned char c : 4;
};
struct Data2
{
    unsigned char a : 4;
    unsigned char : 0;
    unsigned char b : 4;
};
struct reg
{
    unsigned char addr : 2;
    unsigned char : 1; //无意义位段
    unsigned char opt : 2;
    unsigned char : 1;
    unsigned char data : 2;
};
void test01()
{
    printf("sizeof(Data) = %d\n", sizeof(struct Data));
    return;
}
void test02()
{
    printf("sizeof(Data) = %d\n", sizeof(struct Data2));
    return;
}
void test03()
{
    struct reg MYREG;
    MYREG.addr = 2;
    MYREG.data = 3;
    MYREG.opt = 1;
    //10 01 11
}
int main(int argc, char *argv[])
{
    test03();
    return 0;
}
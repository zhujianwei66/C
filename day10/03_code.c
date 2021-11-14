/*
 * @Descripttion: 
            1.结构体内存对齐
                结构体自动对齐规则:
                    1.确定分配单位（逻辑上一行分配多少字节）：
                        由结构体中最大的  基本类型   长度决定
                    2.确定成员的偏移量：
                        成员偏移量=成员自身类型的整数倍。不能存在已有成员之间
                    3.收尾工作
                        结构体的总大小=整行（分配单位）的整数倍
                结构体嵌套结构体自动对齐规则：
                    1.确定分配单位（逻辑上一行分配多少字节）：
                        由所有结构体中最大的  基本类型   长度决定
                    2.确定成员的偏移量：
                        普通成员偏移量=成员自身类型的整数倍。 不能存在已有成员之间
                        结构体成员偏移量 = 结构体的最大基本类型整数倍
                    3.收尾工作
                        结构体成员总大小 = 结构体的最大基本类型整数倍
                        结构体的总大小=整行（分配单位）的整数倍
                强制对齐：
                    #progma pack(value) 指定对齐值value 注意：value的值为1、2、4、8、16
                    1.确定分配单位（逻辑上一行分配多少字节）：
                        分配单位 = min（结构体中最大的基本类型，value）
                    2.确定成员的偏移量：
                        成员偏移量=成员自身类型的整数倍。不能存在已有成员之间
                    3.收尾工作
                        结构体的总大小=整行（分配单位）的整数倍
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-14 16:59:41
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-14 17:21:35
 */
#include <stdio.h>
struct Data1
{
    short a;
    int b;
    char c;
};
struct Data2
{
    char c;
    short a;
    int b;
};

void test01()
{
    printf("sizeof(struct Data1) = %d\n", sizeof(struct Data1));
    printf("sizeof(struct Data2) = %d\n", sizeof(struct Data2));
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}
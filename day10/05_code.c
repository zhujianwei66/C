/*
 * @Descripttion: 
            1.共用体:所有成员共享同一块空间,大小由最大成员确定
            2.成员能够操作的空间大小由成员自身大小决定
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-14 20:20:07
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-14 20:40:43
 */
#include <stdio.h>

union data
{
    char a;
    short b;
    int c;
};
void test01()
{
    union data d;
    d.a = 10;
    d.b = 20;
    d.c = 30;
    printf("%d\n", d.a + d.c + d.b);
    return;
}
void test02()
{
    union data d;
    d.c = 0x01020304;
    d.b = 0x0102;
    d.a = 0x01;
    printf("%#x\n", d.a + d.c + d.b); //0x0x1020203
    return;
}
int main(int argc, char *argv[])
{
    test02();
    return 0;
}
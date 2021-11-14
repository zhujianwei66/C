/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-14 19:28:02
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-14 19:31:27
 */
#include <stdio.h>
#pragma pack(2)

struct A
{
    char a;
    int b;
    short c;
};
void test01()
{
    printf("%d\n", sizeof(struct A));
    return;
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}
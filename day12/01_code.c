/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-16 15:38:17
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-16 15:51:22
 */
#include <stdio.h>
//#include <unistd.h> //window下用不了

void test01()
{
    //行刷新
    printf("hello world\n");
    while (1)
        ;
}
// void test02()
// {
//     //满刷新
//     int i = 0;
//     for (i = 0; i < 1000; i++)
//     {
//         printf("123456789");
//         usleep(20 * 1000);
//     }

//     while (1)
//         ;
// }
void test03()
{
    //强制刷新
    printf("hello world");
    fflush(stdout);

    while (1)
        ;
}
void test04()
{
    //关闭刷新
    printf("hello world");
    return;
}
int main(int argc, char *argv[])
{
    test04();
    return 0;
}
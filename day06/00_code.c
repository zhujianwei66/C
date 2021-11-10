/*
 * @Descripttion: 二维数组遍历
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-10 10:09:52
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-10 11:21:51
 */
#include "stdio.h"
void test01()
{
    char arr[5][128] = {"hello", "world", "hahaha", "xixixi", "lalala"};
    int row = sizeof(arr) / sizeof(arr[0]);

    int i = 0;
    for (i = 0; i < row; i++)
    {
        printf("%s\n", arr[i]);
    }
}
test02()
{

    char arr[5][128] = {"hello", "world", "hahaha", "xixixi", "lalala"};
    int row = sizeof(arr) / sizeof(arr[0]);
    int col = sizeof(arr[0]) / sizeof(arr[0][0]);

    printf("请输入%d个字符串:\n", row);
    int i = 0;
    for (i = 0; i < row; i++)
    {
        scanf("%s", arr[0]);
    }
    printf("---------输入的字符串分别为：-------------\n");

    for (i = 0; i < row; i++)
    {
        printf("%s\n", arr[i]);
    }
}
int main(int argc, char *argv[])
{
    test02();
    return 0;
}
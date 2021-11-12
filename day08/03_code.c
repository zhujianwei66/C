/*
 * @Descripttion:动态内存管理
            1.简单的动态变量申请
            2.简单的动态数组申请
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-12 20:35:37
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-12 21:08:12
 */
#include <stdio.h>
#include <stdlib.h>
void test01()
{
    int *p = NULL;
    p = (int *)malloc(sizeof(int));
    if (p == NULL)
    {
        return;
    }
    *p = 100;
    printf("*p = %d\n", *p);
    free(p);
    return;
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}
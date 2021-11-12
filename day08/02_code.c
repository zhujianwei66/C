/*
 * @Descripttion:函数指针使用案例1 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-12 20:25:52
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-12 20:34:34
 */
#include <stdio.h>

int my_add(int x, int y)
{
    return x + y;
}
int my_sub(int x, int y)
{
    return x - y;
}
int my_mul(int x, int y)
{
    return x * y;
}
int my_div(int x, int y)
{
    return x / y;
}
int my_calc(int x, int y, int (*p)(int, int))
{
    return p(x, y);
}

int main(int argc, char const *argv[])
{
    printf("ret = %d\n", my_calc(57, 34, my_add));
    printf("ret = %d\n", my_calc(57, 34, my_sub));
    printf("ret = %d\n", my_calc(57, 34, my_mul));
    printf("ret = %d\n", my_calc(57, 34, my_div));
    return 0;
}

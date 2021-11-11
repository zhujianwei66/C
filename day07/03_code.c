/*
 * @Descripttion: 
            宏定义注意事项，只作代码替换，不能保证参数的完整性
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-11 12:55:49
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-11 13:11:15
 */
#include "stdio.h"
#define PI 3.14
#define FUNC1(a, b) a *b
#define FUNC2(a, b) ((a) * (b))

int main(int argc, char *argv[])
{
    printf("PI = %lf\n", PI);
    printf("FUNC1(10+20,10+20) = %d\n", FUNC1(10 + 20, 10 + 20));
    printf("FUNC2(10+20,10+20) = %d\n", FUNC2(10 + 20, 10 + 20));
    printf("FUNC1(FUNC2(10+20,10+20),FUNC1(10+20,10+20))) = %d\n", FUNC1(FUNC2(10 + 20, 10 + 20), FUNC1(10 + 20, 10 + 20)));
    return 0;
}
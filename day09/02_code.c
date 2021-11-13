/*
 * @Descripttion: 
            const变量详解
                1.const修饰普通变量为只读变量
                2.const修饰* 在使用中（常量指针）
                    *p是只读，无法通过*p修改所指向的值
                    p可读可写，可以让p指向其他空间地址
                3.const修饰指针变量  在使用中（指针常量）
                    p只读，初始化后无法修改p指向的地址
                    *p可读可写，p指向的地址内容可以修改
                4.const既修饰*，也修饰指针变量
                    p和*p均为只读
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-13 21:54:22
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-13 22:42:09
 */
#include <stdio.h>

void test01();
void test02();
void test03();
void test04();
int main(int argc, char *argv[])
{
    test03();
    return 0;
}
void test04()
{
    int num = 10;
    int num2 = 11;
    //两者只读
    const int *const p = num;
    //p = &num2;//无法修改
    //*p = 13;//无法修改
    return;
}
void test03()
{
    int num = 100;
    int num2 = 200;
    int *const p = &num; //指针常量
    printf("*p = %d\n", *p);
    //p=&num2; //p只读不可写
    *p = 1000; //*p可读可写
    printf("*p = %d\n", *p);
    return;
}
void test01()
{
    const int num = 10; //只读变量，只能初始化，不能赋值
    //num=100;
    printf("%d\n", num);
}
void test02()
{
    int num = 10;
    const int *p = &num; //常量指针
    //*p = 100;//*p只读不可写
    printf("*p = %d\n", *p);
    int num2 = 100;
    p = &num2;
    printf("*p = %d\n", *p);
    return;
}
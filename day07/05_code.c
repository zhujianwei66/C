/*
 * @Descripttion: 
        1.指针变量的大小32位为4，64位为8
        2.指针变量的使用
        3.指针变量指向的类型决定了取值的宽度
        4.指针变量指向的类型决定了+1的跨度
        5.综合案例:取任意合法地址的内容
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-11 17:42:24
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-11 20:29:47
 */
#include <stdio.h>
void test01()
{
    printf("sizeof(int*) = %d\n", sizeof(int *));
    printf("sizeof(char*) = %d\n", sizeof(char *));
    printf("sizeof(short*) = %d\n", sizeof(short *));
    printf("sizeof(long*) = %d\n", sizeof(long *));
    printf("sizeof(long long*) = %d\n", sizeof(long long *));
    printf("sizeof(float*) = %d\n", sizeof(float *));
    printf("sizeof(double*) = %d\n", sizeof(double *));
    return;
}
void test02()
{
    int num = 0;
    int *p = NULL;
    p = &num;
    *p = 10;
    printf("&p = %p\n", p); //使用%p或%u打印编号
    printf("num = %d \n", num);
    return;
}
int test03()
{
    int num = 0x01020304;
    int *p1 = &num;
    short *p2 = (short *)&num; //强转防止报错，无决定性意义
    char *p3 = (char *)&num;
    printf("int *p1 = %#x\n", *p1);   //0x01020304
    printf("short *p2 = %#x\n", *p2); //0x304
    printf("char *p3 = %#x\n", *p3);  //0x4
    return;
}
void test04()
{
    int *p1 = NULL;
    short *p2 = NULL;
    char *p3 = NULL;

    printf("p1 = %p\n", p1);
    printf("p1+1 = %p\n", p1 + 1); //+4
    printf("p2 = %p\n", p2);
    printf("p2+1 = %p\n", p2 + 1); //+2
    printf("p3 = %p\n", p3);
    printf("p3+1 = %p\n", p3 + 1); //+1
    return;
}
void test05()
{
    int num = 0x01020304;
    short *p1 = (short *)&num;
    char *p2 = (char *)&num;
    p2 += 2;
    printf("*(p1+1) = %#x \n", *(p1 + 1)); //取出0102
    printf("*(p2+2) = %#x \n", *p2);       //取出02

    return;
}
int main(int argc, char *argv[])
{
    test05();
    return 0;
}
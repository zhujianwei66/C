/*
 * @Descripttion: 
        1.指针变量的大小32位为4，64位为8
        2.指针变量的使用
        3.指针变量指向的类型决定了取值的宽度
        4.指针变量指向的类型决定了+1的跨度
        5.综合案例:取任意合法地址的内容
        6.万能指针 void *
        注意：不可直接对void *解引用，不可对未初始化的指针操作，初始化为空也不可操作，指针不要越界访问非法内存。
        char * ch = 'a';int *p = &ch; *p;//越界访问
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-11 17:42:24
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-11 21:50:01
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
    char *p3 = (char *)&num;
    short *p4 = (short *)&num;

    printf("*(p1+1) = %#x \n", *(p1 + 1)); //取出0102
    p2 += 2;
    printf("*(p2+2) = %#x \n", *p2); //取出02
    p3 += 1;
    printf("*(short*)p3 = %#x \n", *(short *)p3);                          //取出0203
    printf("*(short*)((char*)p4+1) = %#x \n", *(short *)((char *)p4 + 1)); //取出0203
    return;
}
void test06()
{
    void *p = NULL;
    int num = 10;
    char ch = 'a';
    short sh = 1;
    p = &num;
    printf("%d \n", *(int *)p);
    p = &ch;
    printf("%c \n", *(char *)p);
    p = &sh;
    printf("%d \n", *(short *)p);
    return;
}
int main(int argc, char *argv[])
{
    test06();
    return 0;
}
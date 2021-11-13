/*
 * @Descripttion:动态内存管理malloc free
            1.简单的动态变量申请malloc
            2.简单的动态数组申请malloc
            3.简单的动态数组申请calloc
            4.动态数组的追加realloc
            5.回顾内存知识
            6.free的本质是释放堆区空间权限，具体是否清除堆区空间数据不确定
            注意：malloc申请到的空间不会清零,calloc会清零
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-12 20:35:37
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-13 12:51:29
 */
#include <stdio.h>
#include <stdlib.h> //使用malloc函数需要包含的库
#include <string.h> //memset函数

void test01();
void test02();
void *get_addr(int len, int size);       //用malloc申请空间，获取地址
void get_int_array(int *arr, int len);   //获取数组元素
void print_int_array(int *arr, int len); //打印数组元素
void test03();
void *resize_int_array(int *arr, int newSize);
void test04();
void test05();
void test06();

int main(int argc, char *argv[])
{
    test06();
    return 0;
}
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
void test02()
{
    int len = 0;
    printf("请输入数组的大小：\n");
    scanf("%d", &len);

    int *p = (int *)malloc(len * sizeof(int)); //申请空间
    //判断空间是否申请成功
    if (p == NULL)
        return;
    //对申请到的空间置空
    memset(p, 0, len * sizeof(int));
    //获取输入并写入申请到的空间
    printf("请输入数组的内容：\n");
    //输出动态申请的数组
    int i = 0;
    for (i = 0; i < len; i++)
    {
        scanf("%d", p + i);
    }
    printf("获取到的数组如下：\n");
    for (i = 0; i < len; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
    //释放申请到的空间
    free(p);
    return;
}
void *get_addr(int len, int size)
{
    return calloc(len, size);
}
void get_int_array(int *arr, int len)
{
    printf("请输入%d个整形数据，空格隔开\n", len);
    int i = 0;
    for (i = 0; i < len; i++)
    {
        scanf("%d", arr + i);
    }
    return;
}
void print_int_array(int *arr, int len)
{
    int i = 0;
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}
void test03()
{
    int len = 0;
    printf("请输入数组的大小：\n");
    scanf("%d", &len);
    int *p = (int *)get_addr(len, sizeof(int));
    if (p == NULL)
    {
        return;
    }
    get_int_array(p, len);
    printf("获取到的数组为：\n");
    print_int_array(p, len);
    free(p);
}

void test04()
{
    int len = 0;
    printf("请输入数组的大小：\n");
    scanf("%d", &len);
    int *p = (int *)get_addr(len, sizeof(int));
    if (p == NULL)
    {
        return;
    }
    get_int_array(p, len);
    printf("获取到的数组为：\n");
    print_int_array(p, len);

    //追加realloc
    int Size = 0;
    printf("请输入需要追加的元素个数：\n");
    scanf("%d", &Size);
    //重置数组大小
    p = (int *)resize_int_array(p, Size + len);
    //追加数组元素
    if (Size > 0)
        get_int_array(p + len, Size);
    //打印数组元素
    printf("新的数组为：\n");
    print_int_array(p, Size + len);

    free(p);
    return;
}
void test05()
{
    //回顾内存相关知识点
    //在栈区保存变量str1，共12个字节
    char str1[] = "hello world";
    //在字符常量区保存"hello world",用str2保存其地址
    char *str2 = "hello world";
    //在堆区申请空间保存hello，用str3保存
    char *str3 = (char *)calloc(1, 128);
    strcpy(str3, str2);
    printf("%s\n", str3);
    free(str3);
    return;
}
void *resize_int_array(int *arr, int newSize)
{
    return realloc(arr, newSize * sizeof(int));
}
void test06()
{
    char *p = (char *)calloc(1, 128);
    strcpy(p, "test06");
    free(p);
    printf("%s \n", p);
    return;
}
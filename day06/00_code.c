/*
 * @Descripttion: 
        1.二维数组遍历
        2.多字符串读取
        3.函数的调用
        4.给函数传入数组参数
        5.字符数组作为函数参数
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-10 10:09:52
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-10 17:27:17
 */
#include "stdio.h"
#include "string.h"

//函数声明
void test01();
void test02();
int my_add(int num1, int num2); //两个数相加
void test03();
void inputIntarray(int arr[], int arrSize);  //从键盘输入中获取数据
void printfIntarray(int arr[], int arrSize); //输出数组
void sortIntarray(int arr[], int arrSize);   //对整形数组排序
void test04();
void myGetstr(char str[], int strSize);
int myGetSize(char str[]);
void test05();

//函数入口
int main(int argc, char *argv[])
{
    test05();
    return 0;
}

//函数实现
int myGetSize(char str[])
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}
void myGetStr(char str[], int strSize)
{
    printf("请输入一个字符串：\n");
    fgets(str, strSize, stdin);
    //去掉空格
    str[strlen(str) - 1] = '\0';
    return;
}
void inputIntarray(int arr[], int arrSize)
{
    int i = 0;
    for (i = 0; i < arrSize; i++)
    {
        scanf("%d", &arr[i]);
    }
    return;
}
void printfIntarray(int arr[], int arrSize)
{
    int i = 0;
    for (i = 0; i < arrSize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}
void sortIntarray(int arr[], int arrSize)
{
    int i = 0;
    //使用选择法排序
    for (i = 0; i < arrSize - 1; i++)
    {
        int min_flag = i; //假设最小值为第i个
        int j = 0;
        for (j = i + 1; j < arrSize; j++)
        {
            if (arr[min_flag] > arr[j])
            {
                min_flag = j;
            }
        }
        if (min_flag != i) //如果不是最初认定的最小值就交换
        {
            int temp = arr[i];
            arr[i] = arr[min_flag];
            arr[min_flag] = temp;
        }
    }

    return;
}
int my_add(int num1, int num2)
{
    return num1 + num2;
}
void test01()
{
    char arr[5][128] = {"hello", "world", "hahaha", "xixixi", "lalala"};
    int row = sizeof(arr) / sizeof(arr[0]);

    int i = 0;
    for (i = 0; i < row; i++)
    {
        printf("%s\n", arr[i]);
    }
    return;
}
void test02()
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
    return;
}
void test03()
{
    int data1 = 10;
    int data2 = 21;

    int ret = 0;
    ret = my_add(data1, data2);
    printf("ret = %d\n", ret);
    return;
}
void test04()
{
    //定义一个整形数组
    int arr[5] = {0};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    //获取键盘输入整形数组的具体值
    printf("请输入%d个整形数值\n", arrSize);
    inputIntarray(arr, arrSize);

    //对整形数组进行排序
    sortIntarray(arr, arrSize);
    //输出整形数组
    printf("排序后数组为：\n");
    printfIntarray(arr, arrSize);
    return;
}
void test05()
{
    //定义字符数组
    char str[128] = "";
    int strSize = sizeof(str);
    //获取字符数组
    myGetStr(str, strSize); //注意：不能在函数内求str大小，编译器会将数组形参优化为指针
    //计算字符数组的长度
    printf("字符串长度为：%d\n", myGetSize(str));
    return;
}
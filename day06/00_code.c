/*
 * @Descripttion: 
        1.二维数组遍历
        2.多字符串读取
        3.函数的调用
        4.给函数传入数组参数
        
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-10 10:09:52
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-10 16:40:44
 */
#include "stdio.h"

//函数声明
void test01();
void test02();
int my_add(int num1, int num2); //两个数相加
void test03();
void inputIntarray(int arr[], int arrSize);  //从键盘输入中获取数据
void printfIntarray(int arr[], int arrSize); //输出数组
void sortIntarray(int arr[], int arrSize);
void test04();

//函数入口
int main(int argc, char *argv[])
{
    test04();
    return 0;
}

//函数实现
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
    for (i = 0; i < arrSize; i++)
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
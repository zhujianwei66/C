/*
 * @Descripttion: 
            1.结构体指针
                调用成员方法：(*p). 或  p->
                符号左边是变量就使用. 左边是结构体地址就使用->
            2.结构体数组元素的指针    struct stu (*p)[5]
            
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-14 11:38:14
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-14 13:03:20
 */
#include <stdio.h>
#include <string.h>

struct stu
{
    int num;
    char name[32];
};
void test01()
{
    struct stu lucy = {1, "lucy"};
    struct stu *p = &lucy;

    printf("%d %s\n", lucy.num, lucy.name);
    printf("%d %s\n", (*p).num, (*p).name);
    printf("%d %s\n", p->num, p->name);
}
void get_stu_array(struct stu *arr, int n)
{
    printf("请输入%d个学生的信息num name\n", n);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("请输入第%d个学生的信息：", i + 1);
        scanf("%d %s", &arr[i].num, arr[i].name);
    }
    return;
}
void print_stu_array(struct stu *arr, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("第%d个学生的信息为：%d,%s\n", i + 1, (arr + i)->num, (arr + i)->name);
    }
    return;
}
void sort_stu_array(struct stu *arr, int n)
{
    int i = 0;
    for (; i < n - 1; i++)
    {
        int min = i;
        int j = i + 1;
        for (; j < n; j++)
        {
            if (arr[j].num < arr[min].num)
            {
                min = j;
            }
        }
        if (min != i)
        {
            struct stu temp;
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    return;
}
void test02()
{
    struct stu edu[5];
    memset(edu, 0, sizeof(edu));
    int len = sizeof(edu) / sizeof(edu[0]);

    get_stu_array(edu, len);
    sort_stu_array(edu, len);
    print_stu_array(edu, len);
    return;
}
int main(int argc, char *argv[])
{
    test02();
    return 0;
}
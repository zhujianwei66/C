/*
 * @Descripttion: 
            1.结构体的指针成员
            2.结构体指针成员指向堆区
            3.结构体在堆区，指针成员也指向堆区
            4.结构体指针数组在堆区，结构体在堆区，指针成员在堆区
            
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-14 13:04:34
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-14 16:46:57
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu
{
    int num;
    char *name; //指针成员
};

void test01()
{
    struct stu lucy = {100, "hello world"}; //此初始化会将hello world字符串存放再字符常量区，只读不可写。
    printf("%d \n", sizeof(lucy));
    //lucy.name[0] = 'H';//段错误
    printf("%d %s\n", lucy.num, lucy.name);
    return;
}
void test02()
{
    struct stu lucy;
    lucy.num = 100;
    lucy.name = (char *)calloc(1, 128);
    //先指向calloc申请的空间，下面赋值让指针指向字符常量区，内存泄漏
    //lucy.name = "hello world"//此处不可行，name原指向内存泄漏
    strcpy(lucy.name, "hello world");
    printf("%d %s\n", lucy.num, lucy.name);

    //数据存放再堆区可以修改字符串的值
    lucy.name[0] = 'H';
    printf("%s\n", lucy.name);

    //一定要记得释放空间
    if (lucy.name != NULL)
    {
        free(lucy.name);
        lucy.name = NULL;
    }
    return;
}
void test03()
{
    struct stu *p = NULL;
    //为结构体申请堆区空间
    p = (struct stu *)calloc(1, sizeof(struct stu));
    //为结构体成员申请堆区空间
    p->name = (char *)calloc(1, 128);
    //为结构体成员赋值
    p->num = 103;
    strcpy(p->name, "hello world");
    //使用完之后释放堆区空间，从里到外
    printf("%d %s\n", p->num, p->name);
    if (p->name != NULL)
    {
        free(p->name);
        p->name = NULL;
    }
    if (p != NULL)
    {
        free(p);
        p = NULL;
    }
    return;
}
void test04()
{
    struct stu **arr = NULL; //结构体数组指针初始化
    arr = (struct stu **)calloc(5, sizeof(struct stu *));
    //结构体数组指针内的元素申请堆区空间，并给每个结构体的name申请堆区空间
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        arr[i] = (struct stu *)calloc(1, sizeof(struct stu));
        arr[i]->name = (char *)calloc(1, 128);
        //printf("请输入第%d个学生的信息:", i + 1);
        //scanf("%d %s", &arr[i]->num, arr[i]->name);
        sprintf(arr[i]->name, "学生%d", i + 1);
        arr[i]->num = 101 + i;
        //*(arr+i)->num=101+i//这是错误的要考虑运算符的优先级
        //(*(arr + i))->num//应当这样使用！！！
    }
    //输出获取的数据
    for (i = 0; i < 5; i++)
    {
        printf("%d %s\n", arr[i]->num, arr[i]->name);
    }
    //释放堆区空间
    if (arr != NULL)
    {
        for (i = 0; i < 5; i++)
        {
            if (arr[i] != NULL)
            {
                if (arr[i]->name != NULL)
                {
                    free(arr[i]->name);
                    arr[i]->name = NULL;
                }
                free(arr[i]);
                arr[i] = NULL;
            }
        }
        free(arr);
        arr = NULL;
    }
    return;
}
int main(int argc, char *argv[])
{
    test04();
    return 0;
}
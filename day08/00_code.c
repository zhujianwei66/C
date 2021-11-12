/*
 * @Descripttion: 
            1.字符串数组
            2.指针数组
                字符指针数组保存的是字符串的地址，二维字符数组保存的是每个字符串
            3.数组首元素地址和数组首地址的区别：
                数组的首元素地址：arr
                数组的首地址：&arr（并非真的取地址，只是表示格式）&arr+1将会跳到数组尾部地址
                对数组首地址解引用可得数组首元素地址
            4.数组指针
                本质是指针，保存的数组的首地址
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-12 10:51:18
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-12 12:38:44
 */
#include <stdio.h>

void test01()
{
    char *p = "hello world!";
    printf("%s \n", p);
    printf("*(p+6) = %c \n", *(p + 6));
    printf("p[6] = %c \n", p[6]);
    return;
}
void test02()
{
    int num1 = 10;
    int num2 = 20;
    int num3 = 30;
    int num4 = 40;
    int num5 = 50;
    int *arr[5] = {&num1, &num2, &num3, &num4, &num5};
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("%d ", *arr[i]);
    }
    printf("\n");
    return;
}
void test03()
{
    int arr[5] = {1, 2, 3, 4, 5};

    printf("arr = %p\n", arr); //首元素地址
    printf("arr+1 = %p\n", arr + 1);
    return;
}
void test04()
{
    int arr[5] = {1, 2, 3, 4, 5};

    int(*p)[5] = NULL;
    printf("sizeof(p) = %d\n", sizeof(p));
    printf("p = %x\n", p);
    printf("p+1 = %x\n", p + 1);

    p = &arr; //*p = *&arr = arr
    printf("arr[2] = %d\n", *(*p + 2));
    printf("arr[2] = %d\n", p[0][2]);
    return;
}
int main(int argc, char *argv[])
{
    test04();
    return 0;
}
/*
 * @Descripttion:
            1.深入理解二维数组：
                二维数组名代表的是第0行的行地址，+1代表跳过一个行
                对行地址解引用代表当前行第0列的列地址
            2.二维数组与一维数组指针的关系
                保证数组指针的[]内值和arr第二维值相等，数组指针完全等价二维数组
            3.多维数组的物理存储
            4.指针作为函数的参数，当需要在函数内部修改外部的值时使用
            5.一维数组作为函数的参数，会被编译器优化为一级指针变量
            6.n维数组作为函数的参数，会被编译器优化为n-1维数组指针
            7.指针作为函数的返回值
            8.函数指针：本质是指针，保存的是函数的入口地址
                    注意:对函数指针+1无意义
                         对函数指针解引用无意义
                         函数指针变量比较大小无意义
                         函数指针可以赋值，
                         函数指针可以判断相等
            9.通过函数入口地址调用函数,linux的漏洞
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-12 15:24:20
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-12 16:46:48
 */

#include <stdio.h>

void test01()
{
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    //对二维数组的取操作
    //1.arr[1]   代表第1行的首元素地址
    //2.&arr[1]  代表第1行的行地址
    //3.*arr+1   代表第0行第1列的地址
    //4.arr[1]+2 代表第1行第2列的地址
    //**arr      代表第0行第0列的元素
    return;
}
void test03()
{
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int row = sizeof(arr) / sizeof(arr[0]);
    int col = sizeof(arr[0]) / sizeof(arr[0][0]);

    int *p = &arr[0][0];
    int i = 0;
    for (i = 0; i < row * col; i++) //通过一维指针依然可以遍历二维数组，说明二维数组的物理存储是一维连续的
    {
        printf("%d ", p[i]);
    }
    printf("\n");
    return;
}
void set_data(int *p)
{
    *p = 10; //修改对应地址中的内容
    return;
}
void test04()
{
    int num = 0;
    printf("%d \n", num);
    set_data(&num);
    printf("%d \n", num);
    return;
}
void print_int_array(int *p, int size)
{
    int i = 0;
    //一维数组作为函数的参数，会被编译器优化为一级指针变量
    printf("sizeof(arr[%d]) = %d\n", size, sizeof(p));

    for (i = 0; i < size; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
    return;
}
void test05()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("n = %d \n", n);
    print_int_array(arr, n);
    return;
}
void print_int_two_array(int (*arr)[4], int row, int col)
{
    printf("szieof(arr) = %d\n", sizeof(arr)); //8B
    int i = 0;
    for (i = 0; i < row; i++)
    {
        int j = 0;
        for (j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
            // printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    return;
}
void test06()
{
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; //二维数组
    int row = sizeof(arr) / sizeof(arr[0]);
    int col = sizeof(arr[0]) / sizeof(arr[0][0]);

    printf("sizeof(arr) = %d \n", sizeof(arr)); //48B
    print_int_two_array(arr, row, col);
    return;
}
int *get_addr()
{
    static int num = 10;
    return &num; //注意返回局部变量的地址，最终结果不确定
}
void get_addr2(int **q)
{
    static int num2 = 20;
    *q = &num2;
    return;
}
void test07()
{
    int *p1 = NULL;
    int *p2 = NULL;
    p1 = get_addr();
    get_addr2(&p2);
    printf("%d\n", *p1);
    printf("%d\n", *p2);
    return;
}
int my_add(int x, int y)
{
    return x + y;
}
void test08()
{
    int (*p1)(int, int) = NULL;
    typedef (*MY_FUNC_TYPE)(int, int);

    MY_FUNC_TYPE p2 = my_add;
    p1 = my_add;

    printf("sizeof(p1) = %d\n", sizeof(p1));
    printf("sizeof(p2) = %d\n", sizeof(p2));

    printf("p1(1,2) = %d\n", p1(1, 2));
    printf("p2(1,2) = %d\n", p2(1, 2));
    return;
}
void test09()
{
    printf("my_add = %p\n", my_add);
    int ret = ((int (*)(int, int))(0x40097b))(10, 20);
    printf("ret = %d\n", ret);
    return;
}
int main(int argc, char const *argv[])
{
    test09();
    return 0;
}

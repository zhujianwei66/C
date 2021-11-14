/*
 * @Descripttion: 
            1.结构体：成员拥有独立空间
                1.结构体定义方式：（
                    先定义结构体类型，再定义结构体变量，推荐
                    定义结构体类型的同时定义结构体变量，不推荐
                    定义一次性结构体类型
                2.结构体变量的初始化：结构体初始化需要遵循结构体成员的次序和类型
                3.结构体清零需要使用memset函数,并键盘输入给结构体的成员赋值
                4.单独操作结构体成员
                5.相同类型结构体之间的赋值
                6.结构体嵌套结构体
                7.结构体数组，本质是数组，元素是结构体
                    
                注意：
                    定义结构体类型，系统不分配空间，定义时不可给结构体成员赋值
                    访问结构体成员，必须遵循成员自身的类型
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-14 09:44:08
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-14 10:12:25
 */
#include <stdio.h>
#include <string.h>

struct student
{
    int num;       //结构体成员
    char name[32]; //结构体成员
};                 //先定义结构类型

struct teacher
{
    int num;
    char name[32];
} jack; //定义结构体同时定义结构体变量，可同时定义多个变量

struct //一次性结构体，无结构体名
{
    int num;
    char name[32];
} bob;

void test01()
{
    struct student lucy;
    printf("##%d %s##\n", lucy.num, lucy.name);
    //jack
    //bobo

    return;
}
void test02()
{
    //结构体初始化需要遵循结构体成员的次序和类型
    struct student lucy = {100, "lucy"};
    printf("%d %s\n", lucy.num, lucy.name);
    bob.num = 10;
    strcpy(bob.name, "Bob");
    printf("%d %s\n", bob.num, bob.name);
    jack.num = 50;
    strcpy(jack.name, "Jack");
    printf("%d %s\n", jack.num, jack.name);
    return;
}
void test03()
{
    struct student lucy;
    memset(&lucy, 0, sizeof(lucy));
    printf("##%d##%s##\n", lucy.num, lucy.name);
    printf("请输入num name\n");
    scanf("%d %s", &lucy.num, lucy.name);
    printf("##%d##%s##\n", lucy.num, lucy.name);
    return;
}
void test04()
{
    struct student lucy = {10, "luvy"};
    lucy.num += 100;
    strcpy(lucy.name, "lucy");
    printf("##%d##%s##\n", lucy.num, lucy.name);
    return;
}
void test05()
{
    struct student lucy = {10, "lucy"};
    struct student lucy2;
#if 0
    //方式一：逐个成员赋值
    lucy2.num = lucy.num;
    strcpy(lucy2.name, lucy.name);
#elif 1
    //方式二：相同变量之间可以直接赋值，推荐
    lucy2 = lucy;
#else
    //方式三：直接对内存拷贝
    memcpy(&lucy2, &lucy, sizeof(lucy));
#endif
    printf("##%d##%s##\n", lucy2.num, lucy2.name);

    return;
}

struct Date //日期
{
    int year;
    int month;
    int day;
};
struct worker //员工
{
    int number;
    char name[32];
    struct Date work_date;
};

void test06()
{
    struct worker jack = {100, "jack", {2021, 11, 14}};
    printf("%d %s\n", jack.number, jack.name);
    //结构体嵌套结构体，需要访问到最底层
    printf("%d %d %d\n", jack.work_date.year, jack.work_date.month, jack.work_date.day);

    return;
}
void test07()
{
    //结构体数组
    struct student stu[2] = {{1, "lucy"}, {2, "mark"}};
    int len = sizeof(stu) / sizeof(stu[0]);
    int i = 0;
    for (i = 0; i < len; i++)
    {
        printf("%d %s\n", stu[i].num, stu[i].name);
    }
    return;
}
void test08()
{
    //结构体数组获取键盘输入
    struct student stu[2];
    memset(stu, 0, sizeof(stu)); //数组内存清零
    int len = sizeof(stu) / sizeof(stu[0]);
    int i = 0;
    for (i = 0; i < len; i++)
    {
        printf("请输入num name：");
        scanf("%d %s", &stu[i].num, stu[i].name);
    }
    printf("获取到的数据如下：\n");

    for (i = 0; i < len; i++)
    {
        printf("%d %s\n", stu[i].num, stu[i].name);
    }
    return;
}
int main(int argc, char *argv[])
{
    test08();
    return 0;
}

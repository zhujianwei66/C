/*
 * @Descripttion: 
            1.链表
            2.给结构体区别名

 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-15 08:56:52
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-15 09:48:45
 */
#include <stdio.h>
/*
1.数组和链表的优缺点
静态数组：int arr[5];
        必须事先确定数组元素的个数，过多容易浪费，过少容易溢出；
        删除插入数据效率低；
动态数组：
        不需要事先直到数组元素的个数，在使用中动态申请；
        删除插入数据效率低；
数组优点：遍历元素效率高
链表：不需要事先直到数据的个数，在使用中动态申请，插入删除不需要移动数据
链表缺点：遍历效率低
2.链表的概述
链表是由一个个节点组成，节点没有名字，每个节点从堆区动态申请，节点间物理空间是非连续的，
但是每个节点通过指针域保存下一个节点的位置达到逻辑上连续。
3.静态链表

*/
struct NODE
{
    //数据域
    int num;
    char name[32];

    //指针域
    struct NODE *next;
};
void test01()
{
    struct NODE node1 = {101, "节点1", NULL};
    struct NODE node2 = {102, "节点2", NULL};
    struct NODE node3 = {103, "节点3", NULL};
    struct NODE node4 = {104, "节点4", NULL};
    struct NODE node5 = {105, "节点5", NULL};

    struct NODE *head = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    struct NODE *p = head;
    while (p != NULL)
    {
        printf("%d %s\n", p->num, p->name);
        p = p->next;
    }
    return;
}
typedef struct name_name_name_name
{
    int a;
    char b;
} DATA1; //1

struct name_name_name_name2
{
    int a;
    char b;
};
typedef struct name_name_name_name2 DATA2; //2

typedef struct name_name_name_name3
{
    int a;
    char b;
} D_TYPE, *D_POINTER; //3

int test02()
{
    struct name_name_name_name ob1;
    DATA1 ob2;
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}
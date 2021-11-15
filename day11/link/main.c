/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-15 14:45:41
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-15 21:56:03
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "link.h"
STU *head = NULL; //头指针初始化为空
void help(void)
{
    printf("***************************\n");
    printf("*help:帮助信息            *\n");
    printf("*insert: 插入链表节点     *\n"); //存在问题
    printf("*print:遍历链表节点       *\n");
    printf("*search:查询链表某个节点  *\n");
    printf("*delete:删除链表某个节点  *\n");
    printf("*free:释放整个链表        *\n");
    printf("*reverse:翻转链表         *\n");
    printf("*sort:链表排序            *\n"); //存在问题
    printf("*quit:退出程序            *\n");
    printf("***************************\n");
    return;
}
int main(int argc, char *argv[])
{
    help();
    while (1)
    {
        char cmd[128] = "";
        printf("请输入操作命令：");
        scanf("%s", cmd);
        if (strcmp(cmd, "help") == 0)
        {
            help();
        }
        else if (strcmp(cmd, "insert") == 0)
        {
            STU tmp;
            printf("请输入需要插入的学生信息num score name :");
            scanf("%d %f %s", &tmp.num, &tmp.score, tmp.name);
            //printf("%d %s %.1f", tmp.num, tmp.name, tmp.score);
            //将节点插入到链表中
            head = insert_link(head, tmp);
        }
        else if (strcmp(cmd, "print") == 0)
        {
            print_link(head);
        }
        else if (strcmp(cmd, "search") == 0)
        {
            printf("请输入要查找的学生名字:\n");
            char name[128] = "";
            scanf("%s", name);
            STU *ret = search_link(head, name);
            if (ret == NULL) //未找到
            {
                printf("查无此人\n");
            }
            else
            {
                printf("查询结果：%d %.2f %s\n", ret->num, ret->score, ret->name);
            }
        }
        else if (strcmp(cmd, "delete") == 0)
        {
            printf("请输入要删除的学号：");
            int num = -1;
            scanf("%d", &num);
            head = delete_link(head, num);
        }
        else if (strcmp(cmd, "free") == 0)
        {
            head = free_link(head);
        }
        else if (strcmp(cmd, "quit") == 0)
        {
            head = free_link(head);
            printf("quit\n");
            break;
        }
        else if (strcmp(cmd, "reverse") == 0)
        {
            head = reverse_link(head);
        }
        else if (strcmp(cmd, "sort") == 0)
        {
            sort_link(head);
        }
    }
    return 0;
}
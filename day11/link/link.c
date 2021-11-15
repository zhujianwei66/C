/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-15 14:45:27
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-15 22:32:16
 */
#include <stdlib.h>
#include "link.h"
#include <stdio.h>
//插入
#if 0
//头插法
STU *insert_link(STU *head, STU tmp)
{
    //为待插入的数据申请空间
    STU *pi = (STU *)calloc(1, sizeof(STU));
    if (pi == NULL)
    {
        perror("calloc");
        exit(-1);
    }
    *pi = tmp;
    pi->next = NULL; //下个节点指向先置空
    //判断链表是否存在
    if (head == NULL) //不存在
    {
        head = pi;
    }
    else //存在
    {
        pi->next = head; //头插
        head = pi;
    }
    return head;
}
#endif
#if 0
//尾插法
STU *insert_link(STU *head, STU tmp)
{
    //为待插入的数据申请空间
    STU *pi = (STU *)calloc(1, sizeof(STU));
    if (pi == NULL)
    {
        perror("calloc");
        exit(-1);
    }
    *pi = tmp;
    pi->next = NULL; //下个节点指向先置空
    //判断链表是否存在
    if (head == NULL) //不存在
    {
        head = pi;
    }
    else //存在
    {
        //寻找链表的尾部
        STU *pb = head;          //不能取head->next,因为只有一个节点时的next为NULL
        while (pb->next != NULL) //找到尾部时退出
        {
            pb = pb->next;
        }
        pb->next = pi; //把尾部的指针域置为新节点的地址
    }
    return head;
}
#endif
#if 1
//有序插入
STU *insert_link(STU *head, STU tmp)
{
    //为待插入的数据申请空间
    STU *pi = (STU *)calloc(1, sizeof(STU));
    if (pi == NULL)
    {
        perror("calloc");
        exit(-1);
    }
    *pi = tmp;
    pi->next = NULL; //下个节点指向先置空
    //判断链表是否存在
    if (head == NULL) //不存在
    {
        head = pi;
    }
    else //存在
    {
        //寻找插入的位置
        STU *pb = head, *pf = head;
        while ((pb->num < pi->num) && (pb->next != NULL))
        {
            pf = pb;
            pb = pb->next;
        }
        if (pb->num >= pi->num) //头部、中部插入
        {
            if (pb == head)
            {
                pi->next = head;
                head = pi;
            }
            else
            {
                pf->next = pi;
                pi->next = pb;
            }
        }
        else
        {
            pb->next = pi;
        }
    }
    return head;
}
#endif
//遍历
void print_link(STU *head)
{
    //判断链表是否存在
    if (head == NULL)
    {
        printf("链表不存在或空\n");
        return;
    }
    else
    {
        STU *pb = head;
        while (pb != NULL)
        {
            printf("%d %s %.2f\n", pb->num, pb->name, pb->score);
            pb = pb->next;
        }
    }
    return;
}

//通过名字查找
STU *search_link(STU *head, char *name)
{
    if (head == NULL)
    {
        printf("链表不存在或空\n");
        return head;
    }
    else
    {
        STU *pb = head;
        while (pb != NULL)
        {
            if (strcmp(pb->name, name) == 0)
            {
                return pb;
            }
            pb = pb->next;
        }
    }
    return NULL;
}
//按学号删除
STU *delete_link(STU *head, int num)
{
    if (head == NULL)
    {
        printf("链表不存在或空\n");
        return head;
    }
    else
    {
        STU *pb = head;
        STU *pf = head;
        while (pb != NULL)
        {
            if (pb->num == num)
            {
                if (head == pb) //如果是第一个节点时
                {
                    head = head->next;
                }
                else //非第一个节点时
                {
                    pf->next = pb->next;
                }
                free(pb);
                printf("删除学号为%d的学生成功\n", num);
                return head; //删除次就结束
            }
            pf = pb;
            pb = pb->next;
        }
        printf("未找到学号为%d的学生\n", num);
        return head;
    }
}
STU *free_link(STU *head)
{
    if (head == NULL) //判断链表是否存在
    {
        printf("链表已为空！\n");
    }
    else
    {
        while (head != NULL)
        {
            STU *tmp = head;
            head = head->next;
            free(tmp);
        }
        printf("链表已清除！\n");
    }
    return NULL;
}
STU *reverse_link(STU *head)
{
    if (head == NULL)
    {
        printf("链表不存在或空\n");
    }
    else
    {
        STU *pb = head->next;
        STU *pn = NULL;
        head->next = NULL;

        while (pb != NULL)
        {
            //记录下一个节点的地址
            pn = pb->next;
            //连接上一个节点
            pb->next = head;
            head = pb;
            pb = pn;
        }
        printf("链表反转完成\n");
    }
    return head;
}
void sort_link(STU *head)
{
    if (head == NULL)
    {
        printf("链表不存在或空\n");
        return;
    }
    else
    {
        STU *p_i = head;
        STU *p_j = head;
        while (p_i->next != NULL)
        {

            STU *p_min = p_i;
            p_j = p_min->next;
            while (p_j != NULL)
            {
                if (p_min->num > p_j->num)
                {
                    p_min = p_j;
                }
                p_j = p_j->next;
            }
            if (p_min != p_i)
            {
                //先内容整体交换
                STU tmp = *p_i;
                *p_i = *p_min;
                *p_min = tmp;
                //然后再交换一次指针域
                tmp.next = p_i->next;
                p_i->next = p_min->next;
                p_min->next = tmp.next;
            }
            p_i = p_i->next;
        }
        printf("排序完成！\n");
    }
}
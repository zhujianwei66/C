/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-16 10:18:18
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-16 13:16:00
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct stu
{
    //数据域
    int num;
    char name[32];
    //指针域
    struct stu *pre;
    struct stu *next;
} STU;
STU *head = NULL;
void insert_link(STU **p_head, STU tmp);
void print_link(STU *head);
STU *search_link(STU *head, int num);
void delete_link(STU **p_head, int num);
void free_link(STU **p_head);

int main(int argc, char *argv[])
{
    int n = 0;
    printf("请输入学生个数：");
    scanf("%d", &n);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("请输入第%d个学员的信息num name:", i + 1);
        STU tmp;
        scanf("%d %s", &tmp.num, tmp.name);
        insert_link(&head, tmp);
    }
    //遍历链表
    print_link(head);
    //查询
    printf("请输入需要查询的学号：");
    int num = 0;
    scanf("%d", &num);
    STU *ret = search_link(head, num);
    if (ret == NULL)
    {
        printf("查询结果为空\n");
    }
    else
    {
        printf("%d %s\n", ret->num, ret->name);
    }
    printf("请输入需要删除的学号：");
    scanf("%d", &num);
    delete_link(&head, num);
    print_link(head);
    free_link(&head);
    return 0;
}

void free_link(STU **p_head)
{
    STU *head = *p_head;
    if (head == NULL)
    {
        printf("链表为空");
        return;
    }
    else
    {
        ;
    }
    return;
}

#if 0
void delete_link(STU **p_head, int num)
{
    STU *head = *p_head;
    if (head == NULL) //链表为空
    {
        printf("链表为空\n");
        return;
    }
    else //链表非空
    {
        STU *pn = head;      //头节点
        STU *pr = head->pre; //尾节点

        while ((pn->num != num) && (pr->num != num) && (pn != pr) && (pn->next != pr))
        {
            pn = pn->next;
            pr = pr->pre;
        }
        if (pn->num == num) //头部中部
        {
            if (pn == head) //删除头节点
            {
                head->next->pre = head->pre;
                head->pre->next = head->next;
                head = head->next;
            }
            else
            {
                pn->pre->next = pn->next; //上一个节点的next指针指向下一个节点
                pn->next->pre = pn->pre;  //下一个节点的pre指针指向上一个节点
            }
            free(pn);
            printf("删除成功");
        }
        else if (pr->num == num) //尾部中部
        {
            pr->pre->next = pr->next;
            pr->next->pre = pr->pre;
            free(pr);
        }
        else //未找到
        {
            printf("未找到学号：%d", num);
        }
        *p_head = head;
        return;
    }

    return;
}
#endif
void delete_link(STU **p_head, int num)
{
    STU *head = *p_head;
    if (head == NULL) //链表为空
    {
        printf("链表为空\n");
        return;
    }
    else //链表非空
    {
        STU *pn = head;      //头节点
        STU *pr = head->pre; //尾节点

        while ((pn->num != num) && (pr->num != num) && (pn != pr) && (pn->next != pr))
        {
            pn = pn->next;
            pr = pr->pre;
        }
        if (pn->num == num) //头部中部
        {
            if (pn == head) //删除头节点前先让头指针后移
            {
                head = head->next;
            }
            pn->pre->next = pn->next; //上一个节点的next指针指向下一个节点
            pn->next->pre = pn->pre;  //下一个节点的pre指针指向上一个节点
            free(pn);
            printf("删除成功\n");
        }
        else if (pr->num == num) //尾部中部
        {
            pr->pre->next = pr->next;
            pr->next->pre = pr->pre;
            free(pr);
        }
        else //未找到
        {
            printf("未找到学号：%d\n", num);
        }
        *p_head = head;
        return;
    }

    return;
}
STU *search_link(STU *head, int num)
{
    if (head == NULL)
    { //链表为空
        printf("链表为空\n");
    }
    else
    { //链表非空
        STU *pn = head;
        STU *pr = head->pre;
        while ((pn->num != num) && (pr->num != num) && (pn != pr) && (pn->next != pr))
        {
            pn = pn->next;
            pr = pr->pre;
        }
        if (pn->num == num)
        {
            return pn;
        }
        else if (pr->num == num)
        {
            return pr;
        }
        else
        {
            return NULL;
        }
    }
}
void print_link(STU *head)
{
    //判断链表是否为空
    if (head == NULL)
    {
        printf("链表为空\n");
        return;
    }
    else
    {
        STU *pn = head;      //头部
        STU *pr = head->pre; //尾部
        while (1)
        {
            if (pn == pr)
            { //节点为奇数个
                printf("%d %s\n", pn->num, pn->name);
                break;
            }
            else if (pn->next == pr)
            { //节点为偶数个
                printf("%d %s\n", pn->num, pn->name);
                printf("%d %s\n", pr->num, pr->name);
                break;
            }
            else
            {
                printf("%d %s\n", pn->num, pn->name);
                printf("%d %s\n", pr->num, pr->name);
                pn = pn->next;
                pr = pr->pre;
            }
        }
    }
    return;
}
void insert_link(STU **p_head, STU tmp) //尾插法
{
    STU *head = *p_head;
    //申请堆区空间存放数据
    STU *pi = (STU *)calloc(1, sizeof(STU));
    *pi = tmp;
    pi->next = NULL;
    pi->pre = NULL;
    //判断链表是否为空
    if (NULL == head) //头节点为空
    {
        head = pi;
        pi->pre = head;
        pi->next = head;
    }
    else //头节点不为空
    {
        head->pre->next = pi; //尾节点的next指针指向pi
        pi->next = head;      //pi的next指针指向head
        pi->pre = head->pre;  //pi的pre指针指向尾节点
        head->pre = pi;
    }
    //更新外部的head
    *p_head = head;
    return;
}
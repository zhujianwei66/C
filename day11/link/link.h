/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-15 14:45:34
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-15 19:41:55
 */
//防止头文件重复包含
#ifndef __LINK_H__
#define __LINK_H__
typedef struct stu
{
    //数据域
    int num;
    char name[32];
    float score;
    //指针域
    struct stu *next;
} STU;

extern STU *insert_link(STU *head, STU tmp);
extern void print_link(STU *head);
extern STU *search_link(STU *head, char *name);
extern STU *delete_link(STU *head, int num);
extern STU *free_link(STU *head);
extern STU *reverse_link(STU *head);
extern void sort_link(STU *head);
#endif
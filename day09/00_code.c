/*
 * @Descripttion: 
            1.长度
                strlen(const char *s) 求字符串长度，遇到'\0'结束
            2.拷贝
                char *strcpy(char *dst, const char *src) 字符串拷贝，遇到'\0'结束。注意目标字符串空间不足依然可以拷贝，导致越界。
                char *strncpy(char *dst, const char *src, int n) 字符串拷贝,遇到'\0'结束，最多拷贝n个字符。
            3.字符串追加
                char *strcat(char *dst, const char *src)    把字符串src追加到dst尾部，遇到'\0'结束
                char *strncat(char *dst, const chat *src, int n) 把字符串src追加到dst尾部，遇到'\0'结束，最多追加n个字符
            4.字符串比较，
                int strcmp(const char* s1,const char* s2)     比较字符串s1、s2
                int strncmp(const char* s1,const char* s2, int n)     比较字符串s1、s2的前n个字符
            5.字符查找
                char *strchr(const char *s,int c)   从前往后查，找到返回地址，找不到返回空
                char *strrchr(const char *s, int c)  从后往前查，找到返回地址，找不到返回空
            6.字符串查找
                char *strstr(const char *haystack, const char *needle);  找到返回地址，找不到返回空
            7.字符串转数值
                atoi(const char *str) 字符串转整型
                atol(const char *str) 字符串转长整型
                atof(const char *str) 字符串转浮点型
            8.字符串切割
                char *strtok(char *str,const char *delim) 对str指向的字符串切割，str不能传文字常量
                第一次切割：str指向需要切割的字符首地址，delim为切割符表，每个字符均可切割
                后续切割： str传NULL
            9.自制字符串转数值函数
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-13 10:35:34
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-13 15:30:18
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test01();
void test02();
void test03();
void test04();
void test05();
void test06();
void test07();
void test08();
void test09();

int main(int argc, char *argv[])
{
    test09();
    return 0;
}
void test01()
{
    char *str1 = "hello world1";
    printf("strlen(str1) = %d\n", strlen(str1));
    return;
}
void test02()
{
    char str2[] = "";
    char str3[] = "hello world3";
    strcpy(str2, str3); //拷贝可以成功，但是已经越界
    printf("%s \n", str2);
    printf("%s \n", str3);
    return;
}
void test03()
{
    char str1[128] = "hello ";
    char str2[] = "world";
    strcat(str1, str2);
    printf("%s \n", str1);
    return;
}
void test04()
{
    /*
    字符串返回值：
    >0： s1字符串 > s2字符串
    <0： s1字符串 < s2字符串
    ==0： s1字符串 == s2字符串
    
    字符比较原理：
    逐个字符比较，相同比较下一位，不同则返回ascii码值，比较到'\0'则返回0
    */
    char str1[] = "helloa";
    char str2[] = "helloc";
    int ret = strcmp(str1, str2);
    printf("%d  %d\n", ret, (int)('a' - 'c'));
    return;
}
void test05()
{
    char str[] = "hello world";
    char *ret = strrchr(str, 'o');
    if (ret != NULL)
        printf("%s\n", ret);
    return;
}
void test06()
{
    char str[] = "hello world";
    while (1)
    {
        char *ret = strstr(str, "ll");
        if (ret != NULL)
        {
            memset(ret, '*', strlen("ll"));
        }
        else
        {
            break;
        }
    }
    printf("%s\n", str);
    return;
}
void test07()
{
    printf("%d \n", atoi("100a"));
    printf("%ld \n", atol("100a"));
    printf("%.3f \n", atof("3.14"));
    return;
}
void test08()
{
    char str[] = "haha:xixi::::lala:wuwu";
    char *buff[32] = {str};
    // //第一次切割
    // int i = 0;
    // buff[i] = strtok(str, ":");
    // //后续切割
    // while (buff[i] != NULL)
    // {
    //     i++;
    //     buff[i] = strtok(NULL, ":");
    // }
    //第二种切割法
    int i = 0;
    while (1)
    {
        buff[i] = strtok(buff[i], ":");
        if (buff[i] == NULL)
            break;
        i++;
    }
    //遍历指针数组
    i = 0;
    while (buff[i] != NULL)
    {
        printf("%s\n", buff[i++]);
    }
    return;
}
int my_atoi(char *s)
{
    int num = 0;
    while (*s >= '0' && *s <= '9')
    {
        num = num * 10 + (*s - '0');
        s++;
    }
    return num;
}
void test09()
{
    char str[] = "123456abc";
    printf("%d\n", my_atoi(str));
    return;
}
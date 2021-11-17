/*
 * @Descripttion: 
                文件操作
                    1.fopen/fclose  打开文件/关闭文件
                    2.fputc  字符写
                    3.fgetc  字符读
                    4.fputs  行写
                    5.fgets  行读
                    6.fwrite  块写
                    7.fread  块读
                    8.fprintf   格式化写
                    9.fscanf   格式化读
                随机读写
                    1.rewind 复位文件流指针
                    2.ftell  返回当前流指针到文件首部的字节数
                    3.fseek文件流指针定位

 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-16 16:11:40
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-17 11:05:04
 */
#include <stdio.h>
//打开文件
//FILE* fopen(const char *path,const char *mode);
void test01()
{
    FILE *pf = NULL;
    pf = fopen("hello.txt", "r");
    if (pf == NULL)
    {
        perror("fopen");
        return;
    }
    fclose(pf);
    return;
}
//单个字符读写
void test02()
{
    FILE *pf = NULL;
    pf = fopen("hello.txt", "w");
    if (pf == NULL)
    {
        perror("fopen");
        return;
    }
    //写入文件
    char *file_data = "hello,I am test02!\n";
    while (*file_data != '\0')
    {
        fputc(*file_data, pf);
        file_data++;
    }
    printf("文件修改完成\n");
    fclose(pf);
    return;
}
void test03()
{
    FILE *pf = NULL;
    pf = fopen("hello.txt", "r");
    if (pf == NULL)
    {
        perror("fopen");
        return;
    }
    //逐个文字读取文件
    while (1)
    {
        char ch = fgetc(pf);
        if (ch == EOF)
            break;
        printf("%c", ch);
    }
    printf("读取完成\n");
    return;
}
void test04()
{
    FILE *pf1 = fopen("hello.txt", "r");
    FILE *pf2 = fopen("test.txt", "w");
    if ((pf1 == NULL) || (pf2 == NULL))
    {
        perror("fopen");
        return;
    }
    //从hello.txt读取内容

    while (1)
    {
        char str[128] = "";
        char *ret = fgets(str, sizeof(str), pf1);
        if (ret == NULL)
            break;
        fputs(str, pf2);
    }
    printf("文件拷贝完成\n");
    fclose(pf1);
    fclose(pf2);
    return;
}
int main(int argc, char *argv[])
{
    test04();
    return 0;
}
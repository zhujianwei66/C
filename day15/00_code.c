/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-24 10:15:26
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-25 17:13:42
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//打印函数
void print_help();
//获取文件名
void get_file_name(char *dest_file_name, char *src_file_name);
//获取文件内容
char *read_src_file(unsigned long int *file_length, char *src_file_name);
//保存函数
void save_file(char *text, unsigned long int length, char *file_name);
//加密函数
char *file_text_encrypt(char *src_file_text, unsigned long int length, unsigned int password);
//解密函数
char *file_text_dencrypt(char *src_file_text, unsigned long int length, unsigned int password);
int main(int argc, char *argv[])
{
    int cmd = 0;
    while (1)
    {
        char src_file_name[128] = "";      //源文件
        char dest_file_name[128] = "";     //目标文件
        unsigned long int file_length = 0; //文件长度
        char *data = NULL;
        unsigned long int password = 0;

        print_help();
        scanf("%d", &cmd);
        switch (cmd)
        {
        case 1:
        {
            // printf("加密函数\n");
            //获取文件名
            get_file_name(dest_file_name, src_file_name);
            //printf("%s %s\n", src_file_name, dest_file_name);
            //读取文件内容
            data = read_src_file(&file_length, src_file_name);
            //printf("%s\n", data);
            //加密
            printf("please input your password:");
            scanf("%lu", &password);
            data = file_text_encrypt(data, file_length, password);
            //printf("%s\n", data);
            //保存文件
            save_file(data, file_length, dest_file_name);
            break;
        }

        case 2:
            // printf("解密函数\n");
            //获取文件名
            get_file_name(dest_file_name, src_file_name);
            //读取文件内容
            data = read_src_file(&file_length, src_file_name);
            //解密
            printf("please input your password:");
            scanf("%lu", &password);
            data = file_text_dencrypt(data, file_length, password);
            //保存文件
            save_file(data, file_length, dest_file_name);
            break;
        case 3:
            printf("退出\n");
            return 0;
        }
    }
    return 0;
}
void print_help()
{
    printf("*******1.加密文件*******\n");
    printf("*******2.解密文件*******\n");
    printf("********3.退出********\n");
    return;
}
void get_file_name(char *dest_file_name, char *src_file_name)
{
    printf("请输入目标文件名:");
    scanf("%s", dest_file_name);
    printf("请输入源文件名：");
    scanf("%s", src_file_name);
}
char *read_src_file(unsigned long int *file_length, char *src_file_name)
{
    FILE *pf = fopen(src_file_name, "r"); //打开文件
    //判断文件是否打开
    if (pf == NULL)
    {
        //打开失败
        //打印错误信息
        perror("fopen");
        exit(-1);
    }
    //打开成功
    fseek(pf, 0, 2);          //文件移动到末尾
    *file_length = ftell(pf); //获取文件大小
    rewind(pf);               //复位
    //申请空间
    char *p = (char *)calloc(1, *file_length);
    if (p == NULL)
    {
        //申请失败
        perror("calloc");
        exit(-1);
    }
    fread(p, *file_length, 1, pf);
    fclose(pf);

    return p;
}
char *file_text_encrypt(char *src_file_text, unsigned long int length, unsigned int password)
{
    int i = 0;
    for (i = 0; i < length; i++)
    {
        src_file_text[i] += password;
    }
    return src_file_text;
}
void save_file(char *text, unsigned long int length, char *file_name)
{
    FILE *pf = fopen(file_name, "w"); //打开
    if (pf == NULL)
    {
        perror("fopen");
        exit(-1);
    }
    fwrite(text, length, 1, pf); //写入
    fclose(pf);                  //关闭
    //释放堆区空间
    if (text != NULL)
    {
        free(text);
        text = NULL;
    }
    return;
}
char *file_text_dencrypt(char *src_file_text, unsigned long int length, unsigned int password)
{
    int i = 0;
    for (i = 0; i < length; i++)
    {
        src_file_text[i] -= password;
    }
    return src_file_text;
}
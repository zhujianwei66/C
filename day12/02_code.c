/*
 * @Descripttion: 文件操作
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-16 16:11:40
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-16 16:34:29
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
int main(int argc, char *argv[])
{

    return 0;
}
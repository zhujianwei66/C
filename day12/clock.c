/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-16 15:54:36
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-16 15:58:15
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    while (i < 3600)
    {
        printf("\r%02d:%02d", i / 60, i % 60);
        fflush(stdout);
        sleep(1);
        i++;
    }
    return 0;
}
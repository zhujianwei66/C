/*
 * @Descripttion: 
        gcc的编译全过程：
            1.预处理：宏替换、删除注释、头文件包含、条件编译 -E
            2.编译：将预处理后的文件编译成汇编文件 -S
            3.汇编：将汇编文件生成二进制文件 -c
            4.链接: 将工程的二进制文件+库函数+启动代码 合并生成可执行文件
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-11 10:04:12
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-11 10:36:19
 */
#include "stdio.h"

int main(int argc, char *argv[])
{
    printf("hello world!\n");
    return 0;
}
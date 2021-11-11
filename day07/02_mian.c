/*
 * @Descripttion:
            1.#ifdef  XXX  #else  #endif  检测是否定义宏XXX，是执行else前，否执行else后
            2.#ifndef XXX  #else  #endif  检测是否定义宏XXX，否执行else前，是执行else后
            3.#if  XXX  #else  #endif     检测宏是非为真，真则编译else前的代码，假则编译else后的代码
            预编译巧用：用作代码裁剪、可用作防止头文件重复包含
            linux下防止头文件重复包含：          |       window下防止重复包含：
            #ifndef                            |       #pragma once
            #define                            |       .....
            .....                              |
            #endif                             |
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-11 12:34:39
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-11 13:06:00
 */
#include "stdio.h"
#include "02_a.h"
#include "02_b.h"

int main(int argc, char *argv[])
{
    printf("num = %d\n", num);
    return 0;
}

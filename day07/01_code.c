/*
 * @Descripttion:头文件包含规则:
            1.include<>在系统指定目录寻找head.h头文件
            2.include""先从当前目录寻找head.h头文件，如果找不到再到系统指定的目录下寻找

 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-11 10:34:24
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-11 10:45:14
 */
#include <stdio.h>
#include "01_code.h"

int main(int argc, char *argv[])
{

    printf("1.include<>在系统指定目录寻找head.h头文件");
    printf("2.include\"\"先从当前目录寻找head.h头文件，如果找不到再到系统指定的目录下寻找");
    return 0;
}

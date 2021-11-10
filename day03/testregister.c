/*
 * @Descripttion: register关键字把变量放在寄存器中，方便反复使用
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-06 15:53:12
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-06 16:17:48
 */
#include"stdio.h"

int main(int argc, char* argv[])
{
    //把频繁使用变量申请在寄存器中
    register int num = 10;
    //注意：寄存器变量不可取地址！！！
    //&取地址取的是内存地址，num可能在寄存器中，所以取地址失败
    //register修饰的变量只是尽量放在寄存器中，实际能否放入还需要看实际情况
    return 0;
}
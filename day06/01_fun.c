/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-10 20:03:13
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-10 20:05:23
 */
extern int data; //声明变量来自其他源文件
void add_data(void)
{
    data = data + 10;
    return;
}
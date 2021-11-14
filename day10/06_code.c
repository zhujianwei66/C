/*
 * @Descripttion:
            枚举
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-14 20:52:15
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-14 20:59:52
 */
#include <stdio.h>
enum POKE_COLOR
{
    HEITAO,
    HONGXING = 10,
    MEIHUA,
    FANGKUAI
}; //默认从0开始递增
void test01()
{
    printf("%d %d %d %d\n", HEITAO, HONGXING, MEIHUA, FANGKUAI);
    return;
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}
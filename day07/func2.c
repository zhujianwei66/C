/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-11 09:52:51
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-11 09:54:49
 */
static int va = 18;
static int getG(void)
{
    return va;
}
int getO(void)
{
    return getG();
}
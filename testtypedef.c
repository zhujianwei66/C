/*
 * @Descripttion: 
                1.先用已有类型定义一个普通变量
                2.用别名替换类型名
                3.在表达式前方加上 typedef

 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-06 16:46:06
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-06 16:53:37
 */
#include"stdio.h"

int main(int argc, char* argv[])
{
    typedef int MY_ARRAY[5];//给数组arr[5]取了一个别名叫MY_ARRAY
    MY_ARRAY a= {1,2,3,4,5};//这样就可以通过别名定义一个数组arr[5]类型的变量
    for(int i= 0;i<5;i++){
        printf("%d ",a[i]);//逐个输出
    }
    printf("");//换行
    return 0;
}
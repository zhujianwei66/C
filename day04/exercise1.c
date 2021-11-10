/*
 * @Descripttion:键盘获取10个数，存储在数组中，求数组的最大值和最小值 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-07 20:42:21
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-07 20:53:03
 */
#include"stdio.h"

int main(int argc, char* argv[])
{
    int arr[10] = {0};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    int i = 0;
    printf("请输入10个整数：\n");
    for(i = 0;i<arr_size;i++){
        scanf("%d",&arr[i]);
    }
    int max_num = arr[0];
    int min_num = arr[0];

    for(i = 0;i<arr_size;i++){
        if(arr[i]>max_num)
        {
            max_num = arr[i];
        }
        if(arr[i]<min_num)
        {
            min_num = arr[i];
        }
    }
    printf("最大值为 %d ,最小值为 %d\n",max_num,min_num);
    return 0;
}
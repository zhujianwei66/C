/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-05 11:00:14
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-05 11:16:20
 */
#include"stdio.h"

int main(int argc, char *argv[]){
    char ch = '\0';
    printf("请输入一个字符（a~z|A~Z）:\n");
    scanf("%c",&ch);
    getchar();//清除回车
    //判断字符是大写还是小写
    if(ch>='a'&&ch<='z'){
        ch -= ('a' - 'A');
    }
    else if(ch>='A'&&ch<='Z'){
        ch += ('a' - 'A');
    }
    printf("转换后的字符为：%c\n",ch);
    return 0;
}
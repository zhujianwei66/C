/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-13 17:24:16
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-13 21:54:09
 */
/*
 * @Descripttion:
            1.格式化字符串：
                组包：按照需要的格式组成字符串
                    sprintf(char* s, char *format,...)以format的格式把...中的数据写入字符串s
                解包：解析特定格式的数据
                    sscanf(char* s,char *format,....)
                        基础用法：
                            %d 提取数值'0'~'9'
                            %s 提取字符串，遇到'\0'、空格、回车结束
                        高级用法：
                            跳过数据：%*s或%*d
                            读取指定宽度： %[width]s %[width]d
                            支持集合操作：只支持提取字符串
                                %[a-z]表示提取a-z中任意的字符（尽可能多）
                                %[a-z,A-Z,0-9]多条件，满足其一即提取（贪婪性）
                                %[aBc] 是'a'\'B'\'c'的任意字符（贪婪性）
                                %[^aFc] 不是a\F\c的任意字符（贪婪性）
                                %[^a-z] 不是a-z就要，遇到第一个不匹配的字符就结束
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-13 17:24:16
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-13 20:02:03
 */
#include <stdio.h>

void test01(); //组包实现格式化输出数据字
void test02(); //组包实现数值转字符串
void test03(); //解包从日期中提取数字
void test04(); //解包提取字符串
void test05(); //sscanf跳过某个数据
void test06(); //提取指定宽度
void test07(); //集合操作

int main(int argc, char *argv[])
{
    test07();
    return 0;
}
void test07()
{
    char str[128] = "abcABC123";
    char buf1[128] = "";
    char buf2[128] = "";
    char buf3[128] = "";
    char buf4[128] = "";
    char buf5[128] = "";

    sscanf(str, "%[a-z]", buf1);            //abc
    sscanf(str, "%[a-z,A-Z,0-9]", buf2);    //abcABC123
    sscanf(str, "%[aBc]", buf3);            //a
    sscanf(str, "%[^A]A%[^1]", buf4, buf5); //abc   ABC
    printf("%s\n%s\n%s\n%s\n%s\n", buf1, buf2, buf3, buf4, buf5);
    return;
}
void test06()
{
    char str[128] = "12345678";
    char buf[128] = "";                      //67
    int num = 0;                             //34
    sscanf(str, "%*2d%2d%*c%2s", &num, buf); //"1234"
    printf("num = %d,buf = %s\n", num, buf);

    return;
}
void test05()
{
    char str[128] = "1234  5678";
    char buf[128] = "";
    sscanf(str, "%*d %s", buf);
    printf("%s\n", buf);
    return;
}
void test04()
{
    char str[128] = "2021年 11月 13日";
    char buf[128] = "";
    sscanf(str, "%s", buf);
    printf("%s\n", buf);
    return;
}
void test03()
{
    char str[128] = "2021年11月13日";
    int year = 0;
    int month = 0;
    int day = 0;
    sscanf(str, "%d年%d月%d日", &year, &month, &day);
    printf("%d, %d, %d\n", year, month, day);
    return;
}
void test02()
{
    char buff[128] = "";
    sprintf(buff, "%d", 1234);
    printf("%s\n", buff);
    return;
}
void test01()
{
    int year = 2021;
    int month = 11;
    int day = 13;
    char str[128] = "";
    int len = sprintf(str, "%d年%d月%d日", year, month, day);
    printf("len = %d,str = %s\n", len, str);

    return;
}
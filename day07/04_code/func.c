/*
 * @Descripttion: 
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-11 15:33:27
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-11 16:53:53
 */
/*
 * @Descripttion: 
        1.静态库的制作：
            gcc -c file.c -o file.o
            ar rc libtestlib.a file1.o .....
            同一文件下编译： gcc main.c libtestlib.a
        2.自定义文件夹下编译： gcc main.c -I./lib -L./lib -ltestlib
            动态库的制作：
            gcc -shared file.c -o libtestlib.so
            动态库需要导入所在的路径
            export LD_LIBRARY_PATH=动态库所在路径:$LD_LIBRARY_PATH
        3.如果静态库和动态库同时存在 默认编译选择动态库 只有加 -static修饰才链接静态库
 * @version: 
 * @Author: ZhuJianwei
 * @Date: 2021-11-11 15:33:27
 * @LastEditors: ZhuJianwei
 * @LastEditTime: 2021-11-11 16:21:00
 */
int my_add(int x, int y)
{
    return x + y;
}
int my_sub(int x, int y)
{
    return x - y;
}
int my_mul(int x, int y)
{
    return x * y;
}
int my_div(int x, int y)
{
    return x / y;
}
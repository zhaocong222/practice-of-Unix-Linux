#include<stdio.h>

/*
 *  int ac 是命令行参数的个数 第一个参数是当前文件地址
 *  char * arg[]  字符指针的数组, 每一个指针指向一个具体的命令行参数(字符串)）
 */

 //命令： ./test.out 1

int main(int ac,char * arg[])
{
    //char *str = "hello world";

    //printf("%c\n",str[0]);
    //printf("%c\n",*str); //首地址对应的值 h
    //printf("%c\n",* ++str); //首地址后的地址对应的值 e

    //printf("%s\n",arg[0]);
    //printf("%s\n",* ++arg);
    
    int c;
    c = getchar();
    printf("%c",c);
    //while( (c = getchar()) != EOF)


    

}
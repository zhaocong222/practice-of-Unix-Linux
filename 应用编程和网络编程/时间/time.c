#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main()
{
    //man 2 time
    /*
    * SYNOPSIS
       #include <time.h>

       time_t time(time_t *tloc);  
       这里的参数前面并没有const关键字，意味着输出型参数，可以传NULL。
       当然可以传入time_t类型的指针变量 
    */
    time_t t = 0; 
    t = time(NULL); //返回值
    //time(&t);   //指针做输出型参数
    if (t == -1)
    {
        perror("time");
        exit(-1);
    }

    printf("time: %ld",t);

}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void func1(void)
{
    printf("func1\n");
}

void func2(void)
{
    printf("func2\n");
}


int main(void)
{
    printf("hello world.\n");
    //当进程被正常终止时，系统会自动调用这里注册的func执行
    //先注册的后执行 - 栈一样
    atexit(func1);
    atexit(func2);

    printf("my name is lemon\n");

    return 0;
    //exit(0);
    
    //_exit(0); // 不会执行注册的函数 func1 func2
}
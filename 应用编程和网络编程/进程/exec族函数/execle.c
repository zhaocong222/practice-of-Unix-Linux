//创建子进程
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main()
{
    char *envp[] = {"AA=aa","XX=abcd",NULL};
    //支持传入环境变量
    execle("hello","",NULL,envp);

}
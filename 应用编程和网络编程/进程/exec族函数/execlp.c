//创建子进程
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{   
    //与execl区别就是，不需要写绝对路径
    execlp("ls","ls","-l","-a",NULL); // ls -la
    
    return 0;
}

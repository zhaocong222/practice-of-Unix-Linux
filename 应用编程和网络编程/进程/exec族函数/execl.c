//创建子进程
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    //NULL表示参数结束
    //execl("/bin/ls","ls","-l","-a",NULL); // ls -la
    
    //char *arg[] = {"ls","-l","-a",NULL};
    //execv("/bin/ls",arg);

    //执行自己编译的程序，注意参数
    //execl("hello","",NULL); 

    return 0;
}
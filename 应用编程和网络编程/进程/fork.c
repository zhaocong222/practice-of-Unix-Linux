//创建子进程
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid = -1;
    //返回值为0就是子进程，返回值>0就是父进程
    pid = fork();

    if (pid == 0)
    {
        //子进程
        pid_t pid = -1;
        pid = getpid();
        printf("子进程是:%d\n",pid);

    } else if (pid > 0) {
        //父进程
        pid_t ppid = -1;
        ppid = getppid();
        printf("父进程是:%d\n",ppid);

    } else {
        //fork出错
        perror("fork错误");
        exit(-1);
    }

    return 0;
}

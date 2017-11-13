#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid = 1;
    pid_t ret = -1;
    int status;
    pid = fork();

    if(pid >0)
    {
        //父进程  
        printf("parent.\n");
        // -1表示回收任意子进程, 0表示默认方式 阻塞式
        //返回值 ret 是本次回收的子进程的id
        //ret =  waitpid(-1,&status,0);

        //非阻塞(如果子进程还没有结束，这里回收是失败的)
        ret = waitpid(pid,&status,WNOHANG);

        printf("子进程已经被回收，子进程pid = %d.\n",ret);

    }
    else if(pid == 0)
    {
        //子进程
        printf("child pid = %d.\n",getpid());
        sleep(1);
    }
    else 
    {
       perror("fork");
       return  -1;
    }

    return 0;
}
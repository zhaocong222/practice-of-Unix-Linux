//创建子进程
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//孤儿进程
//1.父进程先于子进程结束，子进程成为一个孤儿进程。
//2.linux系统规定：所有的孤儿进程都自动成为一个特殊进程(init进程 一般是进程1) 的子进程。

int main(void)
{
    pid_t pid = -1;
    //返回值为0就是子进程，返回值>0就是父进程
    pid = fork();

    if (pid == 0)
    {
        //子进程
        sleep(2); //随便2秒，让父进程先执行
        pid_t pid = -1;
        pid = getpid();
        printf("子进程是:%d\n",pid);
        printf("父进程是:%d\n",getppid());

    } else if (pid > 0) {
        //父进程
        pid_t ppid = -1;
        ppid = getpid();
        printf("进程是:%d\n",ppid);

    } else {
        //fork出错
        perror("fork错误");
        exit(-1);
    }

    return 0;
}

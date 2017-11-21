#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void func(int sig)
{
    if (sig == SIGALRM)
    {
        printf("alarm happened.\n");
    }
}

int main(void)
{
    unsigned int ret1 = -1;
    unsigned int ret2 = -1;
    unsigned int ret3 = -1;
    //处理SIGALRM 信号
    signal(SIGALRM,func);

    ret1 = alarm(5);
    printf("ret1=%d.\n",ret1);

    //内核挂起,cpu交出去给其他进程运行
    //当前进程进入pause状态后当前进程会表现为“卡住，阻塞住”
    //要退出pause状态需要被信号唤醒。
    pause();
    
    return 0;
}
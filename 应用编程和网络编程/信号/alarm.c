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
    unsigned int ret = -1;
    //处理SIGALRM 信号
    signal(SIGALRM,func);

    //设置３秒的计时器,３秒后 触发SIGALRM信号
    ret = alarm(3);

    printf("end-ret=%d.\n",ret);

    //为了测试sigalrm信号
    while(1);

    return 0;
}
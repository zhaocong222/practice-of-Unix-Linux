#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void func(){}

void mysleep(unsigned int seconds)
{
    signal(SIGALRM,func);
    //设置定时器闹钟
    alarm(3);
    //让进程挂起
    pause();
}

int main(void)
{
    printf("sleep before\n");
    mysleep(3);
    printf("sleep after\n");
}
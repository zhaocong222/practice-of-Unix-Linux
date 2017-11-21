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

//　１个进程中　只能定义１个时钟，多次定义alarm,　这一次会把上一次掩盖掉.
int main(void)
{
    unsigned int ret1 = -1;
    unsigned int ret2 = -1;
    unsigned int ret3 = -1;
    //处理SIGALRM 信号
    signal(SIGALRM,func);

    ret1 = alarm(5);
    printf("ret1=%d.\n",ret1);
    sleep(3);

    //返回值是2 ,因为上面定时５秒，等待３秒　还剩２秒
    //但是本次alarm会重新定义5s
    ret2 = alarm(5); 
    printf("ret2=%d.\n",ret2);
    sleep(1);

    ret3 = alarm(5); //4
    printf("ret3=%d.\n",ret3); 
    
    return 0;
}
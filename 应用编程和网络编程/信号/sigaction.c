#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

typedef void (*sighandler_t)(int);

//代表函数指针类型
void func(int sig)
{
    //如果不是SIGINT信号就不处理
    if (SIGINT != sig)
        return;

    printf("func fo signal:%d.\n",sig);
}

int main(void)
{      
    
    struct sigaction act = {0};
    act.sa_handler = func;
    sigaction(SIGINT,&act,NULL);

    printf("before while\n");
    while(1)
        sleep(1);

    return 0;
}
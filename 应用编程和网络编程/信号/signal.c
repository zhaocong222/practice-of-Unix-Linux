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
    //SIGINT 2	Ctrl+C时OS送给前台进程组中每个进程
    //文档 第２个参数函数指针　typedef void (*sighandler_t)(int);
    //捕获到到SIGINT信号，执行func函数
    //signal(SIGINT,func);

    //捕获到信号后默认处理,这句比较多余，系统本身就默认处理。
    //signal(SIGINT,SIG_DFL);

    //忽略处理信号
    //signal(SIGINT,SIG_IGN);

    //处理信号返回值
    sighandler_t ret = (sighandler_t) - 2;
    ret = signal(SIGINT,func);
    if (SIG_ERR == ret)
    {
        perror("signal:");
        exit(-1);
    }

    printf("before while\n");
    while(1)
        sleep(1);
    printf("after while\n");
    return 0;
}
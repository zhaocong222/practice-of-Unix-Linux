#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

int mouse_fd = -1;

//绑定到sigio信号，在函数内处理异步通知事件
void func(int sig)
{
    if (sig != SIGIO)
        return;

    char buf2[100] = {0};
    //读鼠标
    read(mouse_fd,buf2,5);
    printf("读出的内容是:[%s].\n",buf2);


}


//主程序读键盘,注册一个异步io事件(读鼠标)
int main(void)
{
    char buf[100] = {0};
    int flag = -1;

    mouse_fd = open("/dev/input/mouse0",O_RDONLY);
    if (mouse_fd<0)
    {
        perror("oppen");
        return -1;
    }

    //1.把鼠标的文件描述符设置为可以接受异步io
    flag = fcntl(mouse_fd,F_GETFL);
    flag |= O_ASYNC;    //设置异步属性
    fcntl(mouse_fd,F_SETFL);
    //2.把异步io事件的接收进程设置为当前进程
    fcntl(mouse_fd,F_SETOWN,getpid());
    //3.注册当前进程的SIGIO信号捕获函数
    signal(SIGIO,func);

    while(1)
    {
        read(0,buf,5);
        printf("读出的内容是:[%s].\n",buf);
    }

    return 0;
}
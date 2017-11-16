#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//实现守护进程步骤
void crete_daemon(void)
{
    pid_t pid = 0;
    pid = fork();
    if (pid<0)
    {
        perror("fork");
        exit(-1);
    }

    if (pid > 0)
    {
        //1.父进程直接退出
        exit(0);
    }

    //2.
    //执行到这里就是子进程
    //setsid 将当前进程设置为一个新的会话期session,目的就是
    //让当前进程脱离控制台,成为守护进程。
    pid = setsid();
    if (pid < 0)
    {
        perror("setsid");
        exit(-1);
    }

    //3.设置当前进程的工作目录为根目录,不依赖于其他
    chdir("/");

    //4.umask设置为0确保将来进程有最大的文件操作权限
    umask(0);

    //5.关闭文件描述符
    //先要获取当前系统中所允许打开的最大文件描述符数目
    int i = 0;
    int cnt = sysconf(_SC_OPEN_MAX);
    for (i=0;i<cnt;i++)
    {
        close(i);
    }

    //将0,1,2定位到 /dev/null
    open("/dev/null",O_RDWR);
    open("/dev/null",O_RDWR);
    open("/dev/null",O_RDWR);

}

int main(void)
{

    crete_daemon();

    while(1)
    {
        printf("I am running.\n");
        sleep(1);
    }


    return 0;
}
#include <stdio.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char buf[100] = {0};
void *func(void *arg)
{
    //线程读取键盘
    while(1)
    {
        //父进程读键盘
        read(0,buf,4);
        printf("键盘读出的变量是:[%s]\n",buf);
    }
}

//-l 连接线程库
//gcc 线程.c -lpthread
int main(void)
{   

    int fd = -1;

    pthread_t th;

    
    int ret = -1;
    //思路就是创建线程，读键盘
    ret = pthread_create(&th,NULL,func,NULL);
    if (ret!= 0)
    {
        printf("pthread_create error.\n");
        return -1;
    }

    //因为主线程是while(1)死循环,所以可以在这里使用pthread_detach分离子线程
    //主线程用来分离子线程，分离后主线程不必再去回收子线程
    pthread_detach(th);

    //主程序读鼠标
    while(1)
    {
        fd = open("/dev/input/mouse0",O_RDONLY);
        if (fd < 0)
        {   
            perror("open:");
            return -1;
        }   

        read(fd,buf,10);
        printf("鼠标读出的变量是:[%s]\n",buf);
    } 

}
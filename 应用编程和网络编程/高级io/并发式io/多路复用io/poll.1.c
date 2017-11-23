#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <poll.h>
#include <signal.h>


//多路(读键盘，读鼠标)复用io
int main(void)
{
    char buf[100];

    int fd = -1,ret = -1;
    struct pollfd myfds[2] = {0};
    int len = sizeof(myfds) / sizeof(myfds[0]);

    fd = open("/dev/input/mouse0",O_RDONLY);
    if (fd<0)
    {
        perror("oppen");
        return -1;
    }

    //当前有２个fd,一个是鼠标fd,一个是标准输入0
    //初始化myfds
    myfds[0].fd = 0;          //键盘
    myfds[0].events = POLLIN; //等待读操作

    myfds[1].fd = fd;          //鼠标
    myfds[1].events = POLLIN; //等待读操作

    //10000毫秒 -> 10秒
    ret = poll(myfds,fd+1,10000);
    if (ret < 0)
    {
        perror("poll:");
        return -1;
    }
    else if(ret == 0)
    {
        printf("超时了\n");
    }
    else 
    {   
    
        for (int i=0;i<len;i++)
        {
            if (myfds[i].events == myfds[i].revents)
            {
                //这里是键盘
                memset(buf,0,sizeof(buf));
                read(myfds[i].fd,buf,5);
                printf("读出的内容是:[%s].\n",buf);
            }
        }

    }
    
}
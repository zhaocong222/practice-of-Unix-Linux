#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>

//外部阻塞式，内部非阻塞式自动轮询多路阻塞式IO
//多路(读键盘，读鼠标)复用io
int main(void)
{
    char buf[100];
    char buf2[100];
    //打开鼠标
    int fd = -1,ret = -1;
    fd_set myset;
    struct timeval tm;

    fd = open("/dev/input/mouse0",O_RDONLY);
    if (fd<0)
    {
        perror("oppen");
        return -1;
    }

    //当前有２个fd,一个是鼠标fd,一个是标准输入0
    /*
     * 第一个参数 最大的文件标识符+1
     * 处理myset
     */
    FD_ZERO(&myset);
    FD_SET(fd,&myset);
    FD_SET(0,&myset);

    //设置超时时间
    tm.tv_sec = 5; 
    tm.tv_usec = 0;

    ret = select(fd+1,&myset,NULL,NULL,&tm);
    if (ret < 0)
    {
        perror("select:");
        return -1;
    }
    else if(ret == 0)
    {
        printf("超时了\n");
    }
    else 
    {
        //等到了一路io,然后检测到底是哪个io,处理
        if (FD_ISSET(0,&myset))
        {
            //这里是键盘
            memset(buf2,0,sizeof(buf2));
            read(0,buf2,5);
            printf("读出的内容是:[%s].\n",buf2);
        }

        if (FD_ISSET(fd,&myset))
        {
            //这里处理鼠标
            memset(buf,0,sizeof(buf));
            read(fd,buf,5);
            printf("读出的内容是:[%s].\n",buf);
        }
    }




    

    
}
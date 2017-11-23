#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//非阻塞式io
//同时读鼠标和键盘 
/*
    before 鼠标 read.
    读出的内容是:[].
    before 键盘 read.
    读出的内容是:[].

    问题解决了，但是性能太差，ｃｐｕ一直100%
    需要多路复用io和异步io解决
*/
int main(void)
{
    char buf[100];
    char buf2[100];
    int ret = 0;

    //打开鼠标
    int fd = -1;
    fd = open("/dev/input/mouse0",O_RDONLY | O_NONBLOCK);
    if (fd<0)
    {
        perror("oppen");
        return -1;
    }

    //读键盘
    int flag = -1;
    //把0号文件描述符(stdin)变成非阻塞
    //通过fcntl可以改变已打开的文件性质
    flag = fcntl(0,F_GETFL);//1.先获取原来的flag
    flag |= O_NONBLOCK;     //2.添加非阻塞属性(利用位或)
    fcntl(0,F_SETFL,flag);  //3.写入
    //上面3步后，0就变成了非阻塞

    while(1)
    {
        memset(buf2,0,sizeof(buf2));
        //printf("before 键盘 read.\n");
        ret = read(0,buf2,5);
        if (ret > 0)
        {
            printf("键盘读出的内容是:[%s].\n",buf2);
        }

        //读鼠标
        memset(buf,0,sizeof(buf));
        //printf("before 鼠标 read.\n");
        ret = read(fd,buf,5);
        if (ret > 0)
        {
            printf("鼠标读出的内容是:[%s].\n",buf);
        }
    
    }
    return 0;
}
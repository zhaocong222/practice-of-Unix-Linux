#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//阻塞式io的困境
//同时读鼠标和键盘
/*
 *问题：代码是先read鼠标，/后read键盘 - 必须先晃动鼠标，再按键盘才有效果。
 *先按下键盘 没反应，因为read鼠标，一直处于阻塞当中。
 */
int main(void)
{
    char buf[100];
    char buf2[100];
    //打开鼠标
    int fd = -1;
    fd = open("/dev/input/mouse1",O_RDONLY);
    if (fd<0)
    {
        perror("oppen");
        return -1;
    }
    //读鼠标
    memset(buf,0,sizeof(buf));
    printf("before 鼠标 read.\n");
    read(fd,buf,5);
    printf("读出的内容是:[%s].\n",buf);

    //读键盘
    memset(buf2,0,sizeof(buf2));
    printf("before 键盘 read.\n");
    read(0,buf2,5);
    printf("读出的内容是:[%s].\n",buf2);
    return 0;
}
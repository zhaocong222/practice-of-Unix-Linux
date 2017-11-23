#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

//读鼠标－非阻塞式
int main(void)
{
    char buf[100];
    int fd = -1;
    //以非阻塞式打开即可
    fd = open("/dev/input/mouse0",O_RDONLY | O_NONBLOCK);
    
    //将buf内容置0
    memset(buf,0,sizeof(buf));

    printf("before read.\n");
    read(fd,buf,5);
    printf("读出的内容是:[%s].\n",buf);

    return 0;
}
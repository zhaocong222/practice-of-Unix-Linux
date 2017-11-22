#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    char buf[100];

    //读取鼠标
    int fd = -1;
    fd = open("/dev/input/mouse1",O_RDONLY);
    if (fd<0)
    {
        perror("oppen");
        return -1;
    }

    memset(buf,0,sizeof(buf));

    printf("before read.\n");
   
    read(fd,buf,5);
    printf("读出的内容是:[%s].\n",buf);

    return 0;
}
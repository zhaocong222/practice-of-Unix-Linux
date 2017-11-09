#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char **argv)
{

    if (argc != 2)
    {
        printf("usage: %s -v\n",argv[0]);
        return -1;
    }

    int fd;
    char buf[100];
    if (!strcmp(argv[1],"-v")){
        fd = open("/proc/version",O_RDONLY);
        if (fd<0)
        {
            perror("open");
            return -1;
        }
        read(fd,buf,sizeof(buf));
        printf("结果是: %s",buf);
    }

}
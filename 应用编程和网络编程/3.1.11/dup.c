#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define FILENAME "1.txt"

void main()
{
    int fd1 = -1,fd2 = -1;
    fd1 = open(FILENAME,O_RDWR | O_CREAT | O_TRUNC, 0777);
    if (fd1 < 0)
    {
        perror("open");
        exit(0);
    }

    printf("fd1 = %d.\n",fd1);

    close(1);  // 1就是标准输出stdout

    //复制文件描述符
    fd2 = dup(fd1); //fd2一定等于1,因为前面刚刚关闭1
    // 1.txt文件和标准输出就绑定起来了，所以以后输出到标准输出的信息就可以到1.txt中查看
    printf("fd2 = %d.\n",fd2);

    close(fd1);

}
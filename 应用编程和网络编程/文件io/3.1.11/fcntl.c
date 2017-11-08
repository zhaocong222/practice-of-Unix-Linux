#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define FILENAME "1.txt"

//结论接续写
//结论接续写
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

    //通过fcntl模拟 dup2 操作
    fd2 = fcntl(fd1, F_DUPFD ,6); 
    
    printf("fd2 = %d.\n",fd2);

    while (1)
    {
        write(fd1,"aa",2);
        sleep(1);
        write(fd2,"bb",2);
    }


    close(fd1);

}
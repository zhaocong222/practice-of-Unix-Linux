#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

//上下文：父进程先open打开1.txt然后写入,子进程打开1.txt然后写入。

//测试 fork一个进程，分别打开同一文件，向文件写， 是分别写还是接续写？
//测试结果是分别写, 仔细对比open.c的不同

//加上O_APPEND 再观察？ 实际测试结果标明 O_APPEND标志可以把父子进程各自独立打开的fd的文件指针给关联起来，实现分别写。
int main(void)
{   
    int fd = -1;
    pid_t pid = -1;
    //fork创建子进程
    pid = fork();
    if (pid > 0)
    {
        //父进程
        //fd = open("1.txt",O_RDWR);

        fd = open("1.txt",O_RDWR | O_APPEND);
        if (fd < 0)
        {
            perror("open");
            exit(-1);
        }
        
        printf("parent.\n");
        write(fd,"hello",5);
        sleep(1);
    }
    else if(pid == 0)
    {
        //父进程
        //fd = open("1.txt",O_RDWR);
        fd = open("1.txt",O_RDWR | O_APPEND);
        if (fd < 0)
        {
            perror("open");
            exit(-1);
        }
    
        //子进程
        printf("child.\n");
        write(fd,"world",5);
        sleep(1);
    }
    else
    {
        perror("fork");
        exit(-1);
    }
    
    //这里要注意，上面如果不加上sleep，会出现父进程或子进程写入完成后关闭fd，导致写不进去.
    close(fd);

    return 1;
}

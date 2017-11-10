#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

//上下文：父进程先open打开一个文件得到fd,然后在fork创建子进程。之后在父子进程中各自write向fd中写入内容

//测试 fork一个进程，向文件写？ 是分别写还是接续写？
//测试结果是接续写（很想O_APPEND标志后的样子）
int main(void)
{
    int fd = -1;
    fd = open("1.txt",O_RDWR | O_TRUNC);
    if (fd < 0)
    {
        perror("open");
        exit(-1);
    }

    pid_t pid = -1;
    //fork创建子进程
    pid = fork();
    if (pid > 0)
    {
        //父进程       
        printf("parent.\n");
        write(fd,"hello",5);
        sleep(1);
    }
    else if(pid == 0)
    {
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

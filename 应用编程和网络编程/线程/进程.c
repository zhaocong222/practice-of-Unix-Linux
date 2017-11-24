#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
    //思路就是创建子进程，然后父子进程中分别进行读键盘和鼠标的工作
    pid_t pid;
    int fd = -1;
    char buf[100] = {0};
    pid = fork();

    if (pid<0)
    {
        perror("fork");
    }
    else if(pid == 0)
    {
        while(1)
        {
            //子进程读鼠标
            fd = open("/dev/input/mouse0",O_RDONLY);
            if (fd < 0)
            {   
                perror("open:");
                return -1;
            }   

            read(fd,buf,10);
            printf("鼠标读出的变量是:[%s]\n",buf);
        } 

    }
    else 
    {
        while(1)
        {
            //父进程读键盘
            read(0,buf,4);
            printf("键盘读出的变量是:[%s]\n",buf);
        }
        
    }


}
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid = 1;
    pid_t ret = -1;
    int status;
    pid = fork();

    if(pid >0)
    {
        //父进程  
        printf("parent.\n");
        ret =  wait(&status); //wait 阻塞 等待操作系统的信号 回收子进程
        printf("子进程已经被回收，子进程pid = %d.\n",ret);
        //WIFEXITED 宏用来判断进程是否正常终止 -> exit，return，_exit
        //WIFSIGNALED 宏用来判断进程是否非正常终止 (被信号终止)
        //WEXITSTATUS 宏用来得到正常终止情况下的进程返回值的。（正值）
        printf("子进程是否正常终止：%d\n",WIFEXITED(status));
        printf("子进程是否非正常终止：%d\n",WIFSIGNALED(status));
        printf("正常终止值是：%d\n",WEXITSTATUS(status)); // return exit _exit的值


    }
    else if(pid == 0)
    {
        //子进程
        printf("child pid = %d.\n",getpid());
        /*
        while(1)
            sleep(1);
        */
        return 122;
    }
    else 
    {
       perror("fork");
       return  -1;
    }

    return 0;
}
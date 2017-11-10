#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = -1;
    pid_t ppid = -1;

    printf("hello\n");
    pid = getpid(); //当前进程id
    printf("pid = %d.\n",pid);
    ppid = getppid(); //父进程id
    printf("ppid = %d.\n",ppid);
    
}
#include <stdio.h>

int main(void)
{
    extern char **environ; //进程所在的环境变量表
    int i = 0;
    while(NULL != environ[i])
    {
        printf("%s\n",environ[i]);
        i++;
    }

    return 0;
}
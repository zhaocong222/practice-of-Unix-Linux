#include <stdio.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

//利用多线程改造main2实现的功能
char buf[200] = {0};






int main2(void)
{      
    char buf[200] = {0};
    printf("输入一个字符串，以回车结束\n");
    //scanf("%s",buf);
    //printf("%s",buf);

    while(scanf("%s",buf))
    {
        if (!strcmp(buf,"end"))
        {
            printf("程序结束\n");
            break;
        }
        
        //printf("本次输入的字符是:%s\n",buf);
        printf("本次输入的字符个数是:%ld\n",strlen(buf));
        memset(buf,0,sizeof(buf));

    }
    return 0;
}
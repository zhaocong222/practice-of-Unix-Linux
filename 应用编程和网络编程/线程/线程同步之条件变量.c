#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>

//利用多线程改造main2实现的功能
char buf[200] = {0};

int flag = 1;

//子线程程序，作用是统计buf中的字符个数，并打印
void *func(void *arg)
{
    //子线程首先应该有个循环
    //循环中阻塞在等待主线程激活的时候，子线程被激活后就去获取buf中的字符长度
    //然后打印；完成后再次被阻塞
    while(flag)
    {

        printf("本次输入的字符个数是:%ld\n",strlen(buf));
        memset(buf,0,sizeof(buf));
    }

    //子线程退出
    pthread_exit(NULL);
}


int main(void)
{
    int ret = -1;
    pthread_t th = -1;  



    printf("输入一个字符串，以回车结束\n");

     ret = pthread_create(&th,NULL,func,NULL);
    if (ret!= 0)
    {
        printf("pthread_create error.\n");
        exit(-1);
    }


    while(scanf("%s",buf))
    {
        if (!strcmp(buf,"end"))
        {
            flag = 0;
            printf("程序结束\n");
            break;
        }

        //发信号激活子线程来计数
        //子线程被阻塞，主线程可以激活，这就是同步问题。
        
    }

    //回收子线程
    ret = pthread_join(th,NULL);
    if (ret!= 0)
    {
        printf("pthread_join error.\n");
        exit(-1);
    }
    

    printf("子线程回收成功\n");

    return 0;
}



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
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
//信号类型
sem_t sem;
int flag = 1;

//子线程程序，作用是统计buf中的字符个数，并打印
void *func(void *arg)
{
    //子线程首先应该有个循环
    //循环中阻塞在等待主线程激活的时候，子线程被激活后就去获取buf中的字符长度
    //然后打印；完成后再次被阻塞
    while(flag)
    {
        /*
        sem_wait是一个函数，也是一个原子操作，它的作用是从信号量的值减去一个“1”，但它永远会先等待该信号量为一个非零值才开始做减法。也就是说，如果你对一个值为2的信号量调用sem_wait()，线程将会继续执行，将信号量的值将减到1。
        如果对一个值为0的信号量调用sem_wait()，这个函数就会原地等待直到有其它线程增加了这个值使它不再是0为止。如果有两个线程都在sem_wait()中等待同一个信号量变成非零值，那么当它被第三个线程增加 一个“1”时，等待线程中只有一个能够对信号量做减法并继续执行，另一个还将处于等待状态。sem_trywait(sem_t *sem)是函数sem_wait的非阻塞版，它直接将信号量sem减1，同时返回错误代码。
        */
        sem_wait(&sem); //阻塞当前线程直到信号量sem的值大于0
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

    //初始化信号
    sem_init(&sem,0,0);

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
            sem_post(&sem);
            printf("程序结束\n");
            break;
        }

        //发信号激活子线程来计数
        //子线程被阻塞，主线程可以激活，这就是同步问题。
        //利用信号量解决
        sem_post(&sem); /* 信号量+1 */
    }

    //回收子线程
    ret = pthread_join(th,NULL);
    if (ret!= 0)
    {
        printf("pthread_join error.\n");
        exit(-1);
    }
    //销毁信号量
    sem_destroy(&sem);

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
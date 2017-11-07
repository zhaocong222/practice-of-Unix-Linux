#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/*
fd1:[ia].
fd1:[ia].
fd1:[mz].
fd1:[mz].
fd1:[ha].
fd1:[ha].
fd1:[oc].
fd1:[oc].
fd1:[on].
fd1:[on].
fd1:[g].
fd1:[g].
fd1:[].
fd1:[].
*/

//验证-分别写入
int main(int ac,char *agr[])
{
    int fd1 = -1,fd2 = -1;
    char buf[100];
    char writebuf[20] = "i love linux";
    int ret = -1;

    //实验证明是分别写，如果想续接写 加上 O_APPEND参数
    fd1 = open("b.txt",O_RDWR | O_TRUNC | O_CREAT,0666);
    fd2 = open("b.txt",O_RDWR | O_TRUNC | O_CREAT,0666);

    if ((fd1 < 0) || (fd2 < 0))
    {
        perror("open失败");
        exit(0);
    }
    else
    {
        printf("文件打开成功,fd1 = %d,fd2 = %d.\n",fd1,fd2);
    }

    sleep(1);

#if 1

    while(1)
    {
//第二步：读写文件
    //写文件
    ret = write(fd1,"ab",2);
    if (ret < 0)
    {
        perror("write失败");
        exit(-1);
    }
    else
    {
        printf("write成功,写入了%d个字符\n",ret);
    }

        sleep(1);

    ret = write(fd2,"cd",2);
    if (ret < 0)
    {
        perror("write失败");
        exit(-1);
    }
    else
    {
        printf("write成功,写入了%d个字符\n",ret);
    }

        sleep(1);
    }
       
#endif

#if 0

    while(1)
    {

        //读文件
        //清空buf
        memset(buf,0,sizeof(buf));
    
        ret = read(fd1,buf,2);
        if (ret < 0)
        {
            printf("read失败\n");
            exit(-1);
        }
        else
        {
            printf("fd1:[%s].\n",buf);
        }
    
        sleep(1);
    
        memset(buf,0,sizeof(buf));
        
        ret = read(fd2,buf,2);
        if (ret < 0)
        {
            printf("read失败\n");
            exit(-1);
        }
        else
        {
            printf("fd1:[%s].\n",buf);
        }

    }

#endif

    close(fd1);
    close(fd2);

    exit(0);
}
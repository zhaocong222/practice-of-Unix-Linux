#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

//用lseek计算文件长度
int cal_len (char *pathname)
{
    int fd = -1;
    int ret = -1;

    //第一步：打开文件
    fd = open(pathname,O_RDONLY);
    if (-1 == fd) //有时候也写成: (fd<0)
    {
        perror("open失败");
        return -1;
    }
    /*
    else
    {
        printf("文件打开成功,fd = %d.\n",fd);
    }
    */

    //此时文件指针指向文件开头
    //我们用lseek将文件指针移动到末尾,然后返回值就是长度
    ret  = lseek(fd,0,SEEK_END);
    
    return ret;
}


int  main(int argc,char *argv[])
{
    if (argc != 2)
    {   
        printf("usage: %s filename\n",argv[0]);
        exit(-1);
    }
    

    printf("文件长度是：%d个字节",cal_len(argv[1]));

    return 1;




}
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

//lseek构建空洞文件
int main(int ac,char *agr[])
{
    int fd = -1;

    fd = open("b.txt",O_RDWR | O_CREAT);
    if (fd < 0)
    {
        perror("open失败");
        exit(0);
    }
    else
    {
        printf("文件打开成功,fd = %d.\n",fd);
    }

    int ret;
    //文件指针向后偏移了10个字符
    ret = lseek(fd,10,SEEK_SET);
    printf("lseek,ret = %d.\n",ret);
    
    //写入
    char writebuff[20] = "abcd";
    ret = write(fd,writebuff,3);

    return 1;

}
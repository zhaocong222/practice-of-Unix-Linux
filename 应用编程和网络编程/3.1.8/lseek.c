#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac,char *agr[])
{
    int fd = -1;

    fd = open("a.txt",O_RDWR);
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
    //文件指针向后便宜了3个字符
    ret = lseek(fd,3,SEEK_SET);
    printf("lseek,ret = %d.\n",ret);

    char readbuf[20];
    ret = read(fd,readbuf,20);
    if (ret <0)
	{
		printf("读取失败");
		exit(0);
	}
	else 
	{
		printf("实际读取了%d字节.\n",ret);
		printf("文件内容是:%s.\n",readbuf);
    }
    
    return 1;

}
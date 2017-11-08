#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int ac,char * arg[])
{
	int fd = -1;
	int ret;

    //文件a.txt必须存在，O_RDWR可读可写
	fd = open("a.txt",O_RDWR);
	if (fd == -1)
	{
		printf("打开文件失败\n");
		exit(0);
	}
	else 
	{
		printf("文件打开成功，fd = %d.\n",fd);
	}		
	
	char writebuf[20] = "hello world";
 	ret = write(fd,writebuf,strlen(writebuf));		
	if (ret == -1)
	{
		printf("文件写入失败");
		exit(0);
	}
	else 
	{
		printf("文件写入成功,写入了%d个字符\n",fd);	
	}
	
	char readbuf[20];
	//这里需要重新open,要不然无法read出内容(文件指针指向开头)
	fd = open("a.txt", O_RDONLY);
	ret = read(fd,readbuf,strlen(writebuf));	
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



	close(fd);
	return 0;
}
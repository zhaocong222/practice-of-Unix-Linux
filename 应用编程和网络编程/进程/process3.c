#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define FILE "./aston_test_single"

void delete_file(void)
{
    remove(FILE);
}

//让程序不能被多次执行
int main(void)
{
    //程序执行之初,先去判断文件是否存在
    //O_EXCL如果文件存在会报错
    int fd = -1;
    fd = open(FILE,O_RDWR | O_TRUNC | O_CREAT | O_EXCL,0664);
    if (fd < 0)
    {
        //文件存在的错误
        if (errno == EEXIST)
        {
            printf("错误是文件已经存在,并不要重复执行\n");
            return -1;
        }
    }
    //当进程被正常终止时，系统会自动调用这里注册的delete_file执行
    atexit(delete_file);
    printf("打开成功\n");

    int i = 0;
    for (i=0;i<10;i++)
    {
        printf("I am running...%d\n",i);
        sleep(1);
    }

    return 0;
 
}
#include <stdio.h>
#include <unistd.h>

#define NAME "3.txt"

void main()
{
    int ret = -1;
    ret = access(NAME,F_OK);
    if (ret < 0)
    {   
        printf("文件不存在\n");
        exit(-1);
    }

    ret = access(NAME,R_OK);
    if (ret < 0)
    {
        printf("文件不可读\n");
    }
    else
    {
        printf("文件可读\n");
    }

    ret = access(NAME,W_OK);
    if (ret < 0)
    {
        printf("文件不可写\n");
    }
    else
    {
        printf("文件可写\n");
    }

    ret = access(NAME,X_OK);
    if (ret < 0)
    {
        printf("文件不可执行\n");
    }
    else
    {
        printf("文件可执行\n");
    }


}
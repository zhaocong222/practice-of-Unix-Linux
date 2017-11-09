#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

void main()
{
    struct timeval tv;
    struct timezone tz;
    int ret;

    ret = gettimeofday(&tv,&tz);
    if (ret < 0)
    {
        perror("gettimeofday");
        exit(-1);
    }
    //返回当前的秒
    printf("seconde:%ld",tv.tv_sec);


}
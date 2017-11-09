#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char buf[100];
    struct tm *tmNow;
    time_t lt;

    time(&lt);
    tmNow = localtime(&lt);

    memset(buf,0,sizeof(buf));
    //自定义格式
    strftime(buf,sizeof(buf),"%Y-%m-%d, %H:%M:%S.",tmNow);

    printf("时间为:[%s]",buf);

}
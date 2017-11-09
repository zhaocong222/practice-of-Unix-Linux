#include <stdio.h>
#include <time.h>

void main()
{   
/*
    struct tm {
        int tm_sec;          秒，范围从 0 到 59                
        int tm_min;          分，范围从 0 到 59                
        int tm_hour;         小时，范围从 0 到 23                
        int tm_mday;         一月中的第几天，范围从 1 到 31                    
        int tm_mon;          月份，范围从 0 到 11                
        int tm_year;         自 1900 起的年数                
        int tm_wday;         一周中的第几天，范围从 0 到 6                
        int tm_yday;         一年中的第几天，范围从 0 到 365                    
        int tm_isdst;        夏令时                            
    };
*/

    time_t t;
    
    struct tm *info;
    time(&t);
   
    info = gmtime(&t);

    printf("%d",info->tm_year);
   
    

}

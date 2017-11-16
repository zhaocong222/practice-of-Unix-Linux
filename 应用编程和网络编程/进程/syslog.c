#include <stdio.h>
#include <sys/klog.h>
#include <syslog.h>

//syslog记录日志信息
//cat /var/log/syslog ->Nov 16 11:10:01 lemon-pc a.out[7225]: this is my log info.

int main(void)
{   
    //打开日志
    openlog("a.out",LOG_PID | LOG_CONS,LOG_USER);
    //写日志
    syslog(LOG_INFO,"this is my log info.");
    //关闭日志
    closelog();
}
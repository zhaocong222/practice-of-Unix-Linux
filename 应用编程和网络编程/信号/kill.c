#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

void main()
{   
/*
(1)SIGINT			2		Ctrl+C时OS送给前台进程组中每个进程
(2)SIGABRT			6		调用abort函数，进程异常终止
(3)SIGPOLL	SIGIO	8		指示一个异步IO事件，在高级IO中提及
(4)SIGKILL			9		杀死进程的终极办法
(5)SIGSEGV			11		无效存储访问时OS发出该信号
(6)SIGPIPE			13		涉及管道和socket
(7)SIGALARM			14		涉及alarm函数的实现
(8)SIGTERM			15		kill命令发送的OS默认终止信号
(9)SIGCHLD			17		子进程终止或停止时OS向其父进程发此信号
(10)
SIGUSR1				10		用户自定义信号，作用和意义由应用自己定义
SIGUSR2				12
*/

    //强制杀死 进程ｉｄ为 31585 的进程
    kill(31585,SIGKILL);
}
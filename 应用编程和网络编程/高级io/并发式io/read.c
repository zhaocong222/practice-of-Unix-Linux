#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    char buf[100];
    int flag = -1;

    //把0号文件描述符(stdin)变成非阻塞
    //通过fcntl可以改变已打开的文件性质
    flag = fcntl(0,F_GETFL);//1.先获取原来的flag
    flag |= O_NONBLOCK;     //2.添加非阻塞属性(利用位或)
    fcntl(0,F_SETFL,flag);  //3.写入
    //上面3步后，0就变成了非阻塞

    //将buf内容置0
    memset(buf,0,sizeof(buf));

    printf("before read.\n");
    //第一个参数0代表读取键盘 
    //键盘就是标准输入stdin,读取2个字符
    read(0,buf,2);
    printf("读出的内容是:[%s].\n",buf);

    return 0;
}
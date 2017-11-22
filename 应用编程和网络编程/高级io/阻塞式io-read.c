#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    char buf[100];

    //将buf内容置0
    memset(buf,0,sizeof(buf));

    printf("before read.\n");
    //第一个参数0代表读取键盘 
    //键盘就是标准输入stdin,读取2个字符
    //read是阻塞的
    read(0,buf,2);
    printf("读出的内容是:[%s].\n",buf);

    return 0;
}
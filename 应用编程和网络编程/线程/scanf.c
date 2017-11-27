#include <stdio.h>

int main(void)
{
    char buf[100];
    printf("输入一个字符串，以回车结束\n");
    scanf("%s",buf);
    printf("输入的是：%s\n",buf);

    return 0;
}
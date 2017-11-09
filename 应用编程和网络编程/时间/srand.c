#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    time(&t);
    srand(t); //设置随机数种子

    printf("%d",rand());

    return 1;
}
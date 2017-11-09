#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main()
{
    time_t t;
    //time(&t);
    t = time(NULL);

    printf("%s",ctime(&t));
}
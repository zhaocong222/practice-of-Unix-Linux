#include <stdio.h>
#include <stdlib.h>

#define FILENAME "1.txt"

int main(void)
{
    FILE *fp = NULL;
    int array[] = {1,2,3,4};
    int buf[10];
    int len;

    fp = fopen(FILENAME,"w+");
    if (NULL == fp)
    {
        perror("fopen");
        exit(-1);
    }

    //写文件
    //len = fwrite("abcedf",1,5,fp);
    len = fwrite(array,sizeof(int),sizeof(array) / sizeof(array[0]) ,fp);
    printf("len = %d.\n",len);

    //此时文件指针在末尾,偏移到文件头部
    fseek(fp,0L,SEEK_SET);

    //读文件
    if (fp == NULL)
    {
        perror("fopen");
        exit(-1);
    }

    len = fread(buf,sizeof(int),4,fp);
    if (len == 0)
    {
        perror("fread");
        exit(-1);
    }

    for (int i =0; i<len;i++)
    {
        printf("%d\n",buf[i]);
    }

    fclose(fp);
    return 0;
}

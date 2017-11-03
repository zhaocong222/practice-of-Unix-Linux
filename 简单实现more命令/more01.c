#include <stdio.h>
#include <stdlib.h>

//每次显示10页
#define PAGELEN 10
//最大字节
#define LEN 512

void do_more(FILE *);
int see_more();

int main(int ac,char *av[])
{
    //FILE类型指针fp
    FILE *fp;

    //如果只有1个参数，从标准输入流中读取
    //否则从文件读取
    if (ac == 1)
        do_more(stdin); 
    else
    {
        if ((fp = fopen(av[1],"r")) != NULL)
        {
            do_more(fp);
            fclose(fp);
        }
        else
            exit(1);
    }

    return 0;

}

/*
 * 处理文件函数
 */
void do_more(FILE *fp)
{   

    char data[LEN];
    int num_of_lines = 0;
    int see_more(),reply;

    /*
     * 直到取不到值位置
     * 每次取一行，最多读取LEN-1字符
     */
    while(fgets(data,LEN,fp) != NULL)
    {   
        
        //如果已经读取了 PAGELEN 行
        if (num_of_lines == PAGELEN){ //最多显示PAGELEN行
            reply = see_more();
            
            if (reply == 0)
                break;
            
            num_of_lines -= reply;
        }

        //通过标准输出流 输出
        if (fputs(data,stdout) == EOF)
            exit(1);

        num_of_lines++;
    }
}

int see_more()
{
    int c;
    //白底黑字 \033[7m str \033[m
    printf("\033[7m more? \033[m");

    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
            case 'q':
                return 0;
                break;
            case ' ':
                return PAGELEN; //空格返回PAGELEN行
                break;
            case '\n':
            default:
                return 1;  //回车 只返回一行
                break;
        }
    } 

    return 0;
}
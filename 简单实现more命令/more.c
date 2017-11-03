/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<stdio.h>
#include<stdlib.h>
#define PAGELEN 5
#define LINELEN 512

//实现基础功能，显示每一页固定24行文本，“q Enter”退出， “Enter” 下一行， “space Enter”下一页。
void do_more(FILE *);
int see_more();

int main (int ac, char *av[])
{    
    FILE *fp;
    
    if ( ac == 1)
        do_more(stdin); //如果没有第2个参数 从标准输入获取内容
    else 
    {
        while(--ac){
            //* ++av 命令行第二个参数（文件名）
            if ( (fp = fopen(* ++av, "r")) != NULL ){  //打开文件
                do_more(fp);
                fclose(fp);
            } else {
                exit(1);
            }
        }
    }
    return 0;
    
}

void do_more(FILE *fp)
{
    //定义变量
    char line[LINELEN];
    int num_of_lines = 0;
    int see_more(),reply;
        
    /*
     * 直到取不到值位置
     * 每次取一行，最多读取LEN-1字符
     */
    while (fgets(line,LINELEN,fp)){
        
        //如果已经读取了 PAGELEN 行
        if (num_of_lines == PAGELEN){ //最多显示PAGELEN行
            reply = see_more();
            
            if (reply == 0)
                break;
            
            
            num_of_lines -= reply;
        }
        
        //通过标准输出流 输出
        if (fputs(line,stdout) == EOF){
            exit(1);
        }
        num_of_lines++;
    }
}

int see_more()
{
    int c;
    //白底黑字 \033[7m str \033[m
    printf("\033[7m more? \033[m");
    while( (c = getchar()) != EOF)
    {
        if ( c == 'q')
            return 0;
        else if ( c == ' ')
            return PAGELEN; //空格返回PAGELEN行
        else if ( c == '\n' )  
            return 1;  //回车 只返回一行
    }
    
    return 0;
 
            
}


#include <stdio.h>

/*
void test(char str)
{
    printf("str = %c\n",str);
}
*/

void test2(char str[])
{
    printf("str = %s\n",str);
}

void test3(char *str)
{
    printf("str = %s\n",str);
}

void main()
{   
    //char s = 'a';
    //test(s);

    char s2[] = "abc";
    test2(s2);
    test3(s2);

    char *s3 = "abcd";
    test2(s3);
    test3(s3);
    
    printf("%c",s2[0]);
    printf("%s",s2);



}
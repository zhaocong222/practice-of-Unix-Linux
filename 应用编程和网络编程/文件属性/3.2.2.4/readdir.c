#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>

int main (int argc, char **agrv)
{   
    if (argc != 2)
    {
        printf("缺少参数");
        exit(-1);
    }

    // man 3 opendir -> DIR *opendir(const char *name); 
    // man 3 readdir -> struct dirent *readdir(DIR *dirp);
    DIR *dir;
    struct dirent *ptr;
    
    dir = opendir(agrv[1]);
    while((ptr = readdir(dir)) != NULL)
    {
        printf("d_name:%s\n",ptr->d_name);
    }

    closedir(dir);

    return 1;

}
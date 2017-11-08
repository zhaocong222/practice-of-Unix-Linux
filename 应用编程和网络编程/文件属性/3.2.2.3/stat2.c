#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define NAME "1.txt"

void main()
{
    int ret = -1;
    /*
    struct stat  
    {   
        dev_t       st_dev;     // ID of device containing file -文件所在设备的ID
        ino_t       st_ino;     // inode number -inode节点号   
        mode_t      st_mode;    // protection -保护模式?    
        nlink_t     st_nlink;   // number of hard links -链向此文件的连接数(硬连接)    
        uid_t       st_uid;     // user ID of owner -user id   
        gid_t       st_gid;     // group ID of owner - group id    
        dev_t       st_rdev;    // device ID (if special file) -设备号，针对设备文件  
        off_t       st_size;    // total size, in bytes -文件大小，字节为单位    
        blksize_t   st_blksize; // blocksize for filesystem I/O -系统块的大小  
        blkcnt_t    st_blocks;  // number of blocks allocated -文件所占块数 
        time_t      st_atime;   // time of last access -最近存取时间 
        time_t      st_mtime;   // time of last modification -最近修改时间    
        time_t      st_ctime;   // time of last status change -    
    };  
    */
    //定义buf结构体
    struct stat buf;

    memset(&buf,0,sizeof(buf)); // memset后buf中全是0

    ret = stat(NAME,&buf);  //stat后buf中有内容了

    if (ret < 0)
    {
        perror("stat");
        exit(-1);
    }

#if 0

    //判断文件夹 S_ISDIR
    //判断这个文件属性
    int result = S_ISREG(buf.st_mode);
    //1  代表普通文件
    printf("result = %d\n",result);

#endif

    //文件权限测试
    unsigned int result = (buf.st_mode & S_IRWXU);
    printf("file owner: %u.\n",result);

}
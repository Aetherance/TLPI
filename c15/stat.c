#include<stdio.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#include<stdlib.h>
int main(int argc,char **argv)
{
    // DIR * dir = opendir(argv[1]);
    // struct dirent sdirent;
    // struct dirent * rdirent = &sdirent;
    struct stat buf__stat;    // 开辟空间
    struct stat * statbuf = &buf__stat;

    //statbuf = readdir(dir);
    stat("./stat",statbuf);
    







    return 0;    
}
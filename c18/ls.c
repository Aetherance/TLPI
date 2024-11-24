#include<stdio.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#include<stdlib.h>
int main(int argc,char **argv)
{
    if(argc==1)
        argv[1] = ".";
    
    DIR * dir = opendir(argv[1]);
    struct dirent * rdirent;
    struct stat * statbuf;

    if(dir == NULL)
    {
        printf("ls: 无法访问 '%s': 没有那个文件或目录\n",argv[1]);
        return 1;
    }


    while((rdirent = readdir(dir))!=NULL)
    {

        char path_[1000],path[1000];
        sprintf(path_,"%s/%s",argv[1],rdirent->d_name);
        realpath(path_,path);
        stat(path,statbuf);

        // print
        if(S_ISREG(statbuf->st_mode)&&!(statbuf->st_mode & S_IXUSR))printf("%s  ",rdirent->d_name);
        if(S_ISREG(statbuf->st_mode)&& (statbuf->st_mode & S_IXUSR))printf("\033[;1;32m%s  \033[0m",rdirent->d_name);
        if(S_ISDIR(statbuf->st_mode))printf("\033[;1;34m%s  \033[0m",rdirent->d_name);
    }
    
    



    return  0;
}
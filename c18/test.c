#include<stdio.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#include<stdlib.h>
int main(int argc,char **argv)
{
    argv[1] = ".";
    DIR * dir = opendir(argv[1]);
    struct dirent * rdirent;
    struct stat buf;
    struct stat * statbuf = &buf;

    rdirent = readdir(dir);
    rdirent = readdir(dir);
    
    char path_[1000],path[1000];

            sprintf(path_,"%s/%s",argv[1],rdirent->d_name);
            realpath(rdirent->d_name,path);
            
            stat(rdirent->d_name,statbuf);

            // print
            
            printf("%s",rdirent->d_name);
            if(S_ISREG(statbuf->st_mode)&&!(statbuf->st_mode & S_IXUSR))printf("%s  ",rdirent->d_name);
            if(S_ISREG(statbuf->st_mode)&& (statbuf->st_mode & S_IXUSR))printf("\033[;1;32m%s  \033[0m",rdirent->d_name);
            if(S_ISDIR(statbuf->st_mode))printf("\033[;1;34m%s  \033[0m",rdirent->d_name);
}
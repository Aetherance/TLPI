#include<stdio.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
int main(int argc,char ** argv)
{
    if(argc==1)argv[1] = ".";
    struct dirent * temp;
    DIR* dir = opendir(argv[1]);
    if(dir==NULL)
    {   
        printf("ls: 无法访问 '%s': 没有那个文件或目录\n",argv[1]);
        return 1;
    }
    struct stat* temp_stat;
    char * temp_name;
    while((temp = readdir(dir))!=NULL)
    {
        if(!strcmp(temp->d_name,".")||!strcmp(temp->d_name,".."))continue;
        sprintf(temp_name,"./%s",temp->d_name);
        stat(temp_name,temp_stat);
        if(S_ISREG(temp_stat->st_mode)&&!(temp_stat->st_mode & S_IXUSR))printf("%s  ",temp->d_name);
        if(S_ISREG(temp_stat->st_mode)&& (temp_stat->st_mode & S_IXUSR))printf("\033[;1;32m%s  \033[0m",temp->d_name);
        if(S_ISDIR(temp_stat->st_mode))printf("\033[;1;34m%s  \033[0m",temp->d_name);
    }


    printf("\n");
    return 0;
}
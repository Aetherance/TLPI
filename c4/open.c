#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int fd = open("/home/user/CODE/TLPI/TF/0.txt",O_RDWR);
    FILE* fp = fdopen(fd,"r+w");
    char * str = (char *)malloc(1280);
    fscanf(fp,"\n%[^\n]",str);
    printf("%s\n",str);
    fscanf(fp,"\n%[^\n]",str);
    printf("%s",str);

    close(fd);
    free(fp);
    return 0;
}
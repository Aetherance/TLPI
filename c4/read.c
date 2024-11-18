#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int fd = open("/home/user/CODE/TLPI/TF/1.txt",O_RDWR);
    if(fd == -1)printf("Open Error!\n");
    char * str = (char *)malloc(1280);
    read(fd,str,20);
    printf("%s",str);

    close(fd);
    return 0;
}
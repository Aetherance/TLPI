#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int fd = open("/home/user/CODE/TLPI/TF/hellowrite.txt",O_RDWR|O_CREAT);
    if(fd == -1)printf("Open Error!\n");
    char str[] = "hello write!";
    write(fd,str,5);

    return 0;
}
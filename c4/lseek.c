#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
void test(int a,...)
{
    
}
int main()
{
    int fd = open("/home/user/CODE/TLPI/TF/num.txt",O_RDWR);
    lseek(fd,-1,SEEK_SET);
    
    char buf[100];
    read(fd,buf,5);
    printf("Here the buf is : ");
    printf("%s",buf);

    close(fd);
    return 0;
}
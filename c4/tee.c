#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char**argv)
{

    char buf[1000000];
    if(argc==1)
    {
        scanf("%[^\n]",buf);
        printf("%s",buf);
        return 0;
    }               
    else if(argc == 2)
    {
        int fd = open("./1",O_RDWR|O_TRUNC|O_CREAT,S_IRUSR|S_IWUSR);
        char c;
        int count = 0;
        while ((c = getchar())!=EOF)
        {
            
            
            
        }
        
    }





    return 0;
}
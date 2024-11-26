#include<stdio.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#include<getopt.h>
#include<ctype.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ioctl.h>

int main()
{
    struct winsize win;
    ioctl(STDIN_FILENO,TIOCGWINSZ,&win);
    printf("%d %d",win.ws_col,win.ws_row);




    return 0;
}
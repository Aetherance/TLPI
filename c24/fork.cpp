#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string>
#include<vector>

int main()
{
    // int ret = fork();
    
    char *arg[] = {(char*)"ls",(char*)"--color=auto",NULL};
    if(execvp("ls",arg) == -1)
        return -1;

    exit(EXIT_SUCCESS);

    return 0;
}


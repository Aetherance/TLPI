#include<iostream>
#include<unistd.h>
#include<vector>
#include<wait.h>
using namespace std;
int main()
{
    int fds[2];

    pipe(fds);

    int p1 = fork();

    char str1[] = "ls";
    char str2[] = "wc";

    vector<char*>argv1 = {str1};
    vector<char*>argv2 = {str2};
    if(p1==0)
    {
        dup2(fds[1],1);
        execvp(argv1[0],argv1.data());
        wait(&p1);
    }

    close(fds[1]);

    int p2 = fork();

    if(p2 == 0)
    {
        dup2(fds[0],0);
        execvp(argv2[0],argv2.data());
        wait(&p2);
    }

    close(fds[0]);

    return 0;
}

// 总结 重定向是跨越进程的

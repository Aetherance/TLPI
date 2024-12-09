#include<signal.h>
#include<stdio.h>
void func()
{
    printf("\b\b\b\b\b\b\bDo Not KILL ME!!!\n");
}
int main()
{

    while(1)
    {
        signal(SIGINT,func);
    }



    return 0;
}
#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{
    int fds[2];
    int fdat[2];
    pipe(fds);
    fdat[0] = fds[1];
    pipe(fdat);




    return 0;
}
#include<iostream>
#include<fcntl.h>
#include<unistd.h>

using namespace std;
int main()
{
    int fds[2] = {};
    // pipe(fds);
    cout<<fds[0]<<endl<<fds[1];

    return 0;
}
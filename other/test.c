#include<stdio.h>
typedef int (*FP)(const void * ptr1, const void * ptr2);
int add(const int a,const int b)
{
    return a+b;
}
int sort_init(const void * ptr1, const void * ptr2)
{
    return 1;
}
int main()
{

    FP sort_mode = sort_init;






    return 0;
}
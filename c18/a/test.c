#include<stdio.h>
int f_max(int a[],int len)
{
    int max = 0;
    int pos = 0;
    for(int i = 0;i<len;i++)
    {
        if(a[i]>max)
        {
            max = a[i];
            pos = i;
        }
    }
    return pos;
}
int f_min(int a[],int len)
{
    int min = 2100000;
    int pos = 0;
    for(int i = 0;i<len;i++)
    {
        if(a[i]<min)
        {
            min = a[i];
            pos = i;
        }
    }
    return pos;
}
void fun(int a[],int len)
{
    a[f_min(a,len)] = a[f_min(a,len)] ^ a[f_max(a,len)];
    a[f_max(a,len)] = a[f_min(a,len)] ^ a[f_max(a,len)];
    a[f_min(a,len)] = a[f_min(a,len)] ^ a[f_max(a,len)];
    
}
int main()
{

    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    //调用函数
    fun(arr,n);
    //输出
    for (int i = 0; i < n; ++i) {
        printf("%d ",arr[i]);
    }
    printf("\n");

}

#include<stdio.h>
int fun(int x[], int n)   
{
	int pos, m = 0, j = 0;
	for(pos = 1;pos < n; pos++)
	{
        if(x[pos] > x[m])    
            m = pos; 
        if(x[pos] < x[j])     
            j = pos;  
	}
	pos=x[j];              
	x[j]=x[m];
	x[m]=pos;
 } 
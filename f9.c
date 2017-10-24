#include<stdio.h>
void main()
{
    int i,n=153,s=0,b;
    for(i=n;i>0;i=i/10)
    {
        b=i%10;
        s=s+b*b*b;
    }
    if(n==s)
    {
        printf("the no: is armstrong");
    }
    else
    {
        printf("the no: is not armstrong");
    }
}

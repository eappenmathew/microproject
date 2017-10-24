#include<stdio.h>
void main()
{
    int num,d,rev=0,n;
    num=123;
    n=num;
    for(;n>0;)
    {
        d=n%10;
        rev=(rev*10)+d;
        n=n/10;
    }
    printf("rev of num=%d",rev);
}


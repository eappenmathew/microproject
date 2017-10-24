#include<stdio.h>
void main()
{
    int num=439,n=num,d;
    for(;n>0;n=n/10)
    {
        d=n%10;
        printf("%4d",d);
    }
}

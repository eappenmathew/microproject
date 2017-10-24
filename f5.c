#include<stdio.h>
void main()
{
    int num=439,n=num,d,sum=0;
    for(;n>0;n=n/10)
    {
        d=n%10;
        sum=sum+d;
    }
    printf("summ of digits=%d",sum);
}

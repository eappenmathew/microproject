#include<stdio.h>
void main()
{
    int num=123123,sum=0,d=0;
    sum=sum+num%10;
    for(;num>0;num=num/10)
    {
        d=num%10;
    }
    sum=sum+d;
    printf("the sum =%d",sum);
}

#include<stdio.h>
#include<conio.h>
void main()
{
    int num=57,sum=0,d,n;
    for(n=num;n>9;)
    {
        sum=0;
        for(;num>0;num=num/10)
        {
            d=num%10;
            sum=sum+d;
        }
        n=sum;
        num=n;

    }
    printf("the sum=%d",n);
}

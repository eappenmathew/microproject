#include<stdio.h>
void main()
{
    int num=439,n=num,d,pro=1;
    for(;n>0;n=n/10)
    {
        d=n%10;
        pro=pro*d;
    }
    printf("product of digits=%d",pro);
}

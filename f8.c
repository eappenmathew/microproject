#include<stdio.h>
void main()
{
    int num,d,rev=0,n;
    num=12321;
    n=num;
    for(;n>0;)
    {
        d=n%10;
        rev=(rev*10)+d;
        n=n/10;
    }
    if(num==rev)
    {
        printf("the no: is palindrome");
    }
    else
    {
        printf("the no: is not palindrome");
    }
}


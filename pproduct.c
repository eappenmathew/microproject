#include<stdio.h>
#include<conio.h>
void main()
{
    int num=1234,rev=0,d,p;
    for(p=1;num>0;num=num/10)
    {
        d=num%10;
        //if(p==1||p==4)
            rev=(rev*10)+d;
        p++;
    }
    printf("the product=%d",rev);
}

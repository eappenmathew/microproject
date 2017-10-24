#include<conio.h>
#include<stdio.h>
void main()
{
    int num=453,dig,sum,a;
    for(num=1;num<=20;num++)
    {
        sum=0;
        for(a=num;a>0;a=a/10)
        {
            sum=sum+(a%10);
        }
        printf("\n %d \t %d",num,sum);

    }
getch();
}

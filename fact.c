#include<conio.h>
#include<stdio.h>
void main()
{
    int a,b=1,n;
    printf("enter the no:");
    scanf("%d",&a);
    for(n=1;n<=a;n++)
    {
        b=b*n;
    }
    printf("The factorial of %d is %d",a,b);
}

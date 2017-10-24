#include<stdio.h>
#include<conio.h>
void main ()
{
    int a[5]={1,2,3,4,5},large,small,sum=0,i;
    large=a[0];
    for(i=0;i<=4;i++)
    {
        if(a[i]>large)
            large=a[i];
    }
    printf("Largest No: is %d \n",large);
    small=a[0];
    for(i=0;i<=4;i++)
    {
        if(a[i]<small)
            small=a[i];
    }
    printf("Smallest no:is %d \n",small);
    for(i=0;i<=4;i++)
    {
        sum=sum+a[i];
    }
    printf("Sumof nos: is %d",sum);
    getch();
}

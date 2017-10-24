#include<conio.h>
#include<stdio.h>
void main()
{
    int a[5]={5677,2,45,4,5},temp,i,j;
    for(j=1;j<=3;j++)
    {
        for(i=0;i<4;i++)
        {
            if(a[i]>a[i+1])
            {
                temp=a[i+1];
                a[i+1]=a[i];
                a[i]=temp;
            }
        }
    }
    for(i=0;i<5;i++)
    {
        printf("%d ,",a[i]);
    }
}

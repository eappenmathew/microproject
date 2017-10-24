#include<stdio.h>
#include<conio.h>
void main ()
{
    int a[10]={5677,2,45,4,5},temp,i,j,p,v ,temp1;
    printf("enter the position and value");
    scanf("%d %d",&p,&v);
    for(i=5;i>=0;i--)
    {
        a[i+1]=a[i];
        if(i==p)
        {
            //temp=a[i];
            a[i]=v;
            //j=i+1;
        }
    }
    /*a[j]=temp;
    j=9;
    for(;j>i+1;j--)
    {
        //temp1=a[j+1];
        //a[j+1]=a[j];
        //a[j]=temp1;
        a[j+1]=a[j];

    }*/
    for(i=0;i<5;i++)
    {
        printf("%d ,",a[i]);
    }
}

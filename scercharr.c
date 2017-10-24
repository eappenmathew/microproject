#include<stdio.h>
void main()
{
    int a[5]={5677,2,45,4,5},temp,i,j=0,s;
    printf("Enter the No:to be finted  ");
    scanf("%d",&s);
    for(i=0;i<5;i++)
    {
        if(s==a[i])
        {
            j=1;
            break;
        }
        else
            j=0;
    }
    if(j==1)
        printf("The no: is founded in the position %d",i);
    else
        printf("The no: is not founded");
}

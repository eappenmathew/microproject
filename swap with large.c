#include<stdio.h>
#include<conio.h>
void main()
{
    int arr[7]={5,8,3,9,22,6,11},p,temp,pass=0,lp=0,large;
    printf("The orginal arr\n");
    for (p=0;p<7;p++)
    {
        printf("%4d",arr[p]);
    }
    printf("\n");
    large=arr[0];
    for (p=1;p<6;p++)//single pass
    {
        if(arr[p]>large)//to find the smallest
        {
            large=arr[p];
            lp=p;
        }
    }
    temp=arr[lp];
    arr[lp]=arr[0];
    arr[0]=temp;
    for (p=0;p<7;p++)
    {
        printf("%4d",arr[p]);
    }
    getch();
}

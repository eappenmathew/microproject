#include<stdio.h>
#include<conio.h>
void main ()
{
    int arr[7]={5,8,3,9,22,6,11},p,temp,pass=0,sp=0;
    printf("The orginal arr\n");
    for (p=0;p<7;p++)
    {
        printf("%4d",arr[p]);
    }
    printf("\n");
    for(pass=0;pass<7;pass++)//multiple pass
    {
        sp=0;
        for (p=0;p<6-pass;p++)//single pass
        {
            if(arr[p]>arr[p+1])
            {
                temp=arr[p];
                arr[p]=arr[p+1];
                arr[p+1]=temp;
                sp=sp+1;
            }
        }
        if(sp==0)//no swap
        {
            break;
        }
    }
    printf("The changed arr\n");
    for (p=0;p<7;p++)
    {
        printf("%4d",arr[p]);
    }
    printf("\n");
    getch();
}

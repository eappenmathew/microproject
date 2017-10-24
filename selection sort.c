#include<stdio.h>
#include<conio.h>
void main()
{
    int arr[7]={12,8,3,9,22,6,11},p,temp,pass=0,sp=0,small;
    printf("The orginal arr\n");
    for (p=0;p<7;p++)
    {
        printf("%4d",arr[p]);
    }
    printf("\n");
    for(pass=0;pass<4;pass++)
    {
        small=arr[pass];
        for (p=pass;p<6;p++)//single pass
        {
            if(arr[p]<small)//to find the smallest
            {
                small=arr[p];
                sp=p;
            }
        }
        temp=arr[pass];
        arr[pass]=arr[sp];
        arr[sp]=temp;
        for (p=0;p<7;p++)
        {
            printf("%4d",arr[p]);
        }
        printf("\n");
    }
    getch();
}

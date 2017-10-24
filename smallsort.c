#include<stdio.h>
#include<conio.h>
void main()
{
    int arr[7]={5,8,3,9,22,6,11},p,temp,pass=0,sp=0,small;
    printf("The orginal arr\n");
    for (p=0;p<7;p++)
    {
        printf("%4d",arr[p]);
    }
    printf("\n");
    small=arr[0];
    for (p=1;p<6;p++)//single pass
        {
            if(arr[p]<=small)//to find the smallest
            {
                small=arr[p];
                sp=p;
            }
        }
    printf("the smallest element is %2d pos=%2d",small,sp);

    getch();
}

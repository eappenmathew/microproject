#include<stdio.h>
#include<conio.h>
void main()
{
    int arr[7]={1,45,96,25,76,43,12},p,temp,small=0,sp=0,pass;
    printf("the orginal arr=\n");
    for(p=0;p<7;p++)
    {
        printf("%4d",arr[p]);
    }
    for(pass=0;pass<7;pass++)
    {
        small=arr[pass];
        for(p=pass;p<7;p++)
        {
            if(arr[p]<=small)
            {
                small=arr[p];
                sp=p;
            }
        }
        temp=arr[sp];
        arr[sp]=arr[pass];
        arr[pass]=temp;
        //printf("\nsp=%d,small=%d\n",sp,small);
    }
    printf("\nthe sorted array=\n");
    for(p=0;p<7;p++)
    {
        printf("%4d",arr[p]);
    }
    getch();
}

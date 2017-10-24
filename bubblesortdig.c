#include<stdio.h>
#include<conio.h>
void main()
{
    int arr[5],i,j,t,pass,sc,num=5732,p,d;
    for(p=3;num>0;num=num/10)
    {
        d=num%10;
       // rev=(rev*10)+d;
        arr[p]=d;
        p--;
    }

    printf(" Orginal Array\n");
    for (i=0;i<4;i++)
    {
        printf("%4d",arr[i]);
    }
    printf("\n");


    for (pass=0;pass<4;pass++)
    {
        sc=0;
        for (i=0;i<4-1-pass;i++)
        {
            if (arr[i]>arr[i+1])
            {
                t=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=t;
                sc++;
            }
        }
        if (sc==0)
            break;
    }


    printf("Sorted Array \n");
    for (i=0;i<4;i++)
    {
        printf("%4d",arr[i]);
    }
    getch();
}

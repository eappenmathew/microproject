#include<stdio.h>
#include<conio.h>
void main()
{
    int arr[4]={7,3,5,1},i,j,t,pass,sc,num=0,p;

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
            if (arr[i]<arr[i+1])
            {
                t=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=t;
                sc++;
            }
        }
        if (sc==0)
            break;
        //printf("\n\n Pass: %d  =>",pass+1);

        /*for (j=0;j<5;j++)
        {
           // printf("%7d",arr[j]);
        }*/

    }


    for(p=0;p<4;p++)
    {
        num=(num*10)+arr[p];
    }
    printf("%d",num);
    getch();
}

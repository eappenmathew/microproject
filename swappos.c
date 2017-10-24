#include<stdio.h>
#include<conio.h>
void main()
{
    int arr[5],i,j,t,pass,sc,num=5732,p,d,pos1,pos2,numcopy;
    numcopy=num;
    for(p=3;num>0;num=num/10)
    {
        d=num%10;
       // rev=(rev*10)+d;
        arr[p]=d;
        p--;
    }
    num=numcopy;
    printf(" num=%d",num);
    /*for (i=0;i<4;i++)
    {
        printf("%4d",arr[i]);
    }*/
    printf("\n");
    printf("enter the two positions");
    scanf("%d%d",&pos1,&pos2);

    /*for (pass=0;pass<4;pass++)
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
    }*/
    t=arr[pos1];
    arr[pos1]=arr[pos2];
    arr[pos2]=t;


    //printf("Sorted Array \n");
    for (i=3;i>-1;i--)
    {
        num=(num*10)+arr[p];
    }
    printf(" num=%d",num);
    getch();
}

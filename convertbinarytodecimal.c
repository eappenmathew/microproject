#include<stdio.h>
#include<math.h>

void main()
{
    int b[10],bin=1010101,i,dec=0,n,j=0,temp=0;
    for(i=0;i<10;i++)
    {
        temp=bin%2;
        b[i]=temp;
        bin=bin/2;
    }
    for(i=0;i<10;i++)
    {
        printf("%d",b[i]);
    }

////    printf("\n\nenter the limit");
////    scanf("%d ",n);
////    for(i=0;i<n;i++)
////    {
////        scanf("%d ",&b[i]);
////    }
////
    for (i=10;i>=0;i--)
    {   if(b[i]==1)
        {
            dec+=pow(2,j);
        }
        j++;
    }

    printf("\n\nDecimal Value:%d",dec);
    }


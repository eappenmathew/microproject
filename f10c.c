#include<stdio.h>
void main()
{
    int d,de=11,h,ht=15;
    for(d=1;d<=de;d++)
    {
        printf("T");
    }
    printf("\n");
    for(h=1;h<=ht-1;h++)
    {
        for(d=1;d<=de;d++)
        {
            if(d==(de+1)/2)
                printf("T");
            else
                printf(" ");
        }
        printf("\n");
    }
}

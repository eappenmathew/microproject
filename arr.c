#include<stdio.h>
void main()
{
    int a[5]={40,7,9,87,56},p;
    for(p=0;p<5;p++)
    {
        if(a[p]%2==1)
            printf("%8d",a[p]);
        else
            printf("        ");
    }
    printf("\n");
    for(p=0;p<5;p++)
    {
        if(p%2==1)
            printf("%8d",a[p]);
        else
            printf("        ");
    }

}

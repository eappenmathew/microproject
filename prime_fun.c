#include<stdio.h>
int prime(int x)
{
    int i,count;
    for(i=2;i<=(x/2);i++)
    {
        if(x%i==0)
            return 0;
        else
            return 1;
    }
}
void main ()
{
    int num,i;
    printf("ENTER NO.");
    scanf("%d",&num);
    i=prime(num);
    if(i==1)
        printf("prime");
    else
        printf("not prime");
}

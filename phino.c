#include<stdio.h>
#include<conio.h>
void main()
{
    int f=0,s=1,t=0,n=10,i;
    //printf("enter the range");
    //scanf("%d",n);
    printf("%d,%d,",f,s);
    //for(i=3;i<=n;i++)
    while(t<=n)
    {
        t=f+s;
        if(t<=n)
            printf("%d,",t);
        f=s;
        s=t;
    }
    getch();
}

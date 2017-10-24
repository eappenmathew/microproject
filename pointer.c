#include<stdio.h>
#include<conio.h>
void main ()
{
    int a=1,b=2,c=3,*pi,i;
    pi=&a;
    for(i=1;i<=3;i++)
    {
        printf("The value is %d \n",*pi);
        pi--;

    }
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",c);

}

#include<stdio.h>

void main()
{
    int n,r,one=0;
    int b[50],l=0,i;

    printf("Enter the decimal:");
    scanf("%d",&n);
    for (;n>0;n=n/2)
    {
        r=n%2;
        if (r==1)
            one++;
        //printf("%3d | %3d\n",n,r);
        b[l]=r;++l;
    }
    for(i=l-1;i>=0;i--)
        printf("%d ",b[i]);

    printf("\n\nNo. of 1s :%d\n",one);
}

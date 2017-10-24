#include<stdio.h>
void main()
{
    int a[3][3]={1,2,3,4,5,6,7,8,9},b[3][3]={1,2,3,4,5,6,7,8,9},i,j,sum[3][3];
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            sum[i][j]=b[i][j]+a[i][j];
        }
    }
    printf("The sum of metrix is\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            printf("%4d",sum[i][j]);
        printf("\n");
    }
}

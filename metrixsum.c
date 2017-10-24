#include<stdio.h>
#include<conio.h>
void main()
{
    int matrix1[100][100];
	int matrix2[100][100];
	int column;
	int row;
	int sum[100][100];
	int j,i;
	printf("enter the number of rows");
	scanf("%d",&row);
	printf("enter the number of column");
	scanf("%d",&column);
	printf("enter the first matrix coulmn wise \n");
	for (j=0;j<row;j++)
	{
        for(i=0;i<column;i++)
        {
            scanf("%d",&matrix1[j][i]);
        }
	}
    printf("enter the second matrix coulmn wise");
	for (j=0;j<row;j++)
    {
        for(i=0;i<column;i++)
        {
            scanf("%d",&matrix2[j][i]);
        }
	}
    for (j=0;j<row;j++)
        {
        for(i=0;i<column;i++)
        {
            sum[j][i]=matrix1[j][i]+matrix2[j][i];
        }
        }
        printf("sum of matrix= \n");
        for (j=0;j<row;j++)
        {
        for(i=0;i<column;i++)
        {
            printf("%d \t",sum[j][i]);
        }
        printf("\n");
        }
}

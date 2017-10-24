#include<stdio.h>
#include<conio.h>
void main()
{
    int matrix1[100][100],matrix2[100][100];
    int column;
	int row;
	int j,i;
	printf("enter the number of rows");
	scanf("%d",&row);
	printf("enter the number of column");
	scanf("%d",&column);
	printf("enter the matrix coulmn wise \n");
	for (j=0;j<row;j++)
	{
        for(i=0;i<column;i++)
        {
            scanf("%d",&matrix1[j][i]);
        }
	}
	for (j=0;j<row;j++)
	{
        for(i=0;i<column;i++)
        {
            matrix2[j][i]=matrix1[j][i];
            printf("%d",matrix2);
        }
	}
}

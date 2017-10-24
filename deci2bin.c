#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int i,j=0;
    int deci1=0,deci=0;
    int b[4]={1,0,1,1};
    printf("binary value is:");
    printf("\n");
    for(i=0;i<4;i++)
    {
        printf("%d",b[i]);
    }
    for(i=0;i<4;i++)

    {
        j=3-i;
        deci1=b[i]*pow(2,j);
        deci=deci+deci1;

    }
    printf("\nafter conversion \n%4d",deci);
}

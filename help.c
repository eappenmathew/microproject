#include<stdio.h>
int f(int a,int b,int i,int c)
{
    if(i>40)
        return b;
    f(b,c,i=i+1,b+c );

}
void main()
{
    printf("%d",f(0,1,3,1));
}

#include<stdio.h>
void tower(int n,char beg,char mid,char end)
{
    if(n==1)
    {
        printf("\n%c-->%c",beg,end);
        return;
    }
    tower(n-1,beg,end,mid);
    printf("\n%c-->%c",beg,end);
    tower(n-1,mid,beg,end);


}
void main ()
{
    int n=2;
    tower(n,'A','B','C');
}

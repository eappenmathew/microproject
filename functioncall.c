#include<stdio.h>
#include<conio.h>
int n=0;
void fun(void);
int main()
{
    fun();
    getch();
    return 0;
}
void fun(void)
{
    if(n<100)
    {
        n++;
        printf("\n%d",n);
        fun();
    }
}

#include<conio.h>
#include<stdio.h>
void pop(int que[],int front,int back,int *newnum)
{
   int elem;
   while(front!=back)//for getting all the elements
    {
        elem=que[back-1];
        if(elem%2==0)//is the no is even or not
            *newnum=*newnum*10+elem;
        back--;

    }
}


void main()
{
    int num=12345,d,front=0,back,len=0;
    int que[10];
    int newnum=0;
    int numcopy=num;
    while(num>0)//to find the no: of digits
    {
        num=num/10;
        len++;
    }
    back=len;
    num=numcopy;
    while(num>0)//to insert the no: in que
    {
        d=num%10;
        num=num/10;
        que[front]=d;
        front++;
    }
    front=0;
    pop(que,front,back,&newnum);
    printf("the no:=%d\n",numcopy);
    printf("the new no:=%d",newnum);
}

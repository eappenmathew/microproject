#include<stdio.h>
#include<ctype.h>
void pop(int stk[],int *j,char ch)
{
    int opr1,opr2,r;
    opr1=stk[*j];
    (*j)--;
    opr2=stk[*j];
    if(ch=='*')
        r=opr2*opr1;
    else if(ch=='/')
        r=opr2/opr1;
    else if(ch=='+')
        r=opr2+opr1;
    else if(ch=='-')
        r=opr2-opr1;
    stk[*j]=r;
}




void main()
{
    int stk[10],ele,r;
    char post[10]="abc*-",ch;
    int i,j=-1;
    for(i=0;post[i]!='\0';i++)
    {
        ch=post[i];
        if(isalpha(ch))
        {
            printf("Enter the value of %c",ch);
            scanf("%d",&ele);
            stk[++j]=ele;
        }
        else
        {
            pop(stk,&j,ch);
        }
    }
    printf("the result=%d",stk[j]);
}

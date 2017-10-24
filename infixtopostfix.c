#include<stdio.h>
#include<ctype.h>
int priorty(char ch)
{
    if(ch=='(')
        return 0;
    else if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='*'||ch=='/')
        return 2;
    else if(ch==')')
        return 3;
}

void main()
{
    char stk[10],temp;
    char post[10],ch,infix[10]="(a+b)",p;
    int i,p=-1,s=0;
    stk[s]='(';
    for(i=0;post[i]!='\0';i++)
    {
        ch=infix[i];
        if(isalpha(ch))
        {
            post[++p]=ch;
        }
        else
        {
            temp=ch;

        }
    }
}

#include<stdio.h>
void display(int stack[],int top)
{
    int p;
    printf("\nStack is:");
    for(p=top;p>=0;p--)
        printf("\n|%5d |",stack[p]);
    printf("\n\n");

}
void indisplay(int stack[],int top)
{
    int p;
    printf("\nstack:");
    for(p=top;p>=0;p--)
        printf("\n|%5c |",stack[p]);
    printf("\n\n");
}
int getval(char ch)
{
    if(ch=='a')
        return 10;
    if(ch=='b')
        return 5;
    if(ch=='c')
        return 2;
    if(ch=='d')
        return 8;
    if(ch=='e')
        return 4;
}
void push(int num,int *stack[],int *top)
{
    *top=(*top)+1;
    stack[*top]=num;
}
void inpush(char ch,int *stack[],int *top)
{
    *top=(*top)+1;
    stack[*top]=ch;
}
int pop(int *stack[],int *top)
{
    return (stack[(*top)--]);
}
char inpop(int *stack[],int *top)
{

    return (stack[(*top)--]);
}
int priority(char ch)
{
    if(ch=='^')
        return 5;
    else if(ch=='*')
        return 4;
    else if(ch=='/')
        return 4;
    else if(ch=='-')
        return 3;
    else if(ch=='+')
        return 3;
    else if(ch==')')
        return 2;
    else
        return 0;
}
void main()
{
    int stack[20],op1,op2,i,p=-1,j,num,top=-1,c;
    char post[20],infix[20]="(a+b)",ch;
    printf("the infix expression is :\n");
    puts(infix);
    getch();
    for(i=0;infix[i]!='\0';i++)
    {
        ch=infix[i];
        printf("\n--------");
        printf("\ncharacter-->%c",ch);
        printf("\n--------");
        if(ch=='a'||ch=='b'||ch=='c'||ch=='d'||ch=='e')
        {
            p=p+1;
            post[p]=ch;
            getch();

        }
        else if(ch=='(')
        {
            inpush(ch,stack,&top);
            getch();

        }
        else if(ch=='^'||ch=='*'||ch=='/'||ch=='+'||ch=='-')
        {
            if(priority(ch)<=priority(stack[top]))
            {
                p=p+1;
                post[p]=inpop(stack,&top);
                inpush(ch,stack,&top);

            }
            else
            {
                inpush(ch,stack,&top);
            }
            getch();
        }
        else if(ch==')')
        {
            while(stack[top]!='(')
            {
                p=p+1;
                post[p]=inpop(stack,&top);            }
            getch();
        }
        indisplay(stack,top);
    }
    while(top>=1)
    {
        p=p+1;
        post[p]=inpop(stack,&top);
    }
    printf("\nPostfix expression is:\n");
    for(j=0;j<=p;j++)
    {
        printf("%c",post[j]);
    }
    post[p+1]='\0';
    inpop(stack,&top); // POP the last (
    getch();
    printf("\n\n\n--Evaluation--\n");

    for(i=0;post[i]!='\0';i++)//postfix evaluation
    {
        ch=post[i];
        printf("\n---------");
        printf("\nch=%c",ch);
        printf("\n---------");
        if(ch=='a'||ch=='b'||ch=='c'||ch=='d'||ch=='e')
        {
            //printf(" =%d",getval(ch));
            push(getval(ch),stack,&top);
        }

        else if(ch=='+')
        {
            op1=pop(stack,&top);
            op2=pop(stack,&top);
            push((op2+op1),stack,&top);
        }
        else if(ch=='-')
        {
            op1=pop(stack,&top);
            op2=pop(stack,&top);
            push((op2-op1),stack,&top);
        }
        else if(ch=='*')
        {
            op1=pop(stack,&top);
            op2=pop(stack,&top);
            push((op2*op1),stack,&top);
        }
        else if(ch=='/')
        {
            op1=pop(stack,&top);
            op2=pop(stack,&top);
            push((op2/op1),stack,&top);
        }
        else if(ch=='%')
        {
            op1=pop(stack,&top);
            op2=pop(stack,&top);
            push((op2%op1),stack,&top);
        }

        display(stack,top);
    }
    printf("\n The answer is : %d",pop(stack,&top));
    getch();
}


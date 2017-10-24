#include<stdio.h>
#include<conio.h>
void push(int stk[],int *top)
{
    int ele;
    if(*top<5)
    {
        printf("\nenter the element");
        scanf("%d",&ele);
        stk[*top]=ele;
    }
}

void pop(int stk[],int *top)
{
    int ele;
    //if(*top>-1)
    //{
        ele=stk[*top];
        printf("\npop=%d",ele);
   // }
}


void main()
{
    int stk[5],top,p,ele,i,pro;
    for(p=4;p>-1;p--)
    {
        printf("%4d\n",stk[p]);
    }
    for(top=-1;top>-5&&top<9;)
    {
        printf("\n1push 2pop=>");
        scanf("%d",&pro);
        if(pro==1)
        {
            if(top<4)
            {
                top++;
                push(stk,&top);
                for(i=4;i>-1;i--)
                {
                    printf("%4d\n",stk[i]);
                }
            }
            else
            {
                printf("stack is full\n");
            }
        }
        else
        {
            if(top>-1)
            {
                pop(stk,&top);
                top--;
            }
            else
                printf("stack is empty\n");
        }
        //printf("The value of the top is %d \n",top);
    }
}

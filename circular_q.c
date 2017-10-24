#include<stdio.h>
#define cap 5
int isfull(int *back,int *front)
{
    if(*back==cap-1)
        return(-1);
    else
        return(0);
}

int del(int que[],int *front,int *back)
{
    int ele;
    if((*back)==-1)
    {
        printf("que is empty\n");
        return(-1);
    }
    else
        ele=que[*front];
    if((*back)==(*front))
    {
        (*front)=-1;
        (*back)=-1;
    }
    else
        (*front)=((*front)+1)%cap;
}

int add(int que[],int *front,int *back)
{
    int ele;
    if(isfull(*back,*front)==-1)
    {
        printf("que is full\n");
        return(0);
    }
    else if(*front==-1)
    {
        (*front)=0;
        (*back)=0;
    }
    else
        (*back)=((*back)+1)%cap;
    printf("enter element");
    scanf("%d",&ele);
    que[*back]=ele;
    return 0;
}


void display(int que[],int *front,int *back)
{
    int i;
    printf("front:%d | back:%d",front,back);
    printf("\n|");
    /*for(i=0;i<5;i++)
    {
        if(front==i)
            printf("front|");
        else
            printf("     |");

    }
    printf("\n|");*/
    for(i=0;i<5;i++)
        printf("%10d|",que[i]);
    printf("\n|");
    /*for(i=0;i<5;i++)
    {
        if(back==i)
            printf("back |");
        else
            printf("     |");

    }*/
}


void main()
{
    int que[5],back=-1,front=-1,ch,ele;
    display(que,&front,&back);
    while(1)
    {
        printf("\n1-add 2-del 3-exit\n");
        scanf("%d",&ch);
        printf("\n");
        if(ch==1)
        {
            add(que,&front,&back);
            display(que,&front,&back);
        }
        else if(ch==2)
        {
            ele=del(que,&front,&back);
            printf("deleted ele=%d\n",ele);
            display(que,&front,&back);
        }
        else if(ch==3)
            break;
        getch();
    }
}

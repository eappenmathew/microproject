#include<stdio.h>
#define cap 5
void insert(int Q[],int *front,int *rear)
{
    int p,ele;
    if(*front==-1)
    {
        *front=0;
        *rear=0;
    }
    else if(*rear==cap-1)
    {
        printf("Q full\n");
        return;
    }
    else
    {
        (*rear)++;
    }
    printf("\nenter the element  ");
    scanf("%d",&ele);
    Q[*rear]=ele;
}

int dele(int Q[],int *front,int *rear)
{
    int p,ele;
    if(*front==-1)
    {
        printf("Q is empty\n");
        return -1;
    }
    ele=Q[*front];
    if(*front==*rear)
    {
        *rear=-1;
        *front=-1;
    }
    else
    {
        //printf("The deleted elem=%d \n",Q[*front]);
        (*front)++;
    }
    return ele;
}
void display(int Q[],int front,int rear)
{
   int p;
   p=front;
    for(p=0;p<cap;p++)
    {
        printf("%d\t",Q[p]);
    }
}
void main()
{
    int Q[5],front=-1,rear=-1,p,ele,i,ch;
    for(;;)
    {

        display(Q,front,rear);
        printf("\n1add 2del 3exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            insert(Q,&front,&rear);
        }
        else if(ch==2)
        {
            ele=dele(Q,&front,&rear);
            printf("ele=%d\n",ele);
        }
        else if(ch==3)
        {
            break;
        }
        printf("f=%d r=%d\n",front,rear);

    }
}
/*if(*front==cap||(*front)==rear+1)

*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
   int num;
   struct node *flink;
   struct node *blink;
}node;

void fdisplay(node *rider)
{
    while(rider!=NULL)
    {
        printf("%5d",rider->num);
        rider=rider->flink;
    }
    printf("\n");
}


void bdisplay(node *rider)
{
    while(rider!=NULL)
    {
        printf("%5d",rider->num);
        rider=rider->blink;
    }
}

void addatbeg(node **startptrptr,node **endptrptr,int ele)
{
    node *nnodeptr=(node*)malloc(sizeof(node));
    nnodeptr->num=ele;
    if(*startptrptr==NULL)
    {
        nnodeptr->flink=nnodeptr->blink=NULL;
        (*startptrptr)=(*endptrptr)=nnodeptr;
    }
    else
    {
        nnodeptr->blink=NULL;
        nnodeptr->flink=*startptrptr;
        (*startptrptr)->blink=nnodeptr;
        *startptrptr=nnodeptr;
    }
}

void addatend(node **startptrptr,node **endptrptr,int ele)
{
    node *nnodeptr=(node*)malloc(sizeof(node));
    nnodeptr->num=ele;
    if(*endptrptr==NULL)
    {
        nnodeptr->flink=nnodeptr->blink=NULL;
        (*startptrptr)=(*endptrptr)=nnodeptr;
    }
    else
    {
        nnodeptr->flink=NULL;
        nnodeptr->blink=*endptrptr;
        (*endptrptr)->flink=nnodeptr;
        *endptrptr=nnodeptr;
    }
}

void addbefore(node *rider,node **startptrptr,int item,int ele)
{
    node *nnodeptr=(node*)malloc(sizeof(node));
    nnodeptr->num=ele;
    nnodeptr->flink=nnodeptr->blink=NULL;
    if(item==(*startptrptr)->num)
    {
        nnodeptr->flink=*startptrptr;
        (*startptrptr)->blink=nnodeptr;
        *startptrptr=nnodeptr;
    }
    else
    {
        while(rider->flink->num!=item)
            rider=rider->flink;
        nnodeptr->blink=rider;
        nnodeptr->flink=rider->flink;
        rider->flink->blink=nnodeptr;
        rider->flink=nnodeptr;

    }
}

void addafter(node *rider,int item,int ele)
{
    node *nnodeptr=(node*)malloc(sizeof(node));
    nnodeptr->num=ele;
    nnodeptr->flink=nnodeptr->blink=NULL;
    {
        while(rider->num!=item)
            rider=rider->flink;
        nnodeptr->blink=rider;
        nnodeptr->flink=rider->flink;
        rider->flink->blink=nnodeptr;
        rider->flink=nnodeptr;

    }
}
void deletebeg(node **startptrptr)
{
    node *temp;
    temp=*startptrptr;
    *startptrptr=(*startptrptr)->flink;
    free(temp);
    (*startptrptr)->blink=NULL;
}


void main()
{
    node *start=NULL,*end=NULL;
    int ele,ch,item;
    //printf("--MENU--\n1.add at begining\n2.add at end\n");
    //scanf("%d",&ch);
    while(1)
    {
        printf("--MENU--\n1.add at begining\n2.add at end\n3.add before\n4.add after\n5.delete@begining\n10.exit\n");
        scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("Enter the element to be add:");
        scanf("%d",&ele);
        addatbeg(&start,&end,ele);
        fdisplay(start);
        bdisplay(end);
        break;
    case 2:
        printf("Enter the element to be add");
        scanf("%d",&ele);
        addatend(&start,&end,ele);
        fdisplay(start);
        bdisplay(end);
        break;
    case 3:
        if(start==NULL)
        {
            printf("list is empty");
            break;
        }
        printf("Enter the element to be add");
        scanf("%d",&ele);
        printf("Enter the element before which to inserted" );
        scanf("%d",&item);
        addbefore(start,&start,item,ele);
        fdisplay(start);
        bdisplay(end);
        break;
    case 4:
        if(start==NULL)
        {
            printf("list is empty");
            break;
        }
        printf("Enter the element to be add");
        scanf("%d",&ele);
        printf("Enter the element before which to inserted" );
        scanf("%d",&item);
        addafter(start,item,ele);
        fdisplay(start);
        bdisplay(end);
        break;
    case 5:
        if(start==NULL)
        {
            printf("list is empty");
            break;
        }
        else
        {
            printf("the first element %d is deleted\n",start->num);
            deletebeg(&start,&end);
            fdisplay(start);
            bdisplay(end);
            break;
        }
    case 10:
        exit(0);
    }
    }

}

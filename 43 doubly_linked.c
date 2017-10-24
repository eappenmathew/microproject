#include<stdio.h>
#include<malloc.h>
struct node
{
    struct node *flink;    //      <----[NUM]------>
    int num;               //      blink      flink
    struct node *blink;
};

void traversestart(struct node *rider)
{
    printf("\nThe list in FORWARD direction:\n");
    while(rider!=NULL)
    {
        printf("%7d",rider->num);
        rider=rider->flink;
    }
}

void traverseend(struct node *rider)
{
    printf("\nThe list in BACKWARD direction:\n");
    while(rider!=NULL)
    {
        printf("%7d",rider->num);
        rider=rider->blink;
    }
}

void addatbeg(struct node **startptrptr,struct node **endptrptr)
{
    struct node *nnodeptr = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value to be added in the begining");
    scanf("%d",&nnodeptr->num);
    nnodeptr->blink=NULL;
    if(*startptrptr!=NULL) // If Elements already exist in the begining
    {
        (nnodeptr)->flink=(*startptrptr);
        (*startptrptr)->blink=nnodeptr;
        (*startptrptr)=nnodeptr;
    }
    else
    {  // Very first element
        (nnodeptr)->flink=NULL;
        (*startptrptr)=nnodeptr;
        (*endptrptr)=nnodeptr;
    }
}
void addatend(struct node **startptrptr,struct node **endptrptr)
{
    struct node *nnodeptr = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value to be added in the end:");
    scanf("%d",&nnodeptr->num);
    nnodeptr->flink=NULL;
    if(*startptrptr!=NULL) // If Elements already exist
    {
        (nnodeptr)->blink=(*endptrptr);
        (*endptrptr)->flink=nnodeptr;
        (*endptrptr)=nnodeptr;
    }
    else
    {  // Very first element
        (nnodeptr)->blink=NULL;
        (*startptrptr)=nnodeptr;
        (*endptrptr)=nnodeptr;
    }
}
void addafter(struct node **startptrptr,struct node **endptrptr)
{
    struct node *nnodeptr = (struct node*)malloc(sizeof(struct node));
    struct node *rider; rider=*startptrptr;
    int ele;
    printf("\nAter Which element should the new ele be added:");
    scanf("%d",&ele);
    printf("\nEnter the value of ele:");
    scanf("%d",&nnodeptr->num);
    while(rider!=NULL)
    {
        if(rider->num==ele && rider!=*endptrptr)
        {

            nnodeptr->flink=rider->flink;
            nnodeptr->blink=rider;
            nnodeptr->flink->blink=nnodeptr;
            nnodeptr->blink->flink=nnodeptr;
            if (nnodeptr->flink==NULL)
                *endptrptr=nnodeptr;
            break;
        }
        rider=rider->flink;
    }

}
void addbefore(struct node **startptrptr,struct node **endptrptr)
{
    struct node *nnodeptr = (struct node*)malloc(sizeof(struct node));
    struct node *rider; rider=*startptrptr;
    int ele;
    printf("\nBefore Which element should the new ele be added:");
    scanf("%d",&ele);
    printf("\nEnter the value of ele:");
    scanf("%d",&nnodeptr->num);
    while(rider!=NULL)
    {
        if(rider->num==ele && rider!=*startptrptr)
        {

            nnodeptr->blink=rider->blink;
            nnodeptr->flink=rider;
            nnodeptr->flink->blink=nnodeptr;
            nnodeptr->blink->flink=nnodeptr;
            if (nnodeptr->blink==NULL)
                *startptrptr=nnodeptr;
        }
        rider=rider->flink;
    }

}
void delatbeg(struct node **startptrptr)
{
    if ((*startptrptr)->flink!=NULL)
    {
       (*startptrptr)->flink->blink=NULL;
       (*startptrptr)=(*startptrptr)->flink;
    }
    else
    {
        *startptrptr=NULL;
    }
}
void delatend(struct node **endptrptr)
{
    if ((*endptrptr)->blink!=NULL)
    {
       (*endptrptr)->blink->flink=NULL;
       (*endptrptr)=(*endptrptr)->blink;
    }
    else
    {
        *endptrptr=NULL;
    }
}

void delafter(struct node **startptrptr,struct node **endptrptr)
{
    struct node *rider; rider=*startptrptr; int ele;
    printf("\nAter Which element should ele be deleted:");
    scanf("%d",&ele);
    while(rider!=NULL)
    {
        if(rider->num==ele && rider->flink->flink!=NULL)
        {
            rider->flink->flink->blink=rider;
            rider->flink=rider->flink->flink;
        }
        else if(rider->num==ele && rider->flink->flink==NULL)
        {
            rider->flink=NULL;
            *endptrptr=rider;
        }

        rider=rider->flink;
    }

}

void delbefore(struct node **startptrptr,struct node **endptrptr)
{
    struct node *rider; rider=*startptrptr; int ele;
    printf("\nBefore Which element should ele be deleted:");
    scanf("%d",&ele);
    while(rider!=NULL)
    {
        if(rider->num==ele && rider->blink->blink!=NULL)
        {
            rider->blink->blink->flink=rider;
            rider->blink=rider->blink->blink;
        }
        else if(rider->num==ele && rider->blink->blink==NULL)
        {
            rider->blink=NULL;
            *startptrptr=rider;
        }
        rider=rider->flink;
    }

}

void main()
{
    struct node *start = NULL,*end = NULL,*nnodeptr; int ch;
    while(1)
    {
        printf("\nMENU \n1. Add at Begin\n2. Add at end\n3.Add After\n4.Add before\n5.Del at begin\n6. Det at end\n7.Del after\n8. Del Before\n");
        printf("Enter the choice:");
        scanf("%d",&ch);
        if (ch==1)
        {
             addatbeg(&start,&end);
             traversestart(start);
             traverseend(end);
        }
        else if (ch==2)
        {
            addatend(&start,&end);
            traversestart(start);
             traverseend(end);
        }
         else if (ch==3)
        {
            addafter(&start,&end);
            traversestart(start);
             traverseend(end);
        }
         else if (ch==4)
        {
            addbefore(&start,&end);
            traversestart(start);
             traverseend(end);
        }
         else if (ch==5)
        {
            delatbeg(&start);
            traversestart(start);
             traverseend(end);
        }
         else if (ch==6)
        {
            delatend(&end);
            traversestart(start);
             traverseend(end);
        }
        else if (ch==7)
        {
            delafter(&start,&end);
            traversestart(start);
             traverseend(end);
        }
        else if (ch==8)
        {
            delbefore(&start,&end);
            traversestart(start);
             traverseend(end);
        }
        else
            printf("Invalid Choice!");

    }




}

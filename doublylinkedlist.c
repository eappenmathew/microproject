#include <stdio.h>
#include <malloc.h>

struct node
{
    int num;
    struct node *flink;
    struct node *blink;
};

void ftraverse(struct node *rider)
{
    printf("\n The list in the forward direction:\n");
    while(rider!=NULL)
    {
        printf("%5d",rider->num);
        rider=rider->flink;
    }
}

void btraverse(struct node *rider)
{
    printf("\n The list in the backward direction:\n");
    while(rider!=NULL)
    {
        printf("%5d",rider->num);
        rider=rider->blink;
    }
}

struct node *findpos(struct node *rider, int value)
{
    while(rider->num!=value)
    {
        rider=rider->flink;
    }

    return rider;

}

struct node *addatbeg(struct node **startptrptr, struct node **endptrptr)
{
    struct node *nnodeptr=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value of the node to be added at the beginning:\n");
    scanf("%d",&nnodeptr->num);

    //for the case of the first node
    if(*startptrptr==NULL)
    {
        nnodeptr->flink=nnodeptr->blink=NULL;
        (*startptrptr)=(*endptrptr)=nnodeptr;
    }
    else //if it is not the first node
    {
        nnodeptr->blink=NULL;
        nnodeptr->flink=*startptrptr;
        (*startptrptr)->blink=nnodeptr;
        *startptrptr=nnodeptr;
    }

}

struct node *addatend(struct node **startptrptr, struct node **endptrptr)
{
    struct node *nnodeptr=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value of the node to be added at the end:\n");
    scanf("%d",&nnodeptr->num);

    //for the case of the first node
    if(*startptrptr==NULL)
    {
        nnodeptr->flink=nnodeptr->blink=NULL;
        (*startptrptr)=(*endptrptr)=nnodeptr;
    }
    else
    {
        nnodeptr->flink=NULL;
        (*endptrptr)->flink=nnodeptr;
        nnodeptr->blink=*endptrptr;
        *endptrptr=nnodeptr;

    }

}

struct node *insertafter(struct node *pos,int val)
{
    struct node *nnodeptr=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value of node to inserted after:");
    scanf("%d",&nnodeptr->num);
    nnodeptr->flink=pos->flink;
    nnodeptr->blink=pos;
    (pos->flink)->blink=nnodeptr;
    pos->flink=nnodeptr;

}

struct node *insertbefore(struct node *pos, int val)
{
    struct node *nnodeptr=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value of node to inserted before:");
    scanf("%d",&nnodeptr->num);
    nnodeptr->blink=pos->blink;
    nnodeptr->flink=pos;
    (pos->blink)->flink=nnodeptr;
    pos->blink=nnodeptr;

}

struct node *deletenode(struct node *pos,struct node **startptrptr, struct node **endptrptr,int value)
{
    if(pos->num==value && pos->flink==NULL)
    {
        free(*endptrptr);
        (pos->flink)->blink=NULL;
    }
    else if(pos->num==value && pos->blink==NULL)
    {
        struct node *temp=*startptrptr;
        *startptrptr=(*startptrptr)->flink;
        (*startptrptr)->blink=NULL;
        free(temp);
    }
    else
    {
        (pos->blink)->flink=pos->flink;
        (pos->flink)->blink=pos->blink;
    }


    /*
    struct node *temp=pos;
    (pos->flink)->blink=pos->blink;
    (pos->blink)->flink=pos->flink;

    if(pos==*startptrptr) //To check if it is the first element
            *startptrptr->blink=NULL;*/
}


void main()
{

    struct node *start=NULL, *end=NULL, *pos1,*pos2,*pos3;
    int val,val1,opt,del;
    //Forward traversing
    ftraverse(start);

    //Backward traversing
    btraverse(end);

    for(;;)
    {

        printf("\nEnter your option:\n1.Add at beginning\n2.Add at end\n3.Insert after\n4.Insert before\n5.Delete\n6.Exit\n");
        scanf("%d",&opt);
        if(opt==1)
        {
            //Add at the beginning
                addatbeg(&start,&end);

            //Forward traversing
                ftraverse(start);

            //Backward traversing
                btraverse(end);
        }
        else if(opt==2)
        {
            //Add at the end
                    addatend(&start,&end);

            //Forward traversing
                    ftraverse(start);

            //Backward traversing
                    btraverse(end);
        }
        else if(opt==3)
        {
             //Insert after a node

            printf("\n Enter the value of node to be inserted after:\n");
            scanf("%d",&val);
            pos1=findpos(start,val);
            insertafter(pos1,val);

            //Forward traversing
            ftraverse(start);

            //Backward traversing
            btraverse(end);

        }
        else if(opt==4)
        {
            //insert before
            printf("\nEnter the value of node to inserted before:\n");
            scanf("%d",&val1);
            pos2=findpos(start,val1);
            insertbefore(pos1,val1);

            //Forward traversing
            ftraverse(start);

            //Backward traversing
            btraverse(end);
        }
        else if(opt==5)
        {
            //delete a node
            printf("\nEnter the value of node to be deleted\n");
            scanf("%d",&del);
            pos3=findpos(start,del);
            deletenode(pos3,&start,&end,del);
            ftraverse(start);
        }
    }


}

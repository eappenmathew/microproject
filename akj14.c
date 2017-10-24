#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


typedef struct node
{
   int num;
   struct node *flink;
   struct node *blink;
}node;



void fdisplay(node *rider)
{
    while(rider!=NULL)//traverse through all the elements
    {
        printf("%5d",rider->num);
        rider=rider->flink;
    }
    printf("\n");
}





void deleteend(node **startptrptr,node **endptrptr)
{
    node *temp;
    temp=*endptrptr;
    *endptrptr=(*endptrptr)->blink;
    free(temp);
    if((*endptrptr)!=NULL)
    {
        (*endptrptr)->flink=NULL;
    }
    if((*endptrptr)==NULL)
    {
        (*startptrptr)=NULL;
    }
}




void deletebeg(node **startptrptr,node **endptrptr)
{
    node *temp;
    temp=*startptrptr;
    *startptrptr=(*startptrptr)->flink;
    free(temp);
    if((*startptrptr)!=NULL)
    {
        (*startptrptr)->blink=NULL;
    }
    if((*startptrptr)==NULL)
    {
        (*endptrptr)=NULL;
    }
}


void addatbeg(node **startptrptr,node **endptrptr,int ele)
{
    node *nnodeptr=(node*)malloc(sizeof(node));
    nnodeptr->num=ele;
    if(*startptrptr==NULL)//checking weather there is any elements
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



void main()
{
    node *start=NULL,*end=NULL;
    int ele,ch,item,i=0,a=0;
    while(1)
    {
        printf("\n--MENU--\n1.add at begining\n2.find mid\n");
        printf("Enter the choise:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the element to be add:");
            scanf("%d",&ele);
            addatbeg(&start,&end,ele);
            fdisplay(start);
            i++;
            break;
        case 2:
            if(start==NULL)
            {
                printf("list is empty");
                break;
            }
            else
            {

                fdisplay(start);
                if(i%2==1)
                    i=i-3;
                else
                    i=i-4;
                while(i>0)
                {
                    printf("\nthe first element %d is deleted\n",start->num);
                    deletebeg(&start,&end);
                    //fdisplay(start);
                    printf("\nthe last element %d is deleted\n",end->num);
                    deleteend(&start,&end);

                    i=i-2;

                }
                fdisplay(start);
            }
        case 3:
            exit(0);
        }

    }
}

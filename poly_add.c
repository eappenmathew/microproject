#include<stdio.h>
struct node
{
    int cof,exp;
    struct node *next;
};



void addpoly(struct node *start1,struct node *start2,struct node **start3,struct node **end3)
{
    struct node *p=start1;
    struct node *q=start2;
    while(p!=NULL&&q!=NULL)
    {
        if(p->exp==q->exp)
        {
            addatend(start3,end3,(p->cof+q->cof),p->exp);
            p=p->next;
            q=q->next;
        }
        else if(p->exp>q->exp)
        {
            addatend(start3,end3,p->cof,p->exp);
            p=p->next;

        }
        else if(p->exp<q->exp)
        {
            addatend(start3,end3,q->cof,q->exp);
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        addatend(start3,end3,p->cof,p->exp);
        p=p->next;
    }
    while(q!=NULL)
    {
        addatend(start3,end3,q->cof,q->exp);
        q=q->next;
    }
}


void dis(struct node *rider)
{
    printf("the eq=");
    while(rider!=NULL)
    {
        printf("%dx^",rider->cof);
        printf("%d+",rider->exp);
        rider=rider->next;
    }
    printf("\b ");
}


void addatend(struct node **startptrptr,struct node **endptrptr,int elem1,int elem2)
{
    struct node *nnode;
    nnode=(struct node*)malloc(sizeof(struct node));
    nnode->cof=elem1;
    nnode->exp=elem2;
    nnode->next=NULL;
    if(*startptrptr==NULL)
        *startptrptr=*endptrptr=nnode;
    else
    {
        (*endptrptr)->next=nnode;
        *endptrptr=nnode;
    }
}

void main()
{
    struct node *start1=NULL,*start2=NULL,*start3=NULL,*end1=NULL,*end2=NULL,*end3=NULL;
    int ch,ele1,ele2,tr,i;
    printf("entet the no: of terms in exp 1:");
    scanf("%d",&tr);
    i=0;
    while(i<tr)
    {
        printf("\nenter the coff:");
        scanf("%d",&ele1);
        printf("\nenter the exp:");
        scanf("%d",&ele2);
        addatend(&start1,&end1,ele1,ele2);
        i++;
        dis(start1);
    }
    printf("\nentet the no: of terms in exp 2:");
    scanf("%d",&tr);
    i=0;
    while(i<tr)
    {
        printf("\nenter the coff:");
        scanf("%d",&ele1);
        printf("\nenter the exp:");
        scanf("%d",&ele2);
        addatend(&start2,&end2,ele1,ele2);
        i++;
        dis(start2);
    }
    addpoly(start1,start2,&start3,&end3);
    printf("\n");
    dis(start3);
}
